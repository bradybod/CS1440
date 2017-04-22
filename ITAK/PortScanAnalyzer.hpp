//
// Created by Brady Bodily on 4/22/17.
//

#ifndef ITAK_PORTSCANANALYZER_HPP
#define ITAK_PORTSCANANALYZER_HPP

#include "KeyValue.hpp"
#include "Analyzer.hpp"
#include "Config.hpp"
#include <iostream>

class POSAnalyzer : public Analyzer {
public:
    POSAnalyzer(std::vector<Config>* configs, UserIPList* addresses);
    virtual Result Run();
private:
    int LikelyPCount;
    int PossPCount;
    UserIPList* Addresses;
    int PortCount;
};


#endif //ITAK_PORTSCANANALYZER_HPP
