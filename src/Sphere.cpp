#include <QtMath>

#include "Sphere.hh"
#include "Setting.hh"

Sphere::Sphere()
{

}

Sphere::~Sphere()
{

}

void			Sphere::setCenter(const QVector3D& center)
{
  _center = center;
}

const QVector3D&	Sphere::center() const
{
  return _center;
}

void			Sphere::setRadius(float radius)
{
  _radius = radius;
}

float			Sphere::radius() const
{
  return _radius;
}

bool			Sphere::intersect(const Ray& ray,
					  Intersection& hit) const
{
  float		t	= -QVector3D::dotProduct((ray.origin - _center), ray.direction);
  QVector3D	q	= ray.origin + t * ray.direction; 
  float		r2	= _radius * _radius;
  float		l2	= (q - _center).lengthSquared();
  if (l2 > r2) {
    return false;
  }
  float		a	= qSqrt(r2 - l2);
  float		dist	= (t - a < 0 ? t + a : t - a);

  if (dist < settings->Epsilon() || dist > hit.hitDist) {
    return false;
  }
  if (ray.type == Ray::Shadow) {
    return true;
  }
  hit.hitDist		= dist;
  hit.position		= ray.origin + ray.direction * dist;
  hit.normal		= hit.position - _center;
  hit.normal		/= _radius;
  
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
