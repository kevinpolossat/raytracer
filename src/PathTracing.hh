#ifndef	__PATHTRACING_HH__
#define	__PATHTRACING_HH__

#include "Integrator.hh"

class PathTracing : public Integrator
{
public:
  PathTracing(const Scene* scene = 0);
  ~PathTracing();

  void	integrate(const Ray& ray,
		  Color& shade) const;
private:
};

#endif /* __PATHTRACING_HH__ */
