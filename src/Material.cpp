#include "Material.hh"

Material::Material()
{

}

Material::~Material()
{

}

void	Material::reflect(const QVector3D& d,
			  const QVector3D& n,
			  QVector3D& r)
{
  r = d - 2.0f * QVector3D::dotProduct(d, n) * n;
}

void	Material::computeReflectance(Color& col,
				     const Ray& out,
				     const QVector3D& in,
				     const Intersection& hit) const
{
  UNUSED(col);
  UNUSED(in);
  UNUSED(out);
  UNUSED(hit);
}

bool	Material::sampleRay(const Ray& ray,
			    const Intersection& hit,
			    Ray& sampled,
			    Color& col) const
{
  UNUSED(ray);
  UNUSED(hit);
  UNUSED(sampled);
  UNUSED(col);
  return false;
}
