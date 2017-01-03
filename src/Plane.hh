#ifndef __PLANE_HH__
#define __PLANE_HH__

#include "Geometry.hh"

class Plane : public Geometry
{
public:
  Plane();
  ~Plane();

  void			setPosition(const QVector3D& position);
  const QVector3D&	position() const;

  void			setNormal(const QVector3D& normal);
  const QVector3D&	normal() const;
  
  bool			intersect(const Ray& ray,
				  Intersection& hit) const;
private:
  QVector3D	_position;
  QVector3D	_normal;
};

#endif /* __PLANE_HH__ */
