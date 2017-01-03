#ifndef __SCENEGENERATOR_HH__
#define __SCENEGENERATOR_HH__

#include "Scene.hh"
#include "Camera.hh"

class SceneGenerator
{
public:
  SceneGenerator();
  ~SceneGenerator();
  static void	generate(Scene* scene,
			 Camera* camera);
private:
};

#endif /* __SCENEGENERATOR_HH__ */
