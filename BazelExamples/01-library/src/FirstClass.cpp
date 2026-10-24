#include "FirstClass.h"
#include <string>


void FirstClass::Set(const std::string& string) {
  string_ = string;    
}


std::string FirstClass::Get() const {
  return string_;  
}

