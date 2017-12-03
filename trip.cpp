/*
 *   kjs170430_Project5/trip.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */
#include "trip.hpp"

Trip::Trip(Planet& s, Planet& d, speed v, Cargo& c, Ship& t) : 
    _src(s), _dst(d), _cargo(c), _ship(t) 
{
    _speed = abs(v);
}