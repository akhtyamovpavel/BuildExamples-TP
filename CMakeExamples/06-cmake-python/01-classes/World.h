//
// Created by Pavel Akhtyamov on 2019-04-04.
//

#pragma once

#include <string>

struct World {
  explicit World(std::string message);
  void set(std::string message);
  std::string greet();
  std::string message;
};



