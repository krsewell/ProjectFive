/*
 *   kjs170430_Project5/cargo.hpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */

#ifndef CARGO_H_INCL_GUARD
#define CARGO_H_INCL_GUARD

#include <string>
#include <cstring>
#include "planet.hpp"

using weight = int;
using std::strlen;


class Cargo {
protected:
  weight _src_weight;
  weight _dst_weight;
  weight _earth_weight;
  std::string _type;

public:
  Cargo();
  Cargo(weight,std::string);
  void setEarthWgt(const Planet&);
  void setDstWgt(const Planet&);
  void setSrcWgt(weight);
  void setType(std::string);

  weight getEarthWgt() const;
  weight getDstWgt() const;
  weight getSrcWgt() const;
  std::string printType() const;

};

#endif