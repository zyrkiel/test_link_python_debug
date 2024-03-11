set(FOO_FILES foo.cpp foo.h)

add_library(Foo ${FOO_FILES})

target_link_libraries(Foo PUBLIC Python3::Python pybind11::headers)

# Install library ###
install(
  TARGETS Foo
  EXPORT ${PROJECT_NAME}Targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  INCLUDES
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${INSTALL_NAME})
