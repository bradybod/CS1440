
#include "PortScanAnalyzer.hpp"


POSAnalyzer::POSAnalyzer(std::vector<Config> *configs, UserIPList *addresses){
    Addresses = addresses;
    for (int i = 0; i < (*configs).size(); ++i) {
        if ((*configs)[i].GetType() == "Likely Attack Port Count") {

            LikelyPCount = (*configs)[i].GetValue();
        }
        else if ((*configs)[i].GetType() == "Possible Attack Port Count") {

            PossPCount = (*configs)[i].GetValue();
        }
        else {
            throw invalid_argument("Invalid Configuration");
        }
    }}

Result POSAnalyzer::Run() {
    Result results;
    std::vector<UserIP> tempValue;
    KeyValue LiklyAttackers("Likely Attack Port Count", tempValue);
    KeyValue PossAttackers("Possible Attack Port Count", tempValue);
    KeyValue PortCount("Port Count", tempValue);
    results.data.push_back(LiklyAttackers);
    results.data.push_back(PossAttackers);
    results.data.push_back(PortCount);
    std::vector<UserIP> IPAddresses;
    IPAddresses.push_back(Addresses->GetAddressFromIndex(0));
    int LikelyIndex, PossIndex, PortIndex;
    for (int j = 0; j < results.data.size(); j++) {
        if (results.data[j].GetKey() == "Possible Attack Port Count") {
            PossIndex = j;
        } else if (results.data[j].GetKey() == "Likely Attack Port Count") {
            LikelyIndex = j;
        } else if (results.data[j].GetKey() == "Port Count") {
            PortIndex = j;
        } else{}
    }

    for (int i = 0; i < Addresses->size(); i++) {
        bool added = false;
        for (int j = 0; j < IPAddresses.size(); ++j) {
            if (Addresses->GetAddressFromIndex(i).getSourceAddress() == IPAddresses[j].getSourceAddress()) {
                IPAddresses[j].AddDestPortCount(Addresses->GetAddressFromIndex(i).getDestinationPort());
                added = true;
            }
        }
        if (!added) {
            IPAddresses.push_back(Addresses->GetAddressFromIndex(i));
        }
    }

    for (int i = 0; i < IPAddresses.size(); i++) {
        if (IPAddresses[i].DestPortToCount->size() >= LikelyPCount) {
            results.data[LikelyIndex].AddValue(IPAddresses[i]);
        }
        else if (IPAddresses[i].DestPortToCount->size() >= PossPCount) {
            results.data[PossIndex].AddValue(IPAddresses[i]);
        }
        else{}

    }
    std::vector<int>* Ports;
    Ports = new std::vector<int>;
    for (int i = 0; i < IPAddresses.size(); i++) {
        for (int j = 0; j < IPAddresses[i].DestPortToCount->size(); j++) {
            if (Ports->size() == 0) {
                Ports->push_back(IPAddresses[i].GetDestPortFromIndex(j).GetKey());
            }
            else {
                bool Added = false;
                for (int g = 0; g < Ports->size(); g++) {
                    if ((*Ports)[g] == IPAddresses[i].GetDestPortFromIndex(j).GetKey()) {
                        Added = true;
                    }
                }
                if (!Added) {
                    Ports->push_back(IPAddresses[i].GetDestPortFromIndex(j).GetKey());
                }
            }
        }
        UserIP temp;
        temp.SetPorts(Ports);

        results.data[PortIndex].AddValue(temp);
    }

    return results;
}
