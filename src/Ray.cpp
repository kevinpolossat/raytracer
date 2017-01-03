#include "Ray.hh"
#include "Setting.hh"

Ray::Ray()
{
  n = settings->envRefractionIndex();
  depth = 0;
}

Ray::Ray(const QVector3D& origin,
	 const QVector3D& direction,
	 Type type) : origin(origin), direction(direction), type(type)
{

}

Ray::~Ray()
{

}

