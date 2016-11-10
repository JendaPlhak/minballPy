#include <CGAL/Cartesian_d.h>
#include <CGAL/Random.h>
#include <CGAL/Exact_rational.h>
#include <CGAL/Min_sphere_of_spheres_d.h>
#include <array>
#include <vector>
#include "minball_py.hpp"

PYBIND11_PLUGIN(minball) {
    pybind11::module m("minball");
    minball::py_bind(m);
    return m.ptr();
}

namespace minball {

template <uint8_t D>
struct Sphere {
    const std::array<double, D> center;
    const double radius;

    Sphere(const std::array<double, D> center_vec, const double radius)
     : center(center_vec), radius(radius)
    { }
};

void py_bind(py::module& m) {
    constexpr uint8_t D = 2;
    typedef double                            FT;
    typedef CGAL::Cartesian_d<FT>             K;
    typedef CGAL::Min_sphere_of_spheres_d_traits_d<K,FT,D> Traits;
    typedef CGAL::Min_sphere_of_spheres_d<Traits> Min_sphere;
    typedef K::Point_d                        Point;

    py::class_<Sphere<D>>(m, "Sphere2D")
    .def(py::init<const std::array<double, D>, const double>())
    .def_property_readonly("center", [](const Sphere<D>& self) {
        return self.center;
    })
    .def_property_readonly("radius", [](const Sphere<D>& self) {
        return self.radius;
    });

    m.def("get_min_sphere2D", [&](const std::vector<Sphere<D>>& spheres) {
        std::vector<Traits::Sphere> mSpheres;
        for (const auto& s : spheres) {
            Point center(D, s.center.begin(), s.center.end());
            mSpheres.emplace_back(center, s.radius);
        }

        Min_sphere ms(mSpheres.begin(), mSpheres.end());
        CGAL_assertion(ms.is_valid());

        std::array<double, D> center;

        auto begin = ms.center_cartesian_begin();
        auto end = ms.center_cartesian_end();
        size_t i = 0;

        for (auto it = begin; it != end; ++it, ++i) {
            center[i] = *it;
        }
        return Sphere<D>(center, ms.radius());
    });
}

}
