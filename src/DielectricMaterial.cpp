#include <QtMath>

#include "DielectricMaterial.hh"
#include "Setting.hh"

DielectricMaterial::DielectricMaterial()
{

}

DielectricMaterial::~DielectricMaterial()
{

}

void			DielectricMaterial::setRefraction(float n)
{
  _n = n;
}

float			DielectricMaterial::n() const
{
  return _n;
}

void			DielectricMaterial::setRoughness(float rough)
{
  _roughness = rough;
}

float			DielectricMaterial::roughness() const
{
  return _roughness;
}

void			DielectricMaterial::setAbsorption(float absorption)
{
  _absorption = absorption;
}

float			DielectricMaterial::absorption() const
{
  return _absorption;
}

void			DielectricMaterial::setColorAbsorption(const QVector3D& col)
{
  _colorAbsorption = col;
}

const QVector3D&	DielectricMaterial::colorAbsorption() const
{
  return _colorAbsorption;
}

void			DielectricMaterial::Walter(const QVector3D& i,
						   const QVector3D& o,
						   const QVector3D& n)
{
  // float			G;
  // /*Shadow Masking 0 <= G() <= 1*/
  // float			D;
  // /*Micro-facet distribution function 0 <= D <= +inf*/
  // QVector3D		m;
  // /* G(i,O,m) == 0 if i.m*i.n <= 0 || o.m*o.n <= 0*/
  (void)n;
  QVector3D		h	= i + o;
  QVector3D		hn	= h.normalized();
  (void)hn;
  /*fs(i,o,n)*/
}

float			DielectricMaterial::Fresnel(const QVector3D& d,
						    const QVector3D& N,
						    QVector3D& t,
						    float ni,
						    float nt)
{
  QVector3D		n	= N;
  float			NdotD	= QVector3D::dotProduct(d, n);

  if (NdotD > 0) {
    n		*= -1;
    NdotD	*= -1;
  }
  QVector3D	z	= ni / nt * (d - NdotD * n);
  float		l2	= z.lengthSquared();
  if (l2 >= 1) {
    return 1.0f;
  }

  t			= z - qSqrt(1 - l2) * n;
  t.normalize();
  float		NdotT	= QVector3D::dotProduct(n, t);

  float		niNdotT	= ni * NdotT;
  float		ntNdotD	= nt * NdotD;
  float		rpar	= (ntNdotD - niNdotT) / (ntNdotD + niNdotT);

  float		niNdotD	= ni * NdotD;
  float		ntNdotT	= nt * NdotT;
  float		rperp	= (niNdotD - ntNdotT) / (niNdotD + ntNdotT);
  return 0.5 * (rpar * rpar + rperp * rperp);
}

void			DielectricMaterial::computeReflectance(Color& col,
							       const Ray& out,
							       const QVector3D& in,
							       const Intersection& hit) const
{
  /* BSDF change ?*/
  col			= Color::BLACK;
  if (_roughness > 0.0f) {
    QVector3D		t;
    float		ni	= settings->envRefractionIndex(), nt = _n;
    if (out.n != settings->envRefractionIndex()) {
      qSwap(ni, nt);
    }
    float		F	= Fresnel(out.direction, hit.normal, t, ni, nt);
    QVector3D		r;
    Material::reflect(out.direction, hit.normal, r);
    col			= Color::WHITE;
    (void)F;
    (void)in;
  }
}

bool			DielectricMaterial::sampleRay() const
{
  return false;
}
