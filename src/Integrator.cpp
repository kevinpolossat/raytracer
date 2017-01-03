#include "Integrator.hh"

Integrator::Integrator(const Scene* scene) : _scene(scene)
{
}

Integrator::~Integrator()
{
}

void	Integrator::integrate(const Ray& ray,
			      Color& shade) const
{
  UNUSED(ray);
  UNUSED(shade);
}
