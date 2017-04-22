//
// Created by Brady Bodily on 4/22/17.
//

#ifndef ITAK_DICTIONARY_HPP
#define ITAK_DICTIONARY_HPP

#include "KeyValue.hpp"
#include <vector>

class Dictionary {
    std::vector<KeyValue> data;
public:
    KeyValue GetByIndex(int index);
    KeyValue Find(std::string key);
    std::vector<KeyValue> GetData();
};


#endif //ITAK_DICTIONARY_HPP
