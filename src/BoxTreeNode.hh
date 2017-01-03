#ifndef __BOXTREENODE_HH__
#define __BOXTREENODE_HH__

#include <QVector>
#include <cstdint>

#include "Triangle.hh"
#include "BoundingBox.hh"

class BoxTreeNode
{
public:
  BoxTreeNode();
  ~BoxTreeNode();

  bool	intersect(const Ray& ray,
		  Intersection& hit) const;
  void	construct(const QVector<Triangle*>& triangles,
		  bool first,
		  uint32_t currentDepth);
private:
  QVector<Triangle*>		_triangles;
  BoundingBox			_bBox;
  BoxTreeNode*			_left;
  BoxTreeNode*			_right;
  uint32_t			_currentDepth;
  int				_axis;
};

#endif /* __BOXTREENODE_HH__ */
