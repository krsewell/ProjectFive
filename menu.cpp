/*
 *   kjs170430_Project5/menu.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */
#include "menu.hpp"

void Option::displayMenuOption()
{
  std::cout << std::to_string(this->_menu_num) << ".) " << this->_displaystring << std::endl;
}

bool Option::checkDisplay()
{
  return this->_display;
}

void Option::toggleDisplay()
{
  this->_display ? this->_display = false : this->_display = true;
}

int Option::menuNum()
{
  return this->_menu_num;
}

PlanetOption::PlanetOption(std::shared_ptr<Planet> pla, int num, const std::string str) : _planetPtr(pla)
{
  this->_menu_num = num;
  this->_displaystring = str;
}

void PlanetOption::action()
{
}

Menu::Menu(std::vector<PlanetOption> v, std::string s)
{
  std::copy(v.begin(), v.end(), std::back_inserter(this->_menu));
  this->_header = s;
}

std::shared_ptr<Planet> Menu::PrintMenu(const std::string str)
{
  std::vector<int> check;
  //prints out menu options
  std::cout << this->_header << std::endl;
  for (auto &it : this->_menu)
  {
    if (it.checkDisplay())
    {
      it.displayMenuOption();
      check.push_back(it.menuNum());
    }
  }
  //big O for verification and search is n^2. however, ranges should be fairly small.
  while (true)
  {
    int x;
    std::cout << str;
    inputReturn(x);
    std::cout << std::endl;
    // will return an int but we need to make sure it matchs a menu choice.
    for (auto s : check)
    {
      if (s == x)
      {
        // find the menu option.
        for (auto &opt : this->_menu)
        {
          if (x == opt.menuNum())
          {
            opt.toggleDisplay();
            return opt._planetPtr;
          }
        }
      }
    }
    std::cout << "Incorrect Option: please try again.\n";
  }
}