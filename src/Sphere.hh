#ifndef	__SPHERE_HH__
#define	__SPHERE_HH__

#include "Geometry.hh"

class Sphere : public Geometry
{
public:
  Sphere();
  ~Sphere();

  void			setCenter(const QVector3D& center);
  const QVector3D&	center() const;

  void			setRadius(float radius);
  float			radius() const;
  bool			intersect(const Ray& ray,
				  Intersection& hit) const;
private:
  QVector3D	_center;
  float		_radius;
};

#endif /* __SPHERE_HH__ */
