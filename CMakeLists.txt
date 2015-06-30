cmake_minimum_required(VERSION 3.2)
project(PyramidProject)
#message(WARNING ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -mwindows")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES src/main.cpp)

set(EXECUTABLE_NAME Pyramid_Project)

add_executable(${EXECUTABLE_NAME} WIN32 ${SOURCE_FILES}
src/GameObject.cpp
src/GameObject.h
src/Character.cpp
src/Character.h
src/Animator.cpp
src/Animator.h
#src/RessourceManager.cpp
#src/RessourceManager.h
src/const.h
)

#pour l'executable Pyramid_Project
find_package(SFML 2 REQUIRED audio graphics network window system)

if(SFML_FOUND)

    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

endif()


include(configSFMLMakefileHelper.txt)


