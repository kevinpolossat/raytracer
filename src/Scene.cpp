#include "Scene.hh"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void			Scene::addObject(Object* object)
{
  _objects << object;
}

void			Scene::addLight(Light* light)
{
  _lights << light;
}

const QList<Light*>&	Scene::lights() const
{
  return _lights;
}

bool			Scene::intersectWorld(const Ray& ray,
					      Intersection& hit) const
{
  bool	inter = false;
  for (Object* obj : _objects) {
    if (obj->intersect(ray, hit)) {
      if (ray.type == Ray::Shadow) {
	return true;
      }
      inter = true;
    }
  }
  return inter;
}
