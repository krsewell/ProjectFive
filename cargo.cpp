/*
 *   kjs170430_Project5/cargo.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */

#include "cargo.hpp"


  Cargo::Cargo() {
    _src_weight = 0;
    _type = "";
  }

  Cargo::Cargo(weight w, std::string t) {
    _src_weight = abs(w);
    _type = t;
  }

  void Cargo::setEarthWgt(const Planet& p) {
    this->_earth_weight = p.earthwgt(this->_src_weight);
  }

  void Cargo::setDstWgt(const Planet& p) {
    this->_dst_weight = p.planetwgt(this->_earth_weight);
  }

  void Cargo::setSrcWgt(weight w) {
    this->_src_weight = abs(w);
  }

  void Cargo::setType(std::string t) {
    this->_type = std::strlen(t.c_str()) > static_cast<size_t>(60) ? t.substr(0,60) + "..." : t;
  }

  weight Cargo::getEarthWgt() const {
    return this->_earth_weight;
  }

  weight Cargo::getDstWgt() const {
    return this->_dst_weight; 
  }

  weight Cargo::getSrcWgt() const {
    return this->_src_weight;
  }

  std::string Cargo::printType() const {
    return this->_type;
  }
