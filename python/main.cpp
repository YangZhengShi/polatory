#include <polatory/polatory.hpp>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

using namespace polatory;
namespace py = pybind11;

PYBIND11_MODULE(pola, m)
{
  py::class_<rbf::rbf_base>(m, "_rbf_base");

  py::class_<rbf::biharmonic2d, rbf::rbf_base>(m, "biharmonic2d")
    .def(py::init<const std::vector<double>&>());
  py::class_<rbf::biharmonic3d, rbf::rbf_base>(m, "biharmonic3d")
    .def(py::init<const std::vector<double>&>());
  py::class_<rbf::cov_exponential, rbf::rbf_base>(m, "cov_exponential")
    .def(py::init<const std::vector<double>&>());
  py::class_<rbf::cov_quasi_spherical3, rbf::rbf_base>(m, "cov_quasi_spherical3")
    .def(py::init<const std::vector<double>&>());
  py::class_<rbf::cov_quasi_spherical5, rbf::rbf_base>(m, "cov_quasi_spherical5")
    .def(py::init<const std::vector<double>&>());
  py::class_<rbf::cov_quasi_spherical7, rbf::rbf_base>(m, "cov_quasi_spherical7")
    .def(py::init<const std::vector<double>&>());
  py::class_<rbf::cov_quasi_spherical9, rbf::rbf_base>(m, "cov_quasi_spherical9")
    .def(py::init<const std::vector<double>&>());

  py::class_<model>(m, "model")
    .def(py::init<const rbf::rbf_base&, int, int>())
    .def_property("nugget", &model::nugget, &model::set_nugget);

  py::class_<interpolant>(m, "interpolant")
    .def(py::init<const model&>())
	.def("centers", &interpolant::centers)
    .def("evaluate", &interpolant::evaluate_points)
    .def("fit", &interpolant::fit)
    .def("weights", &interpolant::weights);
}
