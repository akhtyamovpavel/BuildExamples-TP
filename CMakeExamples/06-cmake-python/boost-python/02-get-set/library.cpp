//
// Created by Pavel Akhtyamov on 2019-04-04.
//

#include <boost/python.hpp>
#include "Var.h"
#include "config.h"

using boost::python::class_;
using boost::python::init;


BOOST_PYTHON_MODULE(PACKAGE_NAME) {
  class_<Var>("Var", init<std::string>())
      .def_readonly("name", &Var::name)
      .def_readwrite("value", &Var::value)
      .add_property("message", &Var::get_message)
      .add_property("id", &Var::get_id, &Var::set_id);
}