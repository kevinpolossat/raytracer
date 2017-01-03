#include <QVector3D>
#include <QVector>

#include "AssimpLoader.hh"

#include "Triangle.hh"

AssimpLoader::AssimpLoader()
{

}

AssimpLoader::~AssimpLoader()
{

}

void	AssimpLoader::loadFile(const QString& fileName,
			       QList<Mesh*>* object)
{
  if (!object) {
    return ;
  }
  _assimpScene = _importer.ReadFile(fileName.toStdString(),
				    aiProcess_Triangulate
				    | aiProcess_GenSmoothNormals
				    | aiProcess_FixInfacingNormals);
  if (!_assimpScene || !_assimpScene->HasMeshes()) {
    return ;
  }
  _loadAiNodes(_assimpScene->mRootNode, object);
}

void	AssimpLoader::_loadAiNodes(aiNode* assimpNode,
				   QList<Mesh*>* object,
				   const QMatrix4x4& p) const
{

  if (!assimpNode) {
    return ;
  }
  QMatrix4x4		m;
  toQMatrix4x4(assimpNode->mTransformation, m);
  m *= p;
  for (uint32_t i = 0; i < assimpNode->mNumMeshes; ++i) {
    aiMesh*		assimpMesh	= _assimpScene->mMeshes[assimpNode->mMeshes[i]];
    QVector<Vertex*>	vertices;
    for (uint32_t y = 0; y < assimpMesh->mNumVertices; ++y) {
      Vertex*	v	= new Vertex;
      v->position      	= QVector3D(assimpMesh->mVertices[y].x,
				    assimpMesh->mVertices[y].y,
				    assimpMesh->mVertices[y].z);
      if (assimpMesh->mNormals) {
	v->normal	= QVector3D(assimpMesh->mNormals[y].x,
				    assimpMesh->mNormals[y].y,
				    assimpMesh->mNormals[y].z);
      }
      v->getTangent();
      vertices << v;
    }
    QVector<Triangle*>	triangles;
    for (uint32_t y = 0; y < assimpMesh->mNumFaces; ++y) {
      if (assimpMesh->mFaces[y].mNumIndices == 3) {
	Triangle*	t = new Triangle(vertices[assimpMesh->mFaces[y].mIndices[0]],
					 vertices[assimpMesh->mFaces[y].mIndices[1]],
					 vertices[assimpMesh->mFaces[y].mIndices[2]]);
	triangles << t;
      }
    }
    Mesh*		mesh	= new Mesh;
    BoxTreeNode*	root	= new BoxTreeNode;
    root->construct(triangles, true, 0);
    mesh->setMatrix(m);
    mesh->setName(assimpNode->mName.C_Str());
    mesh->setRoot(root);
    *object << mesh;
  }
  for (uint32_t i = 0; i < assimpNode->mNumChildren; ++i) {
    _loadAiNodes(assimpNode->mChildren[i], object, m);
  }
}

void	AssimpLoader::toQMatrix4x4(const aiMatrix4x4& m,
				   QMatrix4x4& qM)
{
  qM.setColumn(0, QVector4D(m.a1, m.b1, m.c1, m.d1));
  qM.setColumn(1, QVector4D(m.a2, m.b2, m.c2, m.d2));
  qM.setColumn(2, QVector4D(m.a3, m.b3, m.c3, m.d3));
  qM.setColumn(3, QVector4D(m.a4, m.b4, m.c4, m.d4));
}
