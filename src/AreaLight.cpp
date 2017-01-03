#include "AreaLight.hh"

AreaLight::AreaLight()
{
}

AreaLight::~AreaLight()
{
}

float			AreaLight::illuminate(const QVector3D& pos,
					      Color& col,
					      Ray& lightRay,
					      Intersection& lightHit) const
{
  (void)pos;
  (void)col;
  (void)lightRay;
  (void)lightHit;
  return 0;
}
