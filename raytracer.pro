#-------------------------------------------------
#
# Project created by QtCreator 2016-06-08T00:21:38
#
#-------------------------------------------------

        QT       += core gui

        QMAKE_CXXFLAGS += -std=c++11
        QMAKE_CXXFLAGS += -W -Werror -Wextra
        
        greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

        TARGET = raytracer
        TEMPLATE = app


        SOURCES += ./src/main.cpp
        SOURCES += ./src/MainWindow.cpp
        SOURCES += ./src/Setting.cpp
        SOURCES += ./src/Camera.cpp
        SOURCES += ./src/Color.cpp
        SOURCES += ./src/Renderer.cpp
        SOURCES += ./src/Noise.cpp
        SOURCES += ./src/Random.cpp
        SOURCES += ./src/Ray.cpp
        SOURCES += ./src/Intersection.cpp
        SOURCES += ./src/Vertex.cpp
        SOURCES += ./src/Triangle.cpp
        SOURCES += ./src/BoundingBox.cpp
        SOURCES += ./src/Geometry.cpp
        SOURCES += ./src/Object.cpp
        SOURCES += ./src/Material.cpp
        SOURCES += ./src/BoxTreeNode.cpp
        SOURCES += ./src/Integrator.cpp
        SOURCES += ./src/PathTracing.cpp
        SOURCES += ./src/Scene.cpp
        SOURCES += ./src/AssimpLoader.cpp
        SOURCES += ./src/SceneGenerator.cpp
        SOURCES += ./src/Mesh.cpp
        SOURCES += ./src/ComposedMesh.cpp
        SOURCES += ./src/Sphere.cpp
        SOURCES += ./src/Plane.cpp
        SOURCES += ./src/Light.cpp
        SOURCES += ./src/PointLight.cpp
        SOURCES += ./src/DirectionalLight.cpp
        SOURCES += ./src/AreaLight.cpp
        SOURCES += ./src/LambertianMaterial.cpp
        SOURCES += ./src/DielectricMaterial.cpp
        SOURCES += ./src/AshikhminMaterial.cpp
        
        HEADERS += ./src/MainWindow.h
        HEADERS += ./src/Setting.hh 
        HEADERS += ./src/Camera.hh
        HEADERS += ./src/Color.h
        HEADERS += ./src/Renderer.hh
        HEADERS += ./src/Noise.hh
        HEADERS += ./src/Random.hh
        HEADERS += ./src/Ray.hh
        HEADERS += ./src/Intersection.hh
        HEADERS += ./src/Vertex.hh
        HEADERS += ./src/Triangle.hh
        HEADERS += ./src/BoundingBox.hh
        HEADERS += ./src/Geometry.hh
        HEADERS += ./src/Object.hh
        HEADERS += ./src/Material.hh
        HEADERS += ./src/BoxTreeNode.hh
        HEADERS += ./src/Integrator.hh
        HEADERS += ./src/PathTracing.hh
        HEADERS += ./src/Scene.hh
        HEADERS += ./src/AssimpLoader.hh
        HEADERS += ./src/SceneGenerator.hh
        HEADERS += ./src/Mesh.hh
        HEADERS += ./src/ComposedMesh.hh
        HEADERS += ./src/Sphere.hh
        HEADERS += ./src/Plane.hh
        HEADERS += ./src/Light.hh
        HEADERS += ./src/PointLight.hh
        HEADERS += ./src/DirectionalLight.hh
        HEADERS += ./src/AreaLight.hh
        HEADERS += ./src/LambertianMaterial.hh
        HEADERS += ./src/DielectricMaterial.hh
        HEADERS += ./src/AshikhminMaterial.hh
        
        FORMS    += mainwindow.ui

        LIBS += -lassimp

        OBJECTS_DIR = ./src/object
