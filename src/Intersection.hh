#ifndef __INTERSECTION_HH__
#define __INTERSECTION_HH__

#include <QVector3D>

class Material;

class Intersection
{
public:
  Intersection();
  ~Intersection();

  float			hitDist;
  QVector3D		position;
  QVector3D		normal;
  QVector3D		u;
  QVector3D		v;
  const Material*	material;
};

#endif /* __INTERSECTION_HH__ */
