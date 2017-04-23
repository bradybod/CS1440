//
// Created by Brady Bodily on 4/22/17.
//

#include "ITAK.hpp"
#include "PortScanAnalyzer.hpp"
#include "DOSAnalyzer.hpp"


ITAK::ITAK(ifstream& fin, int Time, int Num, int PossNum, int PortAttacks, int PossPortAttacks) {
    Addresses = new UserIPList(&fin);
    if (Num <= PossNum) {
        throw invalid_argument("Invalid Argument: Limit <= Watchlist");
    }

    if (PortAttacks <= PossPortAttacks) {
        throw invalid_argument("Invalid Argument: Limit <= watchlist");
    }

    Config TimeSpan("Time span", Time);
    Config MessageCount("Likely Attack Message Count", Num);
    Config PossMCount("Possible Attack Message Count", PossNum);
    DOSConfigs = new vector<Config>;
    PortScanConfigs = new vector<Config>;
    (*DOSConfigs).push_back(TimeSpan);
    (*DOSConfigs).push_back(MessageCount);
    (*DOSConfigs).push_back(PossMCount);
    (*PortScanConfigs).push_back(Config("Likely Attack Port Count", PortAttacks));
    (*PortScanConfigs).push_back(Config("Possible Attack Port Count", PossPortAttacks));
    DenialAnalyzer = new DOSAnalyzer(DOSConfigs, Addresses);
    PortAnalyzer = new POSAnalyzer(PortScanConfigs, Addresses);
    DenialOfServiceResults = DenialAnalyzer->Run();
    PortScanResults = PortAnalyzer->Run();
}


void ITAK::Print() {
    printf("----DOS Analyzer----\n\n");
    DenialOfServiceResults.PrintDictionary();
    printf("\n\n----Port Scan Analyzer----\n\n");
    PortScanResults.PrintDictionary();
}
