#include <polatory/polatory.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

using namespace polatory;
namespace py = pybind11;

PYBIND11_MODULE(polatory, m)
{
  py::class_<rbf::rbf_base>(m, "_RbfBase")
    .def_property("anisotropy", &rbf::rbf_base::anisotropy, &rbf::rbf_base::set_anisotropy);

  py::class_<rbf::biharmonic2d, rbf::rbf_base>(m, "Biharmonic2D")
    .def(py::init<const std::vector<double>&>());
  py::class_<rbf::biharmonic3d, rbf::rbf_base>(m, "Biharmonic3D")
    .def(py::init<const std::vector<double>&>());
  py::class_<rbf::cov_exponential, rbf::rbf_base>(m, "CovExponential")
    .def(py::init<const std::vector<double>&>());
  py::class_<rbf::cov_spheroidal3, rbf::rbf_base>(m, "CovSpheroidal3")
    .def(py::init<const std::vector<double>&>());
  py::class_<rbf::cov_spheroidal5, rbf::rbf_base>(m, "CovSpheroidal5")
    .def(py::init<const std::vector<double>&>());
  py::class_<rbf::cov_spheroidal7, rbf::rbf_base>(m, "CovSpheroidal7")
    .def(py::init<const std::vector<double>&>());
  py::class_<rbf::cov_spheroidal9, rbf::rbf_base>(m, "CovSpheroidal9")
    .def(py::init<const std::vector<double>&>());

  py::class_<model>(m, "Model")
    .def(py::init<const rbf::rbf_base&, int, int>())
    .def_property("nugget", &model::nugget, &model::set_nugget);

  py::class_<interpolant>(m, "Interpolant")
    .def(py::init<const model&>())
    .def("centers", &interpolant::centers)
    .def("evaluate", &interpolant::evaluate)
    .def("fit", &interpolant::fit)
    .def("weights", &interpolant::weights);

  py::class_<point_cloud::distance_filter>(m, "DistanceFilter")
    .def(py::init<const geometry::points3d&, double>())
    .def_property_readonly("filtered_indices", &point_cloud::distance_filter::filtered_indices);
}
