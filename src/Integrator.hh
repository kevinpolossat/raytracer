#ifndef	__INTEGRATOR_HH__
#define __INTEGRATOR_HH__

#include "Scene.hh"
#include "Ray.hh"
#include "Color.h"

#ifndef		UNUSED
#define		UNUSED(x) (void)(x);
#endif		 /* UNUSED */

class Integrator
{
public:
  Integrator(const Scene* scene = 0);
  ~Integrator();

  virtual void	integrate(const Ray& ray,
			  Color& shade) const;
protected:
  const Scene*	_scene;
};

#endif /* __INTEGRATOR_HH__ */
