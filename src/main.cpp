#include <QApplication>
#include <QLabel>
#include <QImage>
#include <QString>

#include "Setting.hh"
#include "AssimpLoader.hh"
#include "MainWindow.h"
#include "Setting.hh"
#include "Renderer.hh"
#include "SceneGenerator.hh"
#include "PathTracing.hh"

int main(int argc,
	 char *argv[])
{
  QApplication	a(argc, argv);
  QLabel	label;
  // QImage	image(800, 600, QImage::Format_RGB32);
  //  QImage	image(300, 300, QImage::Format_RGB32);
  MainWindow	w;
  Renderer	renderer;
  renderer.setImageSize(800, 600);
  //  AssimpLoader	loader;
  SceneGenerator gen;

  Scene*	scene		= new Scene;
  Camera*	camera		= new Camera;
  PathTracing*	integrator	= new PathTracing(scene);
  gen.generate(scene, camera);

  renderer.setCamera(camera);
  renderer.setScene(scene);
  renderer.setIntegrator(integrator);

  // if (argc == 2 && argv[1]) {
  //   QString file(argv[1]);
  //   loader.loadFile(file);
  // }
  
  renderer.render();
  label.setPixmap(QPixmap::fromImage(renderer.image()));
  label.show();
  
  return a.exec();
}
