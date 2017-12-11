/*
 *   kjs170430_Project5/trip.hpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */

#ifndef TRIP_H_INCL_GUARD
#define TRIP_H_INCL_GUARD

#include <memory>

#include "cargo.hpp"
#include "planet.hpp"
#include "ship.hpp"


class Trip {
public:
  const std::shared_ptr<Planet> _src;
  const std::shared_ptr<Planet> _dst;
  speed _speed;
  std::shared_ptr<Cargo> _cargo;
  const std::shared_ptr<Ship> _ship;

  Trip::Trip(std::shared_ptr<Planet> s, 
              std::shared_ptr<Planet> d, 
              speed v, 
              std::shared_ptr<Cargo> c, 
              std::shared_ptr<Ship> t) : 
    _src(s), _dst(d), _cargo(c), _ship(t) 
  {
  _speed = abs(v);
  }

  ~Trip();
};

#endif