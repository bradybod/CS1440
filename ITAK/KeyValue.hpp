//
// Created by Brady Bodily on 4/22/17.
//

#ifndef ITAK_KEYVALUE_HPP
#define ITAK_KEYVALUE_HPP

#include "UserIP.hpp"
#include <vector>
#include <string>

class KeyValue {
public:
    std::string Key;
    KeyValue();
    std::string GetKey();
    std::vector<UserIP> GetValue();
    std::vector<UserIP> Value;
    void SetKey(std::string key);
    void SetValue(std::vector<UserIP> value);
    void AddValue(UserIP ValueToAdd);
    KeyValue(std::string key, std::vector<UserIP> value);
    void AddToValue(UserIP valueToAdd);


};


#endif //ITAK_KEYVALUE_HPP
