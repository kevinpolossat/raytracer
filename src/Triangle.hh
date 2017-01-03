#ifndef __TRIANGLE_HH__
#define __TRIANGLE_HH__

#include "Geometry.hh"
#include "Vertex.hh"

class Triangle : public Geometry
{
public:
  Triangle(const Vertex *a = 0,
	   const Vertex *b = 0,
	   const Vertex *c = 0);
  ~Triangle();

  bool			intersect(const Ray& ray,
				  Intersection& hit) const;
  float			midPoint(int32_t axis) const;
  const QVector3D&	midPoint() const;
  QVector3D		sample() const;
  
  const Vertex*	a;
  const Vertex*	b;
  const Vertex*	c;
  QVector3D	mid;
};

#endif /*__TRIANGLE_HH__ */
