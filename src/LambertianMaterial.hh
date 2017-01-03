#ifndef __LAMBERTIANMATERIAL_HH__
#define __LAMBERTIANMATERIAL_HH__

#include "Material.hh"

class LambertianMaterial : public Material
{
public:
  LambertianMaterial();
  ~LambertianMaterial();

  void		setAlbedo(const Color& albedo);
  const Color&	albedo() const;

  void		setRoughness(float roughness);
  float		roughness() const;
  
  static float	OrenNayar(const QVector3D& in,
			  const QVector3D& out,
			  const QVector3D& n,
			  float roughness);
  void		computeReflectance(Color& col,
				   const Ray& out,
				   const QVector3D& in,
				   const Intersection& hit) const;
  bool		sampleRay(const Ray& ray,
			  const Intersection& hit,
			  Ray& sampled,
			  Color& col) const;
private:
  Color		_albedo;
  float		_roughness; /* 0.0 - 0.5 */
};

#endif /* __LAMBERTIANMATERIAL_HH__ */
