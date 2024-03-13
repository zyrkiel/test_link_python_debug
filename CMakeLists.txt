cmake_minimum_required(VERSION 3.23)

project(PythonLinkTest LANGUAGES C CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Configure compiler ###

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Unable find ABI : fix link for pybind debug build (working for linux)
# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#   set(Python3_FIND_ABI "ON" "ANY" "ANY")
# else()
#   set(Python3_FIND_ABI "OFF" "ANY" "ANY")
# endif()
find_package(
  Python3
  COMPONENTS Interpreter Development
  REQUIRED)
find_package(pybind11 CONFIG REQUIRED)

add_subdirectory("foo_lib")

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Foo)
