#include <QtMath>
#include "Camera.hh"
#include "Random.hh"

Camera::Camera()
{

}

Camera::~Camera()
{

}

void	Camera::setFocalPlane(float focalPlane)
{
  _focalPlane = focalPlane;
}

float	Camera::getFocalPlane() const
{
  return _focalPlane;
}

void	Camera::setAperture(float aperture)
{
  _aperture = aperture;
}

float	Camera::getAperture() const
{
  return _aperture;
}

#include <iostream>
void	Camera::set(float vFOV,
		    float aspectRatio)
{
  _vFOV		= qDegreesToRadians(vFOV);
  _aspectRatio	= aspectRatio;
  _screenHeight = qTan(_vFOV * 0.5);
  _hFOV		= 2.0 * qAtan(aspectRatio * _screenHeight);
  _screenHeight	*= 2;
  _screenWidth	= _screenHeight * _aspectRatio;
  _screenTopLeft = (-_cameraToWorld.column(2)
		    - _screenWidth * 0.5 * _cameraToWorld.column(0)
		    + _screenHeight * 0.5 * _cameraToWorld.column(1)
		    + _cameraToWorld.column(3)).toVector3D();
}

void	Camera::lookAt(const QVector3D& pos,
		       const QVector3D& target,
		       const QVector3D& up)
{
  QVector3D	d = pos;
  QVector3D	c = d - target;
  c.normalize();
  QVector3D	a = QVector3D::crossProduct(up, c);
  a.normalize();
  QVector3D	b = QVector3D::crossProduct(c, a);

  _cameraToWorld.setColumn(0, a);
  _cameraToWorld.setColumn(1, b);
  _cameraToWorld.setColumn(2, c);
  _cameraToWorld.setColumn(3, d);
}



void	Camera::primaryRay(float x,
			   float y,
			   Ray& ray) const
{
  // float	s	= Random::uniformRand();
  // float	t	= Random::uniformRand();
  // float theta	= 2.f * M_PI * s;
  // float sqrtTA	= _aperture * qSqrt(t);

  // ray.origin		= (_cameraToWorld.column(3)
  // 			   + sqrtTA * cos(theta) * _cameraToWorld.column(0)
  // 			   + sqrtTA * qSin(theta) * _cameraToWorld.column(1)).toVector3D();
  // QVector3D direction	= (_screenTopLeft
  // 			   + x * _screenWidth * _cameraToWorld.column(0)
  // 			   + y * _screenHeight * _cameraToWorld.column(1)
  // 			   - _cameraToWorld.column(3)).toVector3D();
  // QVector3D focus	= _cameraToWorld.column(3).toVector3D() + direction * _focalPlane;;

  // ray.direction		= focus - ray.origin;
  // ray.direction.normalize();
  ray.type	= Ray::Primary;
  ray.origin = _cameraToWorld.column(3).toVector3D();
  ray.direction = (_screenTopLeft +
		   x * _screenWidth * _cameraToWorld.column(0)
		   + y * _screenHeight * _cameraToWorld.column(1)
		   - _cameraToWorld.column(3)).toVector3D();
  ray.direction.normalize();
  // std::cout << ray.direction.x() << " " << ray.direction.y() << " " <<ray.direction.z() << std::endl;
}
