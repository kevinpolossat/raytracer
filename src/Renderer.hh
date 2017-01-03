#ifndef __RENDERER_HH__
#define __RENDERER_HH__

#include <QImage>
#include <QMutex>

#include <cstdint>
#include <thread>

#include "Scene.hh"
#include "Camera.hh"
#include "Integrator.hh"

class Renderer
{
public:
  Renderer();
  ~Renderer();

  void			setCamera(Camera* camera);
  const Camera*		camera() const;

  void			setScene(Scene* scene);
  const Scene*		scene() const;

  void			setIntegrator(Integrator* integrator = 0);
  const Integrator*	integrator() const;

  void			setImageSize(uint32_t x,
				     uint32_t y);
  QSize			imageSize() const;

  const QImage&		image() const;
  
  void			render();
  void			renderSection();

private:
  Camera*		_camera;
  Scene*		_scene;
  Integrator*		_integrator;
  QImage		_image;
  QList<std::thread*>	_threads;
  QList<QRect>		_jobs;
  QMutex		_jobsMutex;
};

#endif /* __RENDERER_HH__ */
