cmake_minimum_required(VERSION 3.2)
project(PyramidProject)
#message(WARNING ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -mwindows")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES src/main.cpp)

set(EXECUTABLE_NAME Pyramid_Project)

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES}
src/nsGameObject/GameObject.cpp
src/nsGameObject/GameObject.h
src/nsGameObject/Character.cpp
src/nsGameObject/Character.h
src/nsRessourceManager/Animator.cpp
src/nsRessourceManager/Animator.h
src/nsRessourceManager/RoomReader.cpp
src/nsRessourceManager/RoomReader.h
src/nsRessourceManager/RessourceManager.cpp
src/nsRessourceManager/RessourceManager.h
src/nsRessourceManager/const.h
src/nsGameObject/Interface.h
src/nsGameEngine/Game.cpp
src/nsGameEngine/Game.h
src/nsGameEngine/QuadTree.cpp
src/nsGameEngine/QuadTree.h
src/nsGameObject/Player.cpp
src/nsGameObject/Player.h
src/nsGameObject/Entity.cpp
src/nsGameObject/Entity.h
src/nsPyramidProject/Fabric.h
src/nsPyramidProject/Fabric.cpp
src/nsGameObject/Foreground.cpp
src/nsGameObject/Foreground.h
src/nsGameObject/Decoration.cpp
src/nsGameObject/Decoration.h
src/nsGameEngine/nsCollision/Collider.cpp
src/nsGameEngine/nsCollision/Collider.h
src/Utility/typedef.hpp
src/VisualTest.cpp
src/VisualTest.h
src/UnitTest.cpp
src/UnitTest.h
src/VisualTest.cpp
src/VisualTest.h
src/nsGameEngine/Movement.h
src/nsGameEngine/Movement.cpp
src/nsRessourceManager/KBManager.cpp
src/nsRessourceManager/KBManager.h
src/nsPyramidProject/Stair.cpp src/nsPyramidProject/Stair.h src/nsPyramidProject/Map.cpp src/nsPyramidProject/Map.h)


include(configSFMLMakefileHelper.txt)


