cmake_minimum_required(VERSION 3.23)

project(PythonLinkTest LANGUAGES C CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Configure compiler ###

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      "Debug"
      CACHE STRING "Choose the type of build" FORCE)
endif()

find_package(pybind11 CONFIG REQUIRED)
find_package(
  Python3
  COMPONENTS Interpreter Development
  REQUIRED)

add_subdirectory("foo_lib")

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Foo)
