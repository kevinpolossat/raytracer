#include "ComposedMesh.hh"

ComposedMesh::ComposedMesh()
{
}

ComposedMesh::~ComposedMesh()
{
}

bool			ComposedMesh::intersect(const Ray& ray,
						Intersection& hit) const
{
  if (!_meshes) {
    return false;
  }
  
  Ray			objectRay(_worldToObject.map(ray.origin),
				  _worldToObject.map(QVector4D(ray.direction, 0.0f)).toVector3D(),
				  ray.type);
  bool			ret = false;
  for (Mesh* mesh : *_meshes) {
    if (mesh->intersect(objectRay, hit)) {
      if (ray.type == Ray::Shadow) {
	return true;
      }
      ret = true;
    }
  }
  if (ret) {
    hit.position	= _objectToWorld.map(hit.position);
    hit.normal		= _objectToWorld.map(QVector4D(hit.normal, 0.0f)).toVector3D().normalized();
    hit.u		= _objectToWorld.map(QVector4D(hit.u, 0.0f)).toVector3D().normalized();
    hit.v		= _objectToWorld.map(QVector4D(hit.v, 0.0f)).toVector3D().normalized();
    hit.material	= _material;
  }
  return ret;
}

void			ComposedMesh::setMatrix(const QMatrix4x4& m)
{
  _objectToWorld	= m;
  _worldToObject	= m.inverted();
}

void			ComposedMesh::setMeshes(const QList<Mesh*>* meshes)
{
  _meshes = meshes;
}

const QList<Mesh*>*	ComposedMesh::meshes() const
{
  return _meshes;
}
