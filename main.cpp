/*
 *   kjs170430_Project5/main.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 5
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <memory>

#include "inputtools.hpp"
#include "cargo.hpp"
#include "planet.hpp"
#include "ship.hpp"
#include "trip.hpp"
#include "menu.hpp"

using speed = long long;
using weight = float;
using gravity = float;
using distance = long long;

void printheader();
void initTransport(std::map<std::string, std::shared_ptr<Planet>> &, std::vector<std::shared_ptr<Ship>> &, std::ofstream &);
void printrecord(Trip &, std::ofstream &);
Trip getuserinput(const std::map<std::string, std::shared_ptr<Planet>> &, const std::vector<std::shared_ptr<Ship>> &);
std::string getDefaultSettings();
bool again();

int main()
{
  std::map<std::string, std::shared_ptr<Planet>> planets;
  std::vector<std::shared_ptr<Ship>> ships;
  std::ofstream fout;

  printheader();
  initTransport(planets, ships, fout);
  while (true)
  {
    Trip trip = getuserinput(planets, ships);
    printrecord(trip, fout);
    if (!again())
      break; //exit condition
  }

  //cleanup
  fout.close();

  return 0;
}

void printheader()
{
  std::cout << "########################################################\n"
            << "#       Interplanetary Transport Tracking System       #\n"
            << "########################################################\n"
            << std::endl
            << std::endl;
  std::cout << "This program can be used to track intergalatic shipments\n"
            << "and verify each journeys feasablity. Options for additional\n"
            << "planets/ships may be set from \"conf\" files within the program\ndirectories."
            << std::endl
            << std::endl;
}

void initTransport(std::map<std::string, std::shared_ptr<Planet>> &p,
                   std::vector<std::shared_ptr<Ship>> &s,
                   std::ofstream &f)
{
  /*  
    Open the settings file. If it doesn't exist create it. If it is inaccessable we should exit the program. 
  */
  std::ifstream file;
  do
  {
    file.open("settings.conf", std::ifstream::in);
    // If you can't open the file it must not be there or is locked. If it is locked exit(-1) we can't write to the same output file.
    if (file.fail())
    {
      file.clear();
      std::ofstream out("settings.conf", std::ofstream::out);
      if (out.is_open())
      {
        out << getDefaultSettings();
        out.close();
      }
      else
      {
        std::cout << "Error: Could not open settings.conf. Could already be open?" << std::endl;
        exit(-1);
      }
    }
  } while (!file.is_open());
  std::cout << "Successfully opened Settings.." << std::endl;
  /*
    Next parse each line. When we find a '#' or empty line we will continue.
  */
  int line = 0;
  std::vector<std::string> static_keywords;
  std::vector<std::string> dynamic_keywords;

  auto kit = static_keywords.begin();
  kit = static_keywords.insert(kit, std::string("OUTPUTFILE"));
  kit = static_keywords.insert(kit, std::string("PLANET"));
  // first run we can only find planet and output file. So build new list that
  // we will use later.
  while (file.good())
  {
    std::string str;
    std::getline(file, str);
    line++;
    if (str.empty() || str.at(0) == '#')
      continue;

    trim(str);
    capitolize(str);
    for (auto k : static_keywords)
    {
      auto x = str.find(k);
      if (x == std::string::npos)
        continue;

      if (k == "PLANET")
      {
        trim(str);
        truc(str);
        std::cout << "Planet name: " << str << std::endl;
        dynamic_keywords.push_back(str);
        p.insert(std::pair<std::string, std::shared_ptr<Planet>>(str, std::make_shared<Planet>()));
      }
      else if (k == "OUTPUTFILE")
      {
        trim(str);
        trim(str, '\"');
        truc(str, '\"');
        formatfilename(str);
        //currently does no check on if the file is accessible or exists.
        if (fileExists(str))
        {  
          f.open(str, std::ios::app);
        }
        else //if first time opening print the table header.
        {
          f.open(str,std::ios::app);
          f   << std::left
              << std::setw(34) << "  Cargo" 
              << std::setw(15) << " Earth Pounds" 
              << std::setw(15) << " Source Pounds" 
              << std::setw(15) << " Dest. Pounds" 
              << std::setw(26) << " Distance (Million Miles)"
              << std::setw(15) << " Travel Time"
              << std::endl;
        }
      }
    }
  }
  //reset file here. then run second pass.
  line = 0;

  file.clear();
  file.seekg(0, file.beg);

  while (file.good())
  {
    std::string str;
    std::getline(file, str);
    line++;

    if (str.empty() || str.at(0) == '#')
      continue;

    trim(str);
    capitolize(str);
    for (auto k : dynamic_keywords)
    {
      auto x = str.find(k);
      if (x == std::string::npos)
        continue;
      //find keywords distance or gravity and call appropriate object function.
      auto d = str.find("DISTANCE");
      auto g = str.find("GRAVITY");
      trim(str);
      truc(str);
      if (d != std::string::npos)
      {
        //std::cout << "\tDistance from Sun: " << std::stoll(str) << std::endl;
        p[k]->setDistance(std::stoll(str));
      }
      else if (g != std::string::npos)
      {
        //std::cout << "\tGravity Coefficent: " << std::stof(str) << std::endl;
        p[k]->setGravity(std::stof(str));
      }
    }
  }
  /*
    Initialize Ships - By default generic ship will be created in 0 position.
  */
  s.push_back(std::make_shared<Ship>(670616629ll, 22040.0f));
  std::cout << "Settings successfully Loaded..\n";
}

