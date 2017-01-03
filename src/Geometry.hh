#ifndef __GEOMETRY_HH__
#define __GEOMETRY_HH__

#include "Object.hh"
#include "Ray.hh"
#include "Intersection.hh"

#ifndef UNUSED
#define UNUSED(x) (void)(x);
#endif /* UNUSED */

class Geometry : public Object
{
public:
  Geometry();
  ~Geometry();

  virtual bool	intersect(const Ray& ray,
			  Intersection& hit) const;
};

#endif /* __GEOMETRY_HH__ */
