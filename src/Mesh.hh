#ifndef __MESH_HH__
#define __MESH_HH__

#include <QMatrix4x4>

#include "BoxTreeNode.hh"

#include "Object.hh"

class Mesh : public Object
{
public:
  Mesh();
  ~Mesh();

  void				setRoot(const BoxTreeNode* node);
  const BoxTreeNode*	        root() const;

  void				setMatrix(const QMatrix4x4& m);
  bool				intersect(const Ray& ray,
					  Intersection& hit) const;
  void				setName(const QString& name);
  const QString&		name() const;
private:
  QString			_name;
  QMatrix4x4			_objectToWorld;
  QMatrix4x4			_worldToObject;
  const BoxTreeNode*   		_root;
};

#endif /* __MESH_HH__ */
