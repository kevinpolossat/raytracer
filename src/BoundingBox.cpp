#include "BoundingBox.hh"
#include "Setting.hh"

BoundingBox::BoundingBox()
{
  setToInfinit();
}

BoundingBox::~BoundingBox()
{

}

bool		BoundingBox::intersect(const Ray& ray,
				       const Intersection& hit) const
{
  QVector3D	invRay	= QVector3D(1.0f / ray.direction.x(), 1.0f / ray.direction.y(), 1.0f / ray.direction.z());
  QVector3D	t1	= (min - ray.origin) * invRay;
  QVector3D	t2	= (max - ray.origin) * invRay;
  
  float tMin		= std::max(std::max(std::min(t1.x(), t2.x()), std::min(t1.y(), t2.y())), std::min(t1.z(), t2.z()));
  float	tMax		= std::min(std::min(std::max(t1.x(), t2.x()), std::max(t1.y(), t2.y())), std::max(t1.z(), t2.z()));
  if (tMin <= tMax) {
    if ((tMin <= settings->Epsilon() && tMax <= settings->Epsilon()) || tMin >= hit.hitDist - settings->Epsilon()) {
      return false;
    }
    return true;
  }
  return false;
}

void		BoundingBox::setToInfinit()
{
  max = QVector3D(1 - std::numeric_limits<float>::max(),
		  1 - std::numeric_limits<float>::max(),
		  1 - std::numeric_limits<float>::max());
  min = QVector3D(std::numeric_limits<float>::max(),
		  std::numeric_limits<float>::max(),
		  std::numeric_limits<float>::max());
}

float		BoundingBox::area()
{
  QVector3D	t = max - min;
  return 2.f * t.x() * t.z() + 2.f * t.x() * t.y() + 2.f * t.y() * t.z();
}

void		BoundingBox::extend(const QVector3D& p)
{
  min.setX(std::min(min.x(), p.x()));
  min.setY(std::min(min.y(), p.y()));
  min.setZ(std::min(min.z(), p.z()));
  max.setX(std::max(max.x(), p.x()));
  max.setY(std::max(max.y(), p.y()));
  max.setZ(std::max(max.z(), p.z()));
}

QVector3D	BoundingBox::size() const
{
  return max - min;
}
