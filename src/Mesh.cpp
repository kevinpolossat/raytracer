#include "Mesh.hh"

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
}

void				Mesh::setMatrix(const QMatrix4x4& m)
{
  _objectToWorld = m;
  _worldToObject = m.inverted();
}

bool				Mesh::intersect(const Ray& ray,
						Intersection& hit) const
{
  if (!_root) {
    return false;
  }
  Ray                   objectRay(_worldToObject.map(ray.origin),
				  _worldToObject.map(QVector4D(ray.direction, 0.0f)).toVector3D(),
				  ray.type);
  bool			ret = _root->intersect(objectRay, hit);
  if (ret) {
    hit.position        = _objectToWorld.map(hit.position);
    hit.normal          = _objectToWorld.map(QVector4D(hit.normal, 0.0f)).toVector3D().normalized();
    hit.u               = _objectToWorld.map(QVector4D(hit.u, 0.0f)).toVector3D().normalized();
    hit.v               = _objectToWorld.map(QVector4D(hit.v, 0.0f)).toVector3D().normalized();
    hit.material	= _material;
  }
  return ret;
}

void				Mesh::setRoot(const BoxTreeNode* node)
{
  _root = node;
}

const BoxTreeNode*		Mesh::root() const
{
  return _root;
}

void				Mesh::setName(const QString& name)
{
  _name = name;
}

const QString&			Mesh::name() const
{
  return _name;
}

