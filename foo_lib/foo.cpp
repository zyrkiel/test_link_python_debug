#include <iostream>
#include <pybind11/pybind11.h>

void foo() {
  std::cout << "foo called\n"
            << pybind11::format_descriptor<int16_t>::format() << "\n";
}