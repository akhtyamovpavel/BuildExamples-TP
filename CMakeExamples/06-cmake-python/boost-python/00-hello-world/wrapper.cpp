//
// Created by Pavel Akhtyamov on 2019-04-04.
//

#include <boost/python.hpp>
#include "greet.h"


BOOST_PYTHON_MODULE(hello_ext)
{
  boost::python::def("greet", greet);
}
