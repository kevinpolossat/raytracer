#include "DirectionalLight.hh"

DirectionalLight::DirectionalLight()
{

}

DirectionalLight::~DirectionalLight()
{

}

void			DirectionalLight::setDirection(const QVector3D& direction)
{
  _direction = direction;
  _direction.normalize();
}

const QVector3D&       	DirectionalLight::direction() const
{
  return _direction;
}

float			DirectionalLight::illuminate(const QVector3D& pos,
						     Color& col,
						     Ray& lightRay,
						     Intersection& lightHit) const
{
  lightRay.direction		= -_direction;
  lightRay.direction.normalize();
  col				= _baseColor;
  lightRay.origin      		= pos;
  lightHit.hitDist		= 1e6;
  lightRay.type			= Ray::Shadow;
  return _intensity;
}
