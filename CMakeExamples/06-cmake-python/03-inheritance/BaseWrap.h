//
// Created by Pavel Akhtyamov on 2019-04-04.
//

#pragma once

#include "Base.h"
#include <boost/python.hpp>

using boost::python::wrapper;

class BaseWrap : public Base, public wrapper<Base> {
 public:
  int f();
  int g();
  int default_g();
};



