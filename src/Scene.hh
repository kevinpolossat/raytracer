#ifndef __SCENE_HH__
#define __SCENE_HH__

#include <QList>

#include "Object.hh"
#include "Light.hh"

class Scene
{
public:
  Scene();
  ~Scene();

  void			addObject(Object* object);
  void			addLight(Light* light);

  const QList<Light*>&	lights() const;
  bool			intersectWorld(const Ray& ray,
				       Intersection& hit) const;
private:
  QList<Object*>	_objects;
  QList<Light*>		_lights;
};

#endif /* __SCENE_HH__ */