void printrecord(Trip &t, std::ofstream &file)
{
  //take care of some last minute data processing.
  t._cargo->setEarthWgt(t._src);
  t._cargo->setDstWgt(t._dst);
  
  //get values to add record.
  auto type = t._cargo->printType();
  auto e_wgt = t._cargo->getEarthWgt();
  auto src_wgt = t._cargo->getSrcWgt();
  auto dst_wgt = t._cargo->getDstWgt();
  auto dist = t._src->distanceto(*t._dst);
  auto t_time = t._ship->calcTravelTime(t._speed,dist);
  auto f_time = t._ship->formatTime(t_time);
  
  // format informaion into a standard line. left aligned with 2 space buffer between
  // cells.
  std::ostringstream ss;
  ss  << ' ' 
      << std::setw(34) << std::left << type 
      << std::setw(15) << std::fixed << std::setprecision(1) << e_wgt
      << std::setw(15) << std::fixed << std::setprecision(1) << src_wgt
      << std::setw(15) << std::fixed << std::setprecision(1) << dst_wgt
      << std::setw(26) << dist 
      << std::setw(15) << f_time << std::endl; 
  
  // record to file.
  file << ss.str();
}

std::string getDefaultSettings()
{
  std::ostringstream stream;
  //absolutely horrendous, I know. Will come up with something better when I have time.
  stream << "#   Planetary Transport System Config File\n#   Any line beginning with \'#\' is ignored.\n\n#\n#   Output"
         << "Registrar\n#\n\nOutputFile=\"Delivery_Report.txt\"\n\n\n#\n#   Planetary destinations\n#\n\n#   Planets are"
         << "created by giving them a name. Afterwards you must define its relative distance to the sun\n#   as well as "
         << "a gravity factor relative to earth's gravity. If these parameters are not defined then the\n#   Planet will"
         << " not be accessible to ship to or from in the program. A template is given below on the re-\n#   commended f"
         << "ormating.\n\n#   Planet=<name>\n#   <name>.distance=<millionmiles>\n#   <name>.gravity=<gravityfactor>\n\n"
         << "Planet=Mercury\nMercury.distance=36\nMercury.gravity=0.27\n\nPlanet=Venus\nVenus.distance=67\nVenus.gravity="
         << "0.86\n\nPlanet=Earth\nEarth.distance=93\nEarth.gravity=1.00\n\nPlanet=Mars\nMars.distance=141\nMars.gravity="
         << "0.37\n\nPlanet=Jupiter\nJupiter.distance=483\nJupiter.gravity=2.64\n\nPlanet=Saturn\nSaturn.distance=886\nSa"
         << "turn.gravity=1.17\n\nPlanet=Uranus\nUranus.distance=1782\nUranus.gravity=0.92\n\nPlanet=Neptune\nNeptune.dis"
         << "tance=2793\nNeptune.gravity=1.44\n";
  return stream.str();
}

Trip getuserinput(const std::map<std::string, std::shared_ptr<Planet>> &p,
                  const std::vector<std::shared_ptr<Ship>> &s)
{
  //ask for the source and destination; present menu...
  std::vector<PlanetOption> planetvector;
  int a = 1;
  for (auto i = p.begin(); i != p.end(); i++)
  {
    planetvector.push_back(PlanetOption(i->second, a++, i->first));
  }
  std::string str = "Below are the locations that we may pickup or deliver cargo.\n";
  auto prompt1 = "Please enter a pickup location: ";
  auto prompt2 = "Please enter a dropoff location: ";
  Menu planetmenu(planetvector, str);
  
  auto src = planetmenu.PrintMenu(prompt1);
  //std::cout << src->planetwgt(10) << std::endl;
  auto dst = planetmenu.PrintMenu(prompt2);
  //std::cout << dst->planetwgt(10) << std::endl;
  //what kind of cargo?
  std::cout << "What type are cargo will we be transporting?" << std::endl;
  std::string cargotype;
  inputReturn(cargotype);

  //find max weight; ask for desired weight...
  weight x = src->earthwgt(s.at(0)->getWeightLimit()); //find the max weight that ship can hold at src
  weight y = dst->earthwgt(s.at(0)->getWeightLimit()); //find the max weight that ship can hold at dst
  
  weight lowerlimit, cargoweight = -1;
  x > y ? lowerlimit = y : lowerlimit = x;  //find the lowest earthwgt limit of src and dst.
  auto trip_limit = src->planetwgt(lowerlimit);
  
  while (cargoweight > trip_limit || cargoweight < 0)
  {
    std::cout << "We can transport " << std::fixed << std::setprecision(2) 
              << trip_limit << "lbs on this route."  << std::endl;
    auto prompt4 = "Please enter cargo weight on pickup planet: ";
    inputReturn(cargoweight,prompt4);
  }
  
  //get speed and check against ship max speed
  speed ship_speed = s.at(0)->getSpeedLimit() + 1;
  while (ship_speed > s.at(0)->getSpeedLimit() || ship_speed < 1)
  {
    std::cout << "The ship can move at a max speed of " << std::to_string(s.at(0)->getSpeedLimit()) << "mph.\n";
    auto prompt3 = "How fast would you like to go: ";
    inputReturn(ship_speed,prompt3);
  }

  //ship pointer
  std::shared_ptr<Ship> ship = s.at(0);

  return Trip(src, dst, ship_speed, std::make_shared<Cargo>(cargoweight, cargotype), ship);
}

bool again()
{
  auto ch = '\0';
  while (ch != 'Y' && ch != 'N')
  {
    std::cout << "Would you like to create another record? ('Y' or 'N'): ";
    inputReturn(ch);
    if (islower(ch))
    {
      ch = toupper(ch);
    }
    std::cout << std::endl;
  }
  if (ch == 'Y')
  {
    return true;
  }
  else
  {
    return false;
  }
}