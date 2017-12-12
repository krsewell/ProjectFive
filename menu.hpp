/*
 *   kjs170430_Project5/menu.hpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */

#ifndef MENU_H_INCL_GUARD
#define MENU_H_INCL_GUARD

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "planet.hpp"
#include "inputtools.hpp"

/*
  Defines the classes required to implement the menu system for this program. 
  General Menu, General Option, and submenu options.
*/

class Option
{
protected:
  bool _display = true;       //records wheather the option should be displayed.
  std::string _displaystring; //holds what should be printed out after the menu number.
  int _menu_num;              //the menu index number (unique within submenu)(non-unique globally)

public:
  void displayMenuOption();
  virtual void action() = 0;
  bool checkDisplay();
  void toggleDisplay();
  int menuNum();
};

class PlanetOption : public Option
{

public:
  std::shared_ptr<Planet> _planetPtr; //needed to reference the planet information for action()
  PlanetOption(std::shared_ptr<Planet>, int, const std::string);
  void action();
};

class Menu
{
private:
  std::vector<PlanetOption> _menu;
  std::string _header;

public:
  Menu(std::vector<PlanetOption>, std::string);
  std::shared_ptr<Planet> PrintMenu(const std::string);
};

#endif