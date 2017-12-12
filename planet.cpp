/*
 *   kjs170430_Project5/planet.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */

#include "planet.hpp"

Planet::Planet() {
  m_gravity = 0.0;
  m_distancetoSun = 0;
  std::cout << "Planet created\n";
}

Planet::~Planet() {}

weight Planet::earthwgt(weight w) const {
  return (w / this->m_gravity);
}

weight Planet::planetwgt(weight w) const {
  return (w * this->m_gravity);
}

distance Planet::distanceto(Planet& p) const{
  return this->m_distancetoSun > p.m_distancetoSun ? 
          this->m_distancetoSun - p.m_distancetoSun :
          p.m_distancetoSun - this->m_distancetoSun;
}

void Planet::setGravity(const gravity x) {
  this->m_gravity = x;
}

void Planet::setDistance(const distance d) {
  this->m_distancetoSun = d;
}