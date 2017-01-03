#ifndef __POINTLIGHT_HH__
#define __POINTLIGHT_HH__

#include "Light.hh"

class PointLight : public Light
{
public:
  PointLight();
  ~PointLight();

  void			setPosition(const QVector3D& position);
  const QVector3D&	position() const;
  float			illuminate(const QVector3D& pos,
				   Color& col,
				   Ray& lightRay,
				   Intersection& lightHit) const;
private:
  QVector3D	_position;
};

#endif /* __POINTLIGHT_HH__ */
