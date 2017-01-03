#include "BoxTreeNode.hh"
#include "Setting.hh"

#ifndef	Ct
#define Ct 0.125f
#endif /* Ct */

#ifndef	Ci
#define Ci 1.0f
#endif /* Ci */

BoxTreeNode::BoxTreeNode() : _left(0), _right(0)
{
}

BoxTreeNode::~BoxTreeNode()
{

}

bool	BoxTreeNode::intersect(const Ray& ray,
			       Intersection& hit) const
{
  if (!_bBox.intersect(ray, hit)) {
    return false;
  }
  bool	ret = false;
  if (_left && _right) {
    if (_left->intersect(ray, hit)) {
      if (ray.type == Ray::Shadow) {
	return true;
      }
      ret = true;
    }
    if (_right->intersect(ray, hit)) {
      if (ray.type == Ray::Shadow) {
	return true;
      }
      ret = true;
    }
  }
  else
    {
      for (int32_t i = 0; i < _triangles.size(); ++i) {
	if (_triangles[i]->intersect(ray, hit)) {
	  if (ray.type == Ray::Shadow) {
	    return true;
	  }
	  ret = true;
	}
      }
    }
  return ret;
}

void	BoxTreeNode::construct(const QVector<Triangle*>& triangles,
			       bool first,
			       uint32_t currDepth)
{
  /* Check as it's a SAH tree we already computed the boundinbox in > 1 node */
  if (first) {
    for (int32_t i = 0; i < triangles.size(); ++i) {
      if (triangles[i]->a && triangles[i]->b && triangles[i]->c) {
	_bBox.extend(triangles[i]->a->position);
	_bBox.extend(triangles[i]->b->position);
	_bBox.extend(triangles[i]->c->position);
      }
    }
  }

  if (triangles.size() <= settings->nbTrianglesPerLeaf()) {
    _triangles = triangles;
    return ;
  }
  float			cost		= std::numeric_limits<float>::max();
  float			invBoxArea	= 1.f / _bBox.area();
  float			currCost	= 0.f;
  float			div		= 0.f;
  QVector3D		size		= _bBox.size();
  BoundingBox		cRight, cLeft;
  uint32_t		sizeLeft	= 0;
  uint32_t		sizeRight	= 0;
  int32_t		split		= -1;

  for (int32_t axis = 0; axis < 3; ++axis) {
    float	curDiv		= _bBox.min[axis];
    float	step		= size[axis] / 10.0f;

    for (uint32_t i = 0; i < 10; ++i) {
      uint32_t		nL = 0, nR = 0;
      BoundingBox	b1, b2;
      b1.setToInfinit();
      b2.setToInfinit();
      for (int32_t y = 0; y < triangles.size(); ++y) {
	if (triangles[y]->a && triangles[y]->b && triangles[y]->c) {
	  if (triangles[y]->midPoint(axis) < curDiv) {
	    b1.extend(triangles[y]->a->position);
	    b1.extend(triangles[y]->b->position);
	    b1.extend(triangles[y]->c->position);
	    ++nL;
	  }
	  else {
	    b2.extend(triangles[y]->a->position);
	    b2.extend(triangles[y]->b->position);
	    b2.extend(triangles[y]->c->position);
	    ++nR;
	  }
	}
      }
      float		aL	= b1.area();
      float		aR	= b2.area();
      currCost = Ct + Ci * (aL * nL + aR * nR) * invBoxArea;
      if (currCost < cost) {
	cost		= currCost;
	split		= axis;
	div		= curDiv;
	cLeft		= b1;
	cRight		= b2;
	sizeLeft	= nL;
	sizeRight	= nR;
      }
      curDiv			+= step;
    }
  }
  if (split >= 0) {

    QVector<Triangle*>	vLeft;
    QVector<Triangle*>	vRight;

    vLeft.reserve(sizeLeft);
    vRight.reserve(sizeRight);
    for (int32_t i = 0; i < triangles.size(); ++i) {
      if (triangles[i]->midPoint(split) < div) {
	vLeft << triangles[i];
      }
      else {
	vRight << triangles[i];
      }
    }

    _left		= new BoxTreeNode;
    _left->_bBox	= cLeft;
    _left->construct(vLeft, false, currDepth + 1);

    _right		= new BoxTreeNode;
    _right->_bBox	= cRight;
    _right->construct(vRight, false, currDepth + 1);

  }
}
