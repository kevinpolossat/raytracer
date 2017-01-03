#include <QtMath>

#include "LambertianMaterial.hh"
#include "Random.hh"

#ifndef invPi
#define invPi 0.318309f
#endif /* invPi */

LambertianMaterial::LambertianMaterial()
{
  _albedo	= Color::BLACK;
  _roughness	= 0.f;
}

LambertianMaterial::~LambertianMaterial()
{

}

void		LambertianMaterial::setAlbedo(const Color& albedo)
{
  _albedo = albedo;
}

const Color&	LambertianMaterial::albedo() const
{
  return _albedo;
}


void		LambertianMaterial::setRoughness(float roughness)
{
  _roughness = roughness;
}

float		LambertianMaterial::roughness() const
{
  return _roughness;
}

float		LambertianMaterial::OrenNayar(const QVector3D& in,
					      const QVector3D& out,
					      const QVector3D& n,
					      float roughness)
{
  float		r2	= roughness * roughness;
  float		A	= 1.f - 0.5 * (r2 / (r2 + 0.57));
  float		B	= 0.45 * (r2 / (r2 + 0.09));
  float		NdotL	= QVector3D::dotProduct(in, n);;
  float		NdotV	= QVector3D::dotProduct(out, n);
  float		thetaI	= qAcos(NdotL);
  float		thetaR	= qAcos(NdotV);
  float		alpha	= std::max(thetaI, thetaR);
  float		beta	= std::min(thetaI, thetaR);
  float		gamma	= QVector3D::dotProduct(out - (n * NdotV), in - (n * NdotL));

  return A + (B * std::max(0.f, gamma) * qSin(alpha) * qTan(beta));
}

void		LambertianMaterial::computeReflectance(Color& col,
						       const Ray& out,
						       const QVector3D& in,
						       const Intersection& hit) const
{
  col.Scale(_albedo, invPi);
  if (_roughness > 0.f) {
    float		microGeo	= OrenNayar(in, -out.direction, hit.normal, _roughness);
    col.Scale(microGeo);
  }
}

bool		LambertianMaterial::sampleRay(const Ray& ray,
					      const Intersection& hit,
					      Ray& sampled,
					      Color& col) const
{
  float		s	= Random::uniformRand();
  float		t	= Random::uniformRand();
  float		u	= 2.0f * M_PI * s;
  float		v	= qSqrt(1.0f - t);

  sampled.direction    	= hit.normal * qSqrt(t) + hit.u * v * qCos(u) + hit.v * v * qSin(u);
  sampled.origin	= hit.position;
  sampled.type		= Ray::Diffused;
  sampled.depth		= ray.depth + 1;
  sampled.direction.normalize();
  col			= _albedo;
  return true;
}
