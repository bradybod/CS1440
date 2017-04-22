//
// Created by Brady Bodily on 4/22/17.
//

#include "Dictionary.hpp"


KeyValue Dictionary::GetByIndex(int index) { return data[index]; }

KeyValue Dictionary::Find(std::string key) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i].GetKey() == key) { return data[i]; }
    }
    throw std::invalid_argument("Item not Found");
}

std::vector<KeyValue> Dictionary::GetData() { return data; }
