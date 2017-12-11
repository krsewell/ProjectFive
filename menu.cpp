/*
 *   kjs170430_Project5/menu.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */
#include "menu.hpp"


void Option::displayMenuOption(){
  std::cout << std::to_string(this->_menu_num) << ".) " << this->_displaystring << std::endl; 

}

bool Option::checkDisplay(){
  return this->_display;

}

void Option::toggleDisplay(){
  this->_display ? this->_display = false : this->_display = true;

}

int Option::menuNum() {
  return this->_menu_num;
}

PlanetOption::PlanetOption(std::shared_ptr<Planet> pla, int num, const std::string str) :
   _planetPtr(pla) {
    this->_menu_num = num;
    this->_displaystring = str;
}

void PlanetOption::action(){


}

template<typename T>
Menu<T>::Menu(std::vector<T> v, std::string s) {
  this->_menu = v;
  this->_header = s;
}

template<typename T,typename P>
std::shared_ptr<P> Menu<T>::PrintMenu() {
  int index = 0;
  int check[this->_menu.size()] = {};
  //prints out menu options
  std::cout << _header << std::endl;
  for (auto it = this->_menu.begin(); it != this->_menu.end(); it++) {
    if (this->_menu.at(it).checkDisplay()) {
      this->_menu.at(it).displayMenuOption();
      check[index++] = this->_menu.at(it).menuNum();
    }
  }

  while (true) {
    int x;
    inputReturn(x); 
    // will return an int but we need to make sure it matchs a menu choice.
    for (int index = 0; index < this->_menu.size(); index++) {
      if (check[index] == x) {
        this->_menu.at(x).toggleDisplay();
        return this->_menu.at(x)->_planetPtr;
      }
    }
    std::cout << "Incorrect Option: please try again.\n";
  }
}