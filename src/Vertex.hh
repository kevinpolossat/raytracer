#ifndef __VERTEX_HH__
#define __VERTEX_HH__

#include <QVector3D>
#include <cstdint>

class Vertex
{
public:
  Vertex();
  Vertex(const QVector3D& position,
	 const QVector3D& normal);
  ~Vertex();

  void		getTangent();
  
  QVector3D	position;
  QVector3D	normal;
  QVector3D	u;
  QVector3D	v;
};

#endif /* __VERTEX_HH__ */
