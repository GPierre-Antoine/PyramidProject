cmake_minimum_required(VERSION 3.2)
project(PyramidProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -mwindows")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(EXECUTABLE_NAME Pyramid_Project)

file (GLOB SrcFiles src/*.cpp src/*/*.cpp src/*/*/*.cpp)
file (GLOB Includes src/*.h* src/*/*.h* src/*/*/*.h*)

add_executable(${EXECUTABLE_NAME} ${SrcFiles} ${Includes})

include(configSFMLMakefileHelper.txt)


