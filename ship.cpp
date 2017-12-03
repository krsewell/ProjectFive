/*
 *   kjs170430_Project5/ship.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */
#include "ship.hpp"
    
    //creates a kind of useless object. Only included for future use/expansion.
    Ship::Ship() {
        _speed_limit = 0;
        _weight_limit = 0;
    }

    //only ensures that an object is created without negetive values. beware of zero.
    Ship::Ship(speed spd, weight wgt) {
        _speed_limit = std::abs(spd);
        _weight_limit = std::abs(wgt);
    }
    
    Ship::~Ship() {}
    
    // Because there is no default way to change the limits they are returned as constants
    // There are ways for subclasses to change the values however.
    const speed Ship::getSpeedLimit() {
        return _speed_limit;
    }
    
    const weight Ship::getWeightLimit() {
        return _weight_limit;
    }