#ifndef __ASHIKHMINMATERIAL_HH__
#define __ASHIKHMINMATERIAL_HH__

#include "Material.hh"

#ifndef invPi
#define invPi 0.318309f
#endif /* invPi */

class AshikhminMaterial : public Material
{
public:
  AshikhminMaterial();
  ~AshikhminMaterial();

  void			setNu(float nu);
  float			nu() const;
  
  void			setNv(float nv);
  float			nv() const;
  
  void			setRd(float Rd);
  float			Rd() const;
  
  void			setRs(float Rs);
  float			Rs() const;

  void			setSColor(const Color& SColor);
  const Color&		SColor() const;

  void			setDColor(const Color& DColor);
  const Color&		DColor() const;

  static void	        AshikhminBRDF(const QVector3D& k1,
				      const QVector3D& k2,
				      const QVector3D& normal,
				      const QVector3D& u,
				      const QVector3D& v,
				      float nu,
				      float nv,
				      float Rs,
				      float Rd,
				      float& Ps,
				      float& Pd);
  void			computeReflectance(Color& col,
					   const Ray& out,
					   const QVector3D& in,
					   const Intersection& hit) const;
  bool			sampleRay(const Ray& ray,
				  const Intersection& hit,
				  Ray& sampled,
				  Color& col) const;
private:
  float		_nu;
  float		_nv;
  float		_Rd;
  float		_Rs;
  Color		_SColor;
  Color		_DColor;
};

#endif /*__ASHIKHMINMATERIAL_HH__ */
