//
// Created by Brady Bodily on 4/22/17.
//

#ifndef ITAK_KEYDICTIONARY_HPP
#define ITAK_KEYDICTIONARY_HPP
#include "KeyCount.hpp"
#include <string>
class KeyDictionary
{
public:
    KeyDictionary(std::string key, std::vector<KeyCount> Time){IPAddress = key; 
        for (int i = 0; i < Time.size(); i++){TimeStamps[i] = Time[i];}}
    std::string IPAddress;
    std::vector<KeyCount> TimeStamps;
};
#endif //ITAK_KEYDICTIONARY_HPP
