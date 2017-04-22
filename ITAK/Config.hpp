//
// Created by Brady Bodily on 4/22/17.
//

#ifndef ITAK_CONFIG_HPP
#define ITAK_CONFIG_HPP
#include "UserIPList.hpp"
#include "KeyValue.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Config {
public:
    string GetType();
    int GetValue();
    Config(string type, int value);
private:
    string Type;
    int Value;

};
#endif //ITAK_CONFIG_HPP
