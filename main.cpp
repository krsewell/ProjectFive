/*
 *   kjs170430_Project5/main.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */

#include <iostream>

void printheader();
void initTransport();

int main() {
  printheader();
  initTransport();


}

void printheader() {
  std::cout << "########################################################"
            << "#       Interplanetary Transport Tracking System       #"
            << "########################################################"
            << std::endl << std::endl;
  std::cout << "This program can be used to track intergalatic shipments\n" 
            << "and verify each journeys feasablity. Options for additional\n "
            << "planets/ships may be set from \"conf\" files within the program directories."
            << std::endl << std::endl;
}