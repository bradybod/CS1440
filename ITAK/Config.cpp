//
// Created by Brady Bodily on 4/22/17.
//

#include "Config.hpp"
Config::Config(string type, int value) {
    this->Type = type;
    this->Value = value;
}
string Config::GetType() { return Type; }
int Config::GetValue() { return Value; }