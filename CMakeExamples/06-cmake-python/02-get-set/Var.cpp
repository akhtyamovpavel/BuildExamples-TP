//
// Created by Pavel Akhtyamov on 2019-04-04.
//

#include "Var.h"

Var::Var(const std::string& name) : name(name) {}

float Var::get_id() {
  return id;
}

void Var::set_id(float id) {
  this->id = id;
}

std::string Var::get_message() const {
  return "This is my world";
}
