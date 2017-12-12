#ifndef INPUT_TOOLS_H_INCL_GUARD
#define INPUT_TOOLS_H_INCL_GUARD

#include <iostream>
#include <limits>
#include <algorithm>
#include <cctype>
#include <sys/stat.h>

template <typename T>
inline void inputReturn(T &var , std::string prompt = "")
{
  while (true)
  {
    if (!prompt.empty())
    {
      std::cout << prompt;
    }
    if (std::cin >> var)
    {
      std::cout << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     
      return;
    }
    else
    {
      std::cout << std::endl << "That value is not valid." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

inline void inputReturn(std::string &var , std::string prompt = "")
{
  while (true)
  {
    if (!prompt.empty())
    {
      std::cout << prompt;
    }
    if (std::getline(std::cin,var))
    {
      std::cout << std::endl;
      //std::cin.clear();
      //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     
      return;
    }
    else
    {
      std::cout << std::endl << "That value is not valid." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

template <typename T>
inline bool isPositive(const T var)
{
  return var >= 0 ? true : false;
}

template <typename T>
inline bool isZero(const T var)
{
  return var == 0 ? true : false;
}

inline void trim(std::string &s, char ch = ' ')
{
  const auto begin = s.find_first_not_of(ch);
  const auto end = s.find_last_not_of(ch);
  if (begin == std::string::npos)
  {
    return;
  }

  s = s.substr(begin, (end - begin + 1));

  if (s.at(0) == '\t')
    trim(s, '\t');
  if (s.at(0) == ' ')
    trim(s);
}

inline void truc(std::string &s, char ch = '=')
{
  const auto begin = s.find_first_of(ch);
  const auto end = s.size();
  s = s.substr(begin + 1, (end - begin + 1));
}

inline void capitolize(std::string &s)
{
  std::transform(s.begin(), s.end(), s.begin(), toupper);
}

inline void formatfilename(std::string &s)
{
  std::transform(s.begin(), s.end(), s.begin(), tolower);
  s[0] = std::toupper(s[0]);
  auto pos = s.find_first_of('_');
  if (pos != std::string::npos)
    s[pos + 1] = std::toupper(s[pos + 1]);
}

inline bool fileExists(const std::string& f) {
  struct stat buf;
  if (stat(f.c_str(),&buf) != -1)
  {
    return true;
  } 
  else 
  {
    return false;
  }
}


#endif