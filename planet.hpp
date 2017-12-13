/*
 *   kjs170430_Project5/planet.hpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */

#ifndef PLANET_H_INCL_GUARD
#define PLANET_H_INCL_GUARD

#include <iostream>
#include <cmath>

using weight = float;
using gravity = float;
using distance = long long;

class Planet
{
private:
  gravity m_gravity; // should always be a positive number
  distance m_distancetoSun;

public:
  Planet();
  Planet(gravity, distance);
  ~Planet();

  weight earthwgt(weight) const;
  weight planetwgt(weight) const;
  distance distanceto(Planet &) const;
  gravity getGravity() const;

  void setGravity(const gravity x);
  void setDistance(const distance d);
};

#endif