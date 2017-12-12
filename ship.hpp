/*
 *   kjs170430_Project5/ship.hpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */

#ifndef SHIP_H_INCL_GUARD
#define SHIP_H_INCL_GUARD

#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

using speed = long long;
using hours = long long;
using distance = long long;
using weight = float;

class Ship
{
protected:
  speed _speed_limit;
  weight _weight_limit;

public:
  Ship();
  Ship(speed, weight);
  ~Ship();
  const speed getSpeedLimit() const;
  const weight getWeightLimit() const;
  hours calcTravelTime(const speed, const distance) const;
  std::string formatTime(const hours) const;
};

#endif