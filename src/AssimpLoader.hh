#ifndef __ASSIMPLOADER_HH__
#define __ASSIMPLOADER_HH__

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <QMatrix4x4>
#include <QString>

#include "Mesh.hh"

class AssimpLoader
{
public:
  AssimpLoader();
  ~AssimpLoader();

  void			loadFile(const QString& fileName,
				 QList<Mesh*>* objects);
  static void		toQMatrix4x4(const aiMatrix4x4& m,
				     QMatrix4x4& qm);
private:
  void			_loadAiNodes(aiNode* assimpNode,
				     QList<Mesh*>* objects,
				     const QMatrix4x4& parent = QMatrix4x4()) const;
  Assimp::Importer	_importer;
  const aiScene*	_assimpScene;
};

#endif /* __ASSIMPLOADER_HH__ */
