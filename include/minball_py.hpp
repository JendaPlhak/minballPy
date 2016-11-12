#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

namespace minball {
    namespace py = pybind11;

    constexpr uint16_t DIM_FROM = 1;
    constexpr uint16_t DIM_TO = 4;
    template <uint16_t Dim = DIM_FROM>
    void py_bind(py::module& m);
}
