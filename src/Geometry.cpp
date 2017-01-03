#include "Geometry.hh"

Geometry::Geometry()
{
}

Geometry::~Geometry()
{
}

bool	Geometry::intersect(const Ray& ray,
			    Intersection& hit) const
{
  UNUSED(ray);
  UNUSED(hit);
  return false;
}

