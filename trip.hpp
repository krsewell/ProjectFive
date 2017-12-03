/*
 *   kjs170430_Project5/trip.hpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */

#ifndef TRIP_H_INCL_GUARD
#define TRIP_H_INCL_GUARD

#include "cargo.hpp"
#include "planet.hpp"
#include "ship.hpp"


class Trip {
public:
    const Planet& _src;
    const Planet& _dst;
    speed _speed;
    Cargo& _cargo;
    const Ship& _ship;

    Trip(Planet&,Planet&,speed,Cargo&,Ship&);
    ~Trip();


};

#endif