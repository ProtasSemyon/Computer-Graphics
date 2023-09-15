cmake_minimum_required(VERSION 3.5...3.16)
project(ComputerGraphics VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(
  GLOB_RECURSE
  SOURCES
  CONFIGURE_DEPENDS
  "src/*.hpp"
  "src/*.cpp")

add_executable(ComputerGraphics main.cpp ${SOURCES})
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS})
add_subdirectory(./lib/imgui)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC src)
target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw imgui imgui-glfw imgui-opengl3)
