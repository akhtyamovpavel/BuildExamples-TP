#include <boost/python.hpp>

#include "sum.h"

BOOST_PYTHON_MODULE(summer)
{
    boost::python::def("sum", &sum);   
}