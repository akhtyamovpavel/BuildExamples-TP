//
// Created by Pavel Akhtyamov on 2019-04-04.
//

#pragma once

#include <string>

struct Var {
  explicit Var(const std::string& name);

  std::string const name;
  float value;

  float id;

  std::string get_message() const;

  float get_id();

  void set_id(float id);
};



