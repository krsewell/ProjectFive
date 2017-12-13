/*
 *   kjs170430_Project5/ship.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */
#include "ship.hpp"

//creates a kind of useless object. Only included for future use/expansion.
Ship::Ship()
{
  _speed_limit = 0;
  _weight_limit = 0.0f;
}

//only ensures that an object is created without negetive values. beware of zero.
Ship::Ship(speed spd, weight wgt)
{
  _speed_limit = std::abs(spd);
  _weight_limit = std::abs(wgt);
}

Ship::~Ship() {}

// Because there is no default way to change the limits they are returned as constants
// There are ways for subclasses to change the values however.
const speed Ship::getSpeedLimit() const
{
  return _speed_limit;
}

const weight Ship::getWeightLimit() const
{
  return _weight_limit;
}

hours Ship::calcTravelTime(speed velocity, distance miles) const 
{
  auto x = static_cast<double>(miles) * 1000000 / velocity;
  return static_cast<hours>(x);
}

std::string Ship::formatTime(hours h) const
{
  //there are 24 hours in one day and 365 days in one year
  auto raw_days = h / 24;
  auto hours_remainder = h % 24;
  auto raw_years = raw_days / 365;
  auto days_remainder = raw_days % 365;
  std::ostringstream ss;
  ss  << raw_years << ':' << std::setw(3) 
      << std::setfill('0') << days_remainder << ':'
      << std::setw(2) << std::setfill('0') << hours_remainder;
  
  return ss.str();
}