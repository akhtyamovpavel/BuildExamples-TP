//
// Created by Pavel Akhtyamov on 2019-04-04.
//

#include "World.h"

void World::set(std::string message) {
  this->message = message;
}

std::string World::greet() {
  return message;
}
