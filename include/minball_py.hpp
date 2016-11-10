#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

namespace minball {
    namespace py = pybind11;
    void py_bind(py::module& m);
}
