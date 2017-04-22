//
// Created by Brady Bodily on 4/22/17.
//

#ifndef ITAK_ITAK_HPP
#define ITAK_ITAK_HPP

#include "Result.hpp"
#include "DOSAnalyzer.hpp"
#include "Config.hpp"
#include "Analyzer.hpp"
#include "PortScanAnalyzer.hpp"

#include <iostream>


class ITAK
{
public:
    ITAK(ifstream& fin, int Time, int Num, int PossNum, int PortAttacks, int PossPortAttacks);
    void Print();
    UserIPList* Addresses;
    std::vector<Config>* DOSConfigs;
    std::vector<Config>* PortScanConfigs;
    Result DenialOfServiceResults;
    Result PortScanResults;
    DOSAnalyzer* DenialAnalyzer;
    POSAnalyzer* PortAnalyzer;



};

#endif //ITAK_ITAK_HPP
