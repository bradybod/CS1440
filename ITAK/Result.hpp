//
// Created by Brady Bodily on 4/22/17.
//

#ifndef ITAK_RESULT_HPP
#define ITAK_RESULT_HPP


#include "Dictionary.hpp"
#include "UserIP.hpp"
#include "UserIPList.hpp"
#include <string.h>
#include <vector>


class Result : public Dictionary {
public:
    Result();
    void Add(KeyValue dataToAdd);
    void AddToKey(std::string key);
    void PrintDictionary();
    std::vector<KeyValue> data;
    int TimeSpan;
};



#endif //ITAK_RESULT_HPP
