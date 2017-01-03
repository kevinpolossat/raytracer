#ifndef __COMPOSEDMESH_HH__
#define __COMPOSEDMESH_HH__

#include "Object.hh"
#include "Mesh.hh"

class ComposedMesh : public Object
{
public:
  ComposedMesh();
  ~ComposedMesh();

  bool			intersect(const Ray& ray,
				  Intersection& hit) const;
  
  void			setMatrix(const QMatrix4x4& m);

  void			setMeshes(const QList<Mesh*>* meshes);
  const QList<Mesh*>*	meshes() const;

private:
  QMatrix4x4		_objectToWorld;
  QMatrix4x4		_worldToObject;
  const QList<Mesh*>*	_meshes;
};

#endif /* __COMPOSEDMESH_HH__ */
