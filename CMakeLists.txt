cmake_minimum_required(VERSION 3.2)
project(PyramidProject)
message(WARNING ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -mwindows")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(SOURCE_FILES src/main.cpp)

set(EXECUTABLE_NAME Pyramid_Project)
add_executable(${EXECUTABLE_NAME} WIN32 ${SOURCE_FILES} src/main.h src/main.cpp src/GameObject.cpp src/GameObject.h)


include(configSFMLMakefileHelper.txt)


