#ifndef __OBJECT_HH__
#define __OBJECT_HH__

#include "Ray.hh"
#include "Intersection.hh"
#include "Material.hh"

class Object
{
public:
  Object();
  ~Object();

  void			setMaterial(const Material* m);
  const Material*	material() const;
  virtual bool		intersect(const Ray& ray,
				  Intersection& hit) const;
protected:
  const Material*	_material;
};

#endif /* __OBJECT_HH__ */
