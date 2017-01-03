#include "SceneGenerator.hh"
#include "AssimpLoader.hh"

#include "ComposedMesh.hh"
#include "BoxTreeNode.hh"
#include "Sphere.hh"
#include "Plane.hh"

#include "DirectionalLight.hh"

#include "LambertianMaterial.hh"
#include "AshikhminMaterial.hh"

SceneGenerator::SceneGenerator()
{

}

SceneGenerator::~SceneGenerator()
{

}

void	SceneGenerator::generate(Scene* scene,
				 Camera* camera)
{
  if (!scene || !camera) {
    return ;
  }

  LambertianMaterial*	lamber		= new LambertianMaterial;
  lamber->setAlbedo(Color(1.0, 1.0, 1.0));
  lamber->setRoughness(0.0);
  AshikhminMaterial*		ashi = new AshikhminMaterial;
  ashi->setNu(1000.0f);
  ashi->setNv(1000.0f);
  ashi->setRd(0.8f);
  ashi->setRs(0.2f);
  ashi->setDColor(Color(1.0f, 0.1f, 0.1f));
  ashi->setSColor(Color(1.0f, 1.0f, 1.0f));
  
  QList<Mesh*>*		object	= new QList<Mesh*>;
  AssimpLoader		loader;

  loader.loadFile("./Mesh/dragon.ply", object);
  ComposedMesh*		mesh	= new ComposedMesh;
  mesh->setMeshes(object);
  mesh->setMaterial(lamber);
  QMatrix4x4		mtx;
  mtx.setToIdentity();
  mtx.translate(0.0f, 0.0f, -0.1f * 3.0f);
  mesh->setMatrix(mtx);
  scene->addObject(mesh);
  // Sphere*		sphere		= new Sphere;
  // sphere->setCenter(QVector3D(0.0, 0.5, 2.0));
  // sphere->setRadius(0.5);
  // sphere->setMaterial(ashi);
  // scene->addObject(sphere);

  // Plane*		ground		= new Plane;
  // ground->setNormal(QVector3D(0.0f, 1.0f, 0.0f));
  // ground->setPosition(QVector3D(0.0f, 0.0f, 0.0f));
  // ground->setMaterial(lamber);
  // scene->addObject(ground);
  
  DirectionalLight*	light		= new DirectionalLight;
  // light->setDirection(QVector3D(2.f, -3.f, -2.f));
  light->setDirection(QVector3D(2.0f, -3.0f, -2.0f));
  light->setIntensity(1.f);
  light->setBaseColor(Color(1.0f, 1.0f, 0.9f));
  scene->addLight(light);

  /* Optimisation yaxis global ? */
  // camera->lookAt(QVector3D(-0.75f,0.25f,5.0f), QVector3D(0.0f,0.5f,0.0f), QVector3D(0.0f, 1.0f, 0.0f));

  camera->lookAt(QVector3D(-0.5f, 0.25f, -0.2f), QVector3D(0.0f, 0.15f, -0.15f), QVector3D(0.0f, 1.f, 0.0f));
  
  camera->set(40.f, 1.33f);
  camera->setAperture(0.2);
  camera->setFocalPlane(1.0);
}
