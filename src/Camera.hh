#ifndef __CAMERA_HH__
#define __CAMERA_HH__

#include <QMatrix4x4>

#include "Ray.hh"

class Camera
{
public:
  Camera();
  ~Camera();

  void	setFocalPlane(float focalPlane);
  float getFocalPlane() const;

  void	setAperture(float Aperture);
  float getAperture() const;

  void set(float vFOV,
	   float aspectRatio);
  void lookAt(const QVector3D& position,
	      const QVector3D& target,
	      const QVector3D& up);
  void primaryRay(float x,
		  float y,
		  Ray& ray) const;
private:
  float		_hFOV;
  float		_vFOV;
  float		_screenHeight;
  float		_screenWidth;
  float		_aspectRatio;
  float		_aperture;
  float		_focalPlane;
  QVector3D	_screenTopLeft;
  QMatrix4x4	_cameraToWorld;
};

#endif /* __CAMERA_HH__ */
