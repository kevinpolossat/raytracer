#ifndef __LIGHT_HH__
#define __LIGHT_HH__

#include "Object.hh"
#include "Color.h"

#ifndef		UNUSED
#define		UNUSED(x) (void)(x);
#endif		/* UNUSED */

class Light : public Object
{
public:
  Light();
  ~Light();

  void			setIntensity(float intensity);
  float			intensity() const;

  void			setBaseColor(const Color& baseColor);
  const Color&		baseColor() const;

  virtual float		illuminate(const QVector3D& pos,
				   Color& col,
				   Ray& lightRay,
				   Intersection& lightHit) const;
protected:
  float		_intensity;
  Color		_baseColor;
};

#endif /* __LIGHT_HH__ */
