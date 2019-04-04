//
// Created by Pavel Akhtyamov on 2019-04-04.
//

#include <boost/python.hpp>
#include "World.h"

using boost::python::class_;
using boost::python::init;


BOOST_PYTHON_MODULE(classes_simple)
{
  class_<World>("World", init<std::string>())
      .def("greet", &World::greet)
      .def("set", &World::set);
}