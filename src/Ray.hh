#ifndef __RAY_HH__
#define __RAY_HH__

#include <QVector3D>

class Ray
{
public:
  enum Type
    {
      Primary,
      Shadow,
      Reflected,
      Transmitted,
      Diffused
    };
  Ray();
  Ray(const QVector3D& origin,
      const QVector3D& position,
      Type type);
  ~Ray();

  QVector3D	origin;
  QVector3D	direction;
  uint32_t	depth;
  float		n;
  Type		type;
};

#endif /* __RAY_HH__ */
