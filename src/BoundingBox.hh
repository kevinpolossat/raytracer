#ifndef __BOUNDINGBOX_HH__
#define __BOUNDINGBOX_HH__

#include <QVector3D>

#include "Ray.hh"
#include "Intersection.hh"

class BoundingBox
{
public:
  BoundingBox();
  ~BoundingBox();

  bool		intersect(const Ray& ray,
			  const Intersection& hit) const;
  void		setToInfinit();
  void		extend(const QVector3D& t);
  QVector3D	size() const;
  float		area();
  
  QVector3D	min;
  QVector3D	max;
};

#endif /* __BOUNDINGBOX_HH__ */
