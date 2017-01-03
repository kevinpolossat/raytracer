#ifndef __AREALIGHT_HH__
#define __AREALIGHT_HH__

#include "Light.hh"

class AreaLight : public Light
{
public:
  AreaLight();
  ~AreaLight();

  float		        illuminate(const QVector3D& pos,
				   Color& col,
				   Ray& lightRay,
				   Intersection& lightHit) const;
private:
  
};

#endif /* __AREALIGHT_HH__ */
