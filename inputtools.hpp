#ifndef INPUT_TOOLS_H_INCL_GUARD
#define INPUT_TOOLS_H_INCL_GUARD

#include <iostream>
#include <limits>



template<typename T>
void inputReturn(T& var) {
    while (true) {
        if (std::cin >> var) {
            return;
        } else {
            std::cout << "That value is not valid." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
}

template<typename T>
bool isPositive(const T var) {
    return var >= 0 ? true:false;
}

template<typename T>
bool isZero(const T var) {
    return var == 0 ? true:false;
}

void trim(std::string& s, char ch = ' ') {
    const auto begin = s.find_first_not_of(ch);
    const auto end = s.find_last_not_of(ch);
    if (begin == std::string::npos){
        return;
    }

    s = s.substr(begin,(end - begin + 1));
    
    if (s.at(0) == '\t')
        trim(s,'\t');
    if (s.at(0) == ' ')
        trim(s);
}

void truc(std::string& s, char ch = '=') {
    const auto begin = s.find_first_of(ch);
    const auto end = s.size();
    s = s.substr(begin + 1,(end - begin + 1));
}

void capitolize(std::string& s) {
    for (auto& c : s) {
        c = toupper(c);
    }
}

#endif