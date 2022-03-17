#include "sum.h"

int sum(boost::python::list& array) {
    int result = 0;
    for (int index = 0; index < boost::python::len(array); ++index) {
        result += boost::python::extract<int>(array[index]);
    }

    return result;
}