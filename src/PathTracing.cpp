#include "PathTracing.hh"
#include "Setting.hh"
#include "Light.hh"

PathTracing::PathTracing(const Scene* scene)
{
  _scene = scene;
}

PathTracing::~PathTracing()
{
}

void	PathTracing::integrate(const Ray& ray,
			       Color& shade) const
{
  if (!_scene) {
    return ;
  }
  Intersection	hit;
  if (_scene->intersectWorld(ray, hit) && hit.material) {
   
    if (QVector3D::dotProduct(ray.direction, hit.normal) > 0) {
      hit.normal *= -1;
      hit.u *= -1;
      hit.v *= -1;
    }
    Color	dirLight = Color::BLACK;
    for (Light* light : _scene->lights()) {
      Ray		lightRay;
      Color		baseColor;
      Intersection	lightHit;
      float		bright		= light->illuminate(hit.position, baseColor, lightRay, lightHit);
      float		cosTheta	= QVector3D::dotProduct(lightRay.direction, hit.normal);
      if (cosTheta > settings->Epsilon() && bright > settings->Epsilon() && !_scene->intersectWorld(lightRay, lightHit)) {
    	Color		materialColor = Color::BLACK;
    	hit.material->computeReflectance(materialColor, ray, lightRay.direction, hit);
    	materialColor.Scale(cosTheta * bright);
    	materialColor.Multiply(baseColor);
    	dirLight.Add(materialColor);
      }
    }
    shade.Add(dirLight);
    // if (ray.depth <= settings->Depth()) {
    //   Ray		sampled;
    //   Color		color = Color::BLACK;
    //   if (hit.material->sampleRay(ray, hit, sampled, color)) {
    // 	Color		indirLight = Color::BLACK;
    // 	this->integrate(sampled, indirLight);
    // 	indirLight.Multiply(color);
    // 	shade.Add(indirLight);
    //   }
    // }
  }
  else {
    shade = Color(0.8f, 0.9f, 1.0f);
  }
}
