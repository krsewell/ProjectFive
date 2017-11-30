/*
 *   kjs170430_Project5/cargo.hpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */

#ifndef CARGO_H_INCL_GUARD
#define CARGO_H_INCL_GUARD

#include <string>
#include "planet.hpp"

using std::string;
using speed = unsigned;
using time = unsigned long long;

class Cargo {
private:
  Planet& m_source;
  Planet& m_destination;
  weight m_earth_weight;
  string m_type;
  time m_duration;

public:



};

#endif