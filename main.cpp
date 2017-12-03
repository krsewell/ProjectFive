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
#include <memory>


#include "inputtools.hpp"
#include "cargo.hpp"
#include "planet.hpp"
#include "ship.hpp"
#include "trip.hpp"

using speed = long long;
using weight = int;
using gravity = float;
using distance = long long;

void printheader();
void initTransport(std::map<std::string,std::shared_ptr<Planet>>&, std::vector<std::shared_ptr<Ship>>&, std::ofstream&);
std::string getDefaultSettings();




int main() {
  std::map<std::string,std::shared_ptr<Planet>> planets;
  std::vector<std::shared_ptr<Ship>> ships;
  std::ofstream fout;

  printheader();
  initTransport(planets,ships,fout);


  return 0;
}




void printheader() {
  std::cout << "########################################################\n"
            << "#       Interplanetary Transport Tracking System       #\n"
            << "########################################################\n"
            << std::endl << std::endl;
  std::cout << "This program can be used to track intergalatic shipments\n" 
            << "and verify each journeys feasablity. Options for additional\n"
            << "planets/ships may be set from \"conf\" files within the program\ndirectories."
            << std::endl << std::endl;
}

void initTransport(std::map<std::string,std::shared_ptr<Planet>>& p, std::vector<std::shared_ptr<Ship>>& s, std::ofstream& f) {
  /*  
    Open the settings file. If it doesn't exist create it. If it is inaccessable we should exit the program. 
  */
  std::ifstream file;
  do {
    file.open("settings.conf",std::ifstream::in);
    // If you can't open the file it must not be there or is locked. If it is locked exit(-1) we can't write to the same file.
    if (file.fail()){
      file.clear();
      std::ofstream out("settings.conf",std::ofstream::out);
      if (out.is_open()){
        out << getDefaultSettings();
        out.close();
      } else {
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
  std::vector<std::string> keywords = {"PLANET","OUTPUTFILE"};
  
  while (file.good()) {
    std::string str;
    std::getline(file,str);
    line++;
    trim(str);
    capitolize(str);
    if (str.empty() || str.at(0) == '#') continue;
    for (std::string k : keywords) {
      auto x = str.find(k);
      
      if (x == std::string::npos) continue;
      
      if (k == "PLANET") {
        trim(str);
        truc(str);
        //std::cout << "Planet name: " << str << std::endl;
        keywords.push_back(str);
        p[str] = std::make_shared<Planet>();
      }
      else if (k == "OUTPUTFILE") {
        trim(str);
        trim(str,'\"');
        truc(str,'\"');
        //std::cout << "File name: " << str << std::endl;
        f.open(str,std::ios::app);
      }
      else {
        //find keywords distance or gravity and call appropriate object function.
        auto d = str.find("DISTANCE");
        auto g = str.find("GRAVITY");
        trim(str);
        truc(str);
        if (d != std::string::npos) {
          //std::cout << "\tDistance from Sun: " << std::stoll(str) << std::endl;
          p[k]->setDistance(std::stoll(str));
        }
        else if (g != std::string::npos) {
          //std::cout << "\tGravity Coefficent: " << std::stof(str) << std::endl;
          p[k]->setGravity(std::stof(str));
        }
      }
    }
  }
  /*
    Initialize Ships - By default generic ship will be created in 0 position.
  */
  s.push_back(std::make_shared<Ship>(670616629ll,22040));
  std::cout << "Settings successfully Loaded..\n";
}

std::string getDefaultSettings() {
  std::ostringstream stream;
  //absolutely horrendous, I know. Will come up with something better when I have time.
  stream  << "#   Planetary Transport System Config File\n#   Any line beginning with \'#\' is ignored.\n\n#\n#   Output"
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