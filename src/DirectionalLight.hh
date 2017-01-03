#ifndef __DIRECTIONALLIGHT_HH__
#define __DIRECTIONALLIGHT_HH__

#include "Light.hh"

class DirectionalLight : public Light
{
public:
  DirectionalLight();
  ~DirectionalLight();

  void			setDirection(const QVector3D& direction);
  const QVector3D&	direction() const;
  float			illuminate(const QVector3D& pos,
				   Color& col,
				   Ray& lightRay,
				   Intersection& lightHit) const;
private:
  QVector3D	_direction;
};

#endif /* __DIRECTIONALLIGHT_HH__ */
