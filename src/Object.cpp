#include "Object.hh"

Object::Object()
{
  _material = 0;
}

Object::~Object()
{
}

bool		Object::intersect(const Ray& ray,
				  Intersection& hit) const
{
  (void)ray;
  (void)hit;
  return false;
}

const Material*	Object::material() const
{
  return _material;
}

void		Object::setMaterial(const Material* m)
{
  _material = m;
}
