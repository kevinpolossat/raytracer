#include "Setting.hh"
#include "Plane.hh"

Plane::Plane()
{

}

Plane::~Plane()
{

}

void			Plane::setPosition(const QVector3D& position)
{
  _position = position;
}

const QVector3D&	Plane::position() const
{
  return _position;
}

void			Plane::setNormal(const QVector3D& normal)
{
  _normal = normal;
}

const QVector3D&	Plane::normal() const
{
  return _normal;
}

bool			Plane::intersect(const Ray& ray,
					 Intersection& hit) const
{
  float		den	= QVector3D::dotProduct(ray.direction, _normal);
  if (den == 0.f) {
    return false;
  }
  float		d	= QVector3D::dotProduct(_normal, _position);
  float		t	= (d - QVector3D::dotProduct(ray.origin, _normal)) / den;
  if (t < settings->Epsilon() || t > hit.hitDist) {
    return false;
  }
  if (ray.type == Ray::Shadow) {
    return true;
  }
  hit.hitDist		= t;
  hit.position		= ray.origin + ray.direction * t;
  hit.normal		= _normal;
  /* Optimisation global yaxis ? */
  hit.u = QVector3D::crossProduct(QVector3D(0.0f, 1.0f, 0.0f), hit.normal);
  if (hit.u.length() < settings->Epsilon()) {
    hit.u = QVector3D(0.0f, 1.0f, 0.0f);
  }
  else {
    hit.u.normalize();
  }
  hit.v = QVector3D::crossProduct(hit.normal, hit.u);
  hit.material		= _material;
  return true;
}
