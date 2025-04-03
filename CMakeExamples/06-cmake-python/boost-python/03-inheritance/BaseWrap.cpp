//
// Created by Pavel Akhtyamov on 2019-04-04.
//

#include "BaseWrap.h"

using boost::python::override;


int BaseWrap::f() {
  return get_override("f")();
}

int BaseWrap::g() {
  if (override g = this->get_override("g")) {
    return g();
  }
  return Base::g();
}

int BaseWrap::default_g() {
  return Base::g();
}
