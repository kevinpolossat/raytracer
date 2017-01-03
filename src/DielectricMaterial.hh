#ifndef __DIELECTRICMATERIAL_HH__
#define __DIELECTRICMATERIAL_HH__

#include "Material.hh"

class DielectricMaterial : public Material
{
public:
  DielectricMaterial();
  ~DielectricMaterial();

  static float		Fresnel(const QVector3D& d,
				const QVector3D& N,
				QVector3D& t,
				float ni,
				float nt);

  void			setRefraction(float n);
  float			n() const;

  void			setRoughness(float rough);
  float			roughness() const;

  void			setAbsorption(float absorption);
  float			absorption() const;

  void			setColorAbsorption(const QVector3D& col);
  const QVector3D&	colorAbsorption() const;

  static void  		Walter(const QVector3D& i,
			       const QVector3D& o,
			       const QVector3D& n);
  void			computeReflectance(Color& col,
					   const Ray& in,
					   const QVector3D& out,
					   const Intersection& hit) const;
  
  bool			sampleRay() const;
private:
  float		_n;
  float		_roughness;
  float		_absorption;
  QVector3D	_colorAbsorption;

};

#endif /* __DIELECTRICMATERIAL_HH__ */
