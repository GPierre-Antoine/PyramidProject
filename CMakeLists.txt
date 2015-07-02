cmake_minimum_required(VERSION 3.2)
project(PyramidProject)
#message(WARNING ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -mwindows")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES src/main.cpp)

set(EXECUTABLE_NAME Pyramid_Project)

add_executable(${EXECUTABLE_NAME} WIN32 ${SOURCE_FILES}
src/nsGameObject/GameObject.cpp
src/nsGameObject/GameObject.h
src/nsGameObject/Character.cpp
src/nsGameObject/Character.h
src/nsRessourceManager/Animator.cpp
src/nsRessourceManager/Animator.h
src/nsRessourceManager/RoomReader.cpp
src/nsRessourceManager/RoomReader.h
#src/nsRessourceManager/RessourceManager.cpp
#src/nsRessourceManager/RessourceManager.h
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
src/nsGameEngine/Fabric.h
src/nsGameEngine/Fabric.cpp
src/nsGameEngine/Fabric.cpp
src/nsGameEngine/Fabric.h
src/nsGameObject/Foreground.cpp
src/nsGameObject/Foreground.h
src/nsGameObject/Decoration.cpp
src/nsGameObject/Decoration.h
src/nsGameEngine/Collision/Collider.cpp
src/nsGameEngine/Collision/Collider.h
src/nsGameEngine/Defines/typedef.hpp)

#pour l'executable Pyramid_Project
find_package(SFML 2 REQUIRED audio graphics network window system)

if(SFML_FOUND)

    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

endif()


include(configSFMLMakefileHelper.txt)


