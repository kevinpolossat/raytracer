#ifndef __MATERIAL_HH__
#define __MATERIAL_HH__

#include "Ray.hh"
#include "Color.h"
#include "Intersection.hh"


#ifndef UNUSED
#define UNUSED(x) (void)(x);
#endif /* UNUSED */

class Material
{
public:
  Material();
  ~Material();

  static void	reflect(const QVector3D& d,
			const QVector3D& n,
			QVector3D& r);
  virtual void	computeReflectance(Color& col,
				   const Ray& out,
				   const QVector3D& in,
				   const Intersection& hit) const;
  virtual bool	sampleRay(const Ray& ray,
			  const Intersection& hit,
			  Ray& sampled,
			  Color& col) const;
protected:
  
};

#endif /* __MATERIAL_HH__ */
