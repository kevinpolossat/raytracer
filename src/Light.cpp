#include "Light.hh"

Light::Light()
{
  _intensity	= 1.f;
  _baseColor	= Color::WHITE;
}

Light::~Light()
{

}

void			Light::setIntensity(float intensity)
{
  _intensity = intensity;
}

float			Light::intensity() const
{
  return _intensity;
}

void			Light::setBaseColor(const Color& baseColor)
{
  _baseColor = baseColor;
}

const Color&		Light::baseColor() const
{
  return _baseColor;
}

float			Light::illuminate(const QVector3D& pos,
					  Color& col,
					  Ray& lightRay,
					  Intersection& lightHit) const
{
  UNUSED(pos);
  UNUSED(col);
  UNUSED(lightRay);
  UNUSED(lightHit);
  return 0.f;
}
