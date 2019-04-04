//
// Created by Pavel Akhtyamov on 2019-04-04.
//

#pragma once

class Base {
 public:
  virtual int f() = 0;
  virtual ~Base() = default;
  virtual int g();
};



