//
// Created by Pavel Akhtyamov on 2019-04-04.
//


#include <boost/python.hpp>
#include "BaseWrap.h"

using boost::python::class_;
using boost::python::pure_virtual;
using boost::python::init;


BOOST_PYTHON_MODULE(inheritance) {
  class_<BaseWrap, boost::noncopyable>("Base", init<>())
      .def("f", pure_virtual(&Base::f))
      .def("g", &Base::g);
}
