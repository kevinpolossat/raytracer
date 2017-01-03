#include <QtMath>

#include "AshikhminMaterial.hh"
#include "Random.hh"
#include "Setting.hh"

AshikhminMaterial::AshikhminMaterial()
{
}

AshikhminMaterial::~AshikhminMaterial()
{
}

void			AshikhminMaterial::setNu(float nu)
{
  _nu = nu;
}

float			AshikhminMaterial::nu() const
{
  return _nu;
}

void			AshikhminMaterial::setNv(float nv)
{
  _nv = nv;
}

float			AshikhminMaterial::nv() const
{
  return _nv;
}

void			AshikhminMaterial::setRd(float Rd)
{
  _Rd = Rd;
}

float			AshikhminMaterial::Rd() const
{
  return _Rd;
}

void			AshikhminMaterial::setRs(float Rs)
{
  _Rs = Rs;
}

float			AshikhminMaterial::Rs() const
{
  return _Rs;
}

void			AshikhminMaterial::setSColor(const Color& SColor)
{
  _SColor = SColor;
}

const Color&		AshikhminMaterial::SColor() const
{
  return _SColor;
}

void			AshikhminMaterial::setDColor(const Color& DColor)
{
  _DColor = DColor;
}

const Color&		AshikhminMaterial::DColor() const
{
  return _DColor;
}

void			AshikhminMaterial::AshikhminBRDF(const QVector3D& k1,
							 const QVector3D& k2,
							 const QVector3D& normal,
							 const QVector3D& u,
							 const QVector3D& v,
							 float nu,
							 float nv,
							 float Rs,
							 float Rd,
							 float& Ps,
							 float& Pd)
{
  QVector3D		n	= normal;
  QVector3D		h	= (k1 + k2).normalized();
  float			NdotK1	= QVector3D::dotProduct(n, k1);
  if (NdotK1 < 0) {
    NdotK1	*= -1.0f;
    n		*= -1.0f;
  }
  float			NdotK2	= QVector3D::dotProduct(n, k2);
  float			nh	= QVector3D::dotProduct(n, h);
  float			hu	= QVector3D::dotProduct(h, u);
  float			hv	= QVector3D::dotProduct(h, v);
  float			kh	= QVector3D::dotProduct(k2, h);
  float			Ps1	= qSqrt((nu + 1) * (nv + 1)) * (0.125f * invPi);
  float			Ps2	= qPow(nh, (nu * hu * hu + nv * hv * hv) / (1.0f - nh * nh)) / (kh * qMax(NdotK1, NdotK2));
  float			Fkh	= Rs + (1.0f - Rs) * qPow((1.0f - kh), 5.0f);
  Ps	= Ps1 * Ps2 * Fkh;
  float			Pd1	= (28.0f * Rd) * (invPi * 0.043478f);
  float			Pd2	= 1.0f - (qPow(1.0f - NdotK1 * 0.5f, 5.0f));
  float			Pd3	= 1.0f - (qPow(1.0f - NdotK2 * 0.5f, 5.0f));
  Pd	= (Pd1 * (1.0f - Rs)) * Pd2 * Pd3;
}

void			AshikhminMaterial::computeReflectance(Color& col,
							      const Ray& out,
							      const QVector3D& in,
							      const Intersection& hit) const
{
  float			Ps, Pd;
  
  AshikhminMaterial::AshikhminBRDF(in, -out.direction, hit.normal, hit.u, hit.v, _nu, _nv, _Rs, _Rd, Ps, Pd);
  col	= Color::BLACK;
  col.AddScaled(_SColor, Ps);
  col.AddScaled(_DColor, Pd);
}

bool			AshikhminMaterial::sampleRay(const Ray& ray,
						     const Intersection& hit,
						     Ray& sampled,
						     Color& col) const
{
  float			decisionRand	= Random::uniformRand();
  if (decisionRand < _Rs) {
    float		e1		= Random::uniformRand();
    float		e2		= Random::uniformRand();
    float		Phi		= qAtan(qSqrt((_nu + 1.0f) / (_nv + 1.0f)) * qTan(M_PI * e1 * 0.5f));
    if (e1 > 0.75f) {
      Phi				= 2.0 * M_PI - Phi;
    }
    else if (e1 > 0.5f) {
      Phi				= M_PI + Phi;
    }
    else if (e1 > 0.25f) {
      Phi				= M_PI - Phi;
    }
    float		cosPhi		= qCos(Phi);
    float		sinPhi		= qSin(Phi);
    float		cosTheta	= qPow(1.0f - e2, (1.0f / (_nu * cosPhi * cosPhi + _nv * sinPhi * sinPhi + 1.0f)));
    float		sinTheta	= qSin(qAcos(cosTheta));
    QVector3D		h		= (hit.normal * cosTheta + hit.u * cosPhi * sinTheta + hit.v * sinPhi * sinTheta).normalized();
    QVector3D		k1		= -ray.direction;
    QVector3D		k2		= -k1 + 2.0f * QVector3D::dotProduct(k1, h) * h;
    if (QVector3D::dotProduct(k2, hit.normal) < settings->Epsilon()) {
      col				= Color::BLACK;
      return false;
    }
    k2.normalize();
    col					= _SColor;
    sampled.direction			= k2;
    sampled.origin			= hit.position;
    sampled.depth			= ray.depth + 1;
    sampled.type			= Ray::Reflected;
  }
  else {
    float		s		= Random::uniformRand();
    float		t		= Random::uniformRand();
    float		u		= 2.0f * M_PI * s;
    float		v		= qSqrt(1.0f - t);

    sampled.direction			= hit.normal * qSqrt(t) + hit.u * v * qCos(u) + hit.v * v * qSin(u);
    sampled.origin			= hit.position;
    sampled.type			= Ray::Diffused;
    sampled.depth			= ray.depth + 1;
    sampled.direction.normalize();
    col					= _DColor;
  }
  return true;
}
