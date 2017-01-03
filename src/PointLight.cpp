#include "PointLight.hh"

PointLight::PointLight()
{

}

PointLight::~PointLight()
{

}

void			PointLight::setPosition(const QVector3D& position)
{
  _position = position;
}

const QVector3D&       	PointLight::position() const
{
  return _position;
}

float			PointLight::illuminate(const QVector3D& pos,
					       Color& col,
					       Ray& lightRay,
					       Intersection& lightHit) const
{
  lightRay.direction	= _position - pos;
  col			= _baseColor;
  lightRay.origin	= pos;
  float		bright	= _intensity / lightRay.direction.lengthSquared(); 
  lightRay.direction.normalize();
  lightHit.hitDist	= _position.distanceToPoint(pos);
  lightRay.type		= Ray::Shadow;
  return bright;
}
