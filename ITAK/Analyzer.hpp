//
// Created by Brady Bodily on 4/22/17.
//

#ifndef ITAK_ANALYZER_HPP
#define ITAK_ANALYZER_HPP
#include "Result.hpp"
#include "KeyValue.hpp"
#include "Config.hpp"

#include <vector>
#include <iostream>

class Analyzer {
public:
    Analyzer(){};
    virtual Result Run() = 0;
};
#endif //ITAK_ANALYZER_HPP
