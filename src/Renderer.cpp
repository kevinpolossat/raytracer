#include <QRgb>
#include <QtMath>

#include "Renderer.hh"
#include "Random.hh"
#include "Setting.hh"

Renderer::Renderer()
{
  _scene = 0;
  _integrator = 0;
  _camera = 0;
}

Renderer::~Renderer()
{
  
}

void			Renderer::setImageSize(uint32_t x,
					       uint32_t y)
{
  _image		= QImage(x, y, QImage::Format_RGB32);
}

QSize			Renderer::imageSize() const
{
  return _image.size();
}

const QImage&		Renderer::image() const
{
  return _image;
}

void			Renderer::setScene(Scene* scene)
{
  _scene = scene;
}

const Scene*		Renderer::scene() const
{
  return _scene;
}

void			Renderer::setCamera(Camera* camera)
{
  _camera = camera;
}

const Camera*		Renderer::camera() const
{
  return _camera;
}

void			Renderer::setIntegrator(Integrator* integrator)
{
  _integrator = integrator;
}

const Integrator*	Renderer::integrator() const
{
  return _integrator;
}

#include <iostream>
void			Renderer::render()
{
  if (!_scene || !_integrator || !_camera) {
    return ;
  }

  int32_t	j	= qSqrt(settings->nbJob());
  QSize		s	= _image.size() / j;

  s.setWidth(qMax(s.width(), 1));
  s.setHeight(qMax(s.height(), 1));

  QList<QRect>	jobs;
  for (int32_t y = 0; y < _image.height(); y += s.height()) {
    for (int32_t x = 0; x < _image.width(); x += s.width()) {
      QRect		t(QPoint(x, y), s);
      t.setRight(qMin(t.right(), _image.width() - 1));
      t.setBottom(qMin(t.bottom(), _image.height() - 1));
      jobs << t;
    }
  }

  for (uint32_t n = 0; n < settings->Sample(); ++n) {
    _jobs = jobs;
    for (uint32_t i = 0; i < settings->nbThread(); ++i) {
      _threads << (new std::thread(&Renderer::renderSection, this));
    }
    for (std::thread* t : _threads) {
      t->join();
      delete t;
    }
    _threads.clear();
  }
}

void			Renderer::renderSection()
{
  if (!_scene || !_integrator || !_camera) {
    return ;
  }
  while (1) {
    
    _jobsMutex.lock();
    if (_jobs.isEmpty()) {
      _jobsMutex.unlock();
      return ;
    }
    QRect	section	= _jobs.takeFirst();
    _jobsMutex.unlock();
    
    Ray			ray;
    for (int32_t y = section.topLeft().y(); y <= section.bottomRight().y(); ++y) {
      for (int32_t x = section.topLeft().x(); x <= section.bottomRight().x(); ++x) {
	Color			col = Color::BLACK;
	/* optimisation == replace image.width by a mult */
	_camera->primaryRay((x + Random::uniformRand()) / _image.width(),
			    -((y + Random::uniformRand()) / _image.height()),
			    ray);
	_integrator->integrate(ray, col);
	_image.setPixel(x, y, col.ToInt());
      }
    }
  }
}
