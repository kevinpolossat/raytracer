#include <QtMath>
#include "Triangle.hh"
#include "Setting.hh"
#include "Random.hh"

Triangle::Triangle(const Vertex* a,
		   const Vertex* b,
		   const Vertex* c)
{
  if (a && b && c) {
    this->a	= a;
    this->b	= b;
    this->c	= c;
    this->mid	= (a->position + b->position + c->position) / 3.0f;
  }
}

Triangle::~Triangle()
{
}


bool			Triangle::intersect(const Ray& ray,
					    Intersection& hit) const
{
  if (!a || !b || !c)
    return false;

  QVector3D		ab		= b->position - a->position;
  QVector3D		ac		= c->position - a->position;
  QVector3D		mDir		= -ray.direction;
  QVector3D		abXac		= QVector3D::crossProduct(ab, ac);
  QVector3D		AP		= ray.origin - a->position;
  float			invDetM		= 1 / QVector3D::dotProduct(mDir, abXac);
  float                 alpha		= QVector3D::dotProduct(mDir,QVector3D::crossProduct(AP, ac)) * invDetM;
  if (alpha < 0.f || alpha > 1.f) {
    return false;
  }
  float                 beta            = QVector3D::dotProduct(mDir,QVector3D::crossProduct(ab, AP)) * invDetM;
  if (beta < 0.f || alpha + beta > 1.f) {
    return false;
  }
  float                 t               = QVector3D::dotProduct(AP, abXac) * invDetM;

  if (t > settings->Epsilon() && t < hit.hitDist)
    {
      if (ray.type == Ray::Shadow) {
	return true;
      }
      hit.normal = alpha * b->normal + beta * c->normal + (1.0f - alpha - beta) * a->normal;
      hit.u = alpha * b->u + beta * c->u + (1.0f - alpha - beta) * a->u;
      hit.v = alpha * b->v + beta * c->v + (1.0f - alpha - beta) * a->v;
      hit.hitDist = t;
      hit.position = ray.origin + hit.hitDist * ray.direction;
      return true;
    }
  return false;
}

const QVector3D&	Triangle::midPoint() const
{
  return mid;
}

float			Triangle::midPoint(int32_t axis) const
{
  return mid[axis];
}

QVector3D		Triangle::sample() const
{
  if (!a || !b || !c) {
    return QVector3D(0.0f, 0.0f, 0.0f);
  }
  
  float			u	= qSqrt(Random::uniformRand());
  float			v	= Random::uniformRand();
  float			alpha	= u * v;
  float			beta	= 1.0f - u; 

  return a->position + alpha * (b->position - a->position) + beta * (c->position - a->position);
}
