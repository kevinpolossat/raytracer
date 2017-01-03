#include "Vertex.hh"
#include "Setting.hh"

Vertex::Vertex()
{

}

Vertex::Vertex(const QVector3D& pos,
	       const QVector3D& n)
{
  position = pos;
  normal = n;
  this->getTangent();
}

Vertex::~Vertex()
{

}

void	Vertex::getTangent()
{
  /* Optimisation global yaxis ? */
  u = QVector3D::crossProduct(QVector3D(0.0f, 1.0f, 0.0f), normal);
  if (u.length() < settings->Epsilon()) {
    u = QVector3D(0.0f, 1.0f, 0.0f);
  }
  else {
    u.normalize();
  }
  v = QVector3D::crossProduct(normal, u);
}
