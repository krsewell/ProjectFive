/*
 *   kjs170430_Project5/ship.hpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */

#ifndef SHIP_H_INCL_GUARD
#define SHIP_H_INCL_GUARD

#include <cmath>

using speed = long long;
using weight = int;

class Ship {
protected:
  speed _speed_limit;
  weight _weight_limit;
public:
  Ship();
  Ship(speed,weight);
  ~Ship();
  const speed getSpeedLimit() const;
  const weight getWeightLimit() const;

};


#endif