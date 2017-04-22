
#ifndef ITAK_DOSANALYZER_HPP
#define ITAK_DOSANALYZER_HPP
#include "KeyValue.hpp"
#include "Config.hpp"
#include "Analyzer.hpp"
#include "KeyCount.hpp"
#include "KeyDictionary.hpp"
#include <vector>

class DOSAnalyzer : public Analyzer {
public:
    DOSAnalyzer(std::vector<Config> *configs, UserIPList *addresses);
    Result Run();
    vector<KeyDictionary> Timestamps;
    int TIMEFRAME;
private:
    UserIPList* Addresses;
    int likelyMCount;
    int possMCount;
};


#endif //ITAK_DOSANALYZER_HPP