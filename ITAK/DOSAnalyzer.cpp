
#include "DOSAnalyzer.hpp"
#include "UserIP.hpp"
DOSAnalyzer::DOSAnalyzer(vector<Config>* configs, UserIPList *addresses) : Analyzer() {
    Addresses = addresses;
    for (int i = 0; i < (*configs).size(); i++){
        if ((*configs)[i].GetType() == "Time span"){
            TIMEFRAME = (*configs)[i].GetValue();
        } else if ((*configs)[i].GetType() == "Likely Attack Message Count") {
            likelyMCount = (*configs)[i].GetValue();
        } else if ((*configs)[i].GetType() == "Possible Attack Message Count") {
            possMCount = (*configs)[i].GetValue();
        } else{
            throw invalid_argument("Invalid Config");
        }
    }
}

Result DOSAnalyzer::Run() {
    Result results;
    vector<UserIP> tempValue;
    KeyValue LiklyAttackers("Likely Attack Message Count", tempValue);
    KeyValue PossAttackers("Possible Attack Message Count", tempValue);
    KeyValue AttackPeriods("Attack Periods", tempValue);
    KeyValue timeframe("Timeframe", tempValue);
    results.data.push_back(LiklyAttackers);
    results.data.push_back(PossAttackers);
    results.data.push_back(AttackPeriods);
    results.data.push_back(timeframe);
    vector<UserIP> AllAddressesOrganized;
    AllAddressesOrganized.push_back(Addresses->GetAddressFromIndex(0));
    results.TimeSpan = TIMEFRAME;
    UserIP AttacksAddress;
    for (int i = 0; i < Addresses->size(); i++) {
        bool added = false;
        for (int j = 0; j < AllAddressesOrganized.size(); ++j) {
            if (Addresses->GetAddressFromIndex(i).getSourceAddress() == AllAddressesOrganized[j].getSourceAddress()) {
                AllAddressesOrganized[j].AddTimeStampCount(Addresses->GetAddressFromIndex(i).getTimeStamp());
                added = true;
            }
        }
        if (!added) {
            AllAddressesOrganized.push_back(Addresses->GetAddressFromIndex(i));
        }
    }

    for (int i = 0; i < AllAddressesOrganized.size(); i++) {
        for (int j = 0; j < AllAddressesOrganized[i].TimeStampToCount->size(); j++) {
            int start = AllAddressesOrganized[i].GetTimeStampFromIndex(j).GetKey();
            int end = start + TIMEFRAME;
            int LastIndex = AllAddressesOrganized[i].GetTimeStampFromIndex(AllAddressesOrganized[i].TimeStampToCount->size()-1).GetKey();
            int count = 0;
            int tempIndex = j;
            while (AllAddressesOrganized[i].GetTimeStampFromIndex(tempIndex).GetKey() < end && end <= LastIndex) {
                count += AllAddressesOrganized[i].GetTimeStampFromIndex(tempIndex).GetCount();
                tempIndex++;
            }
            if (count >= likelyMCount) {
                AllAddressesOrganized[i].AttackPeriods.push_back(to_string(start) + " - " + to_string(end));
            }
        }
    }
    int LikelyIndex, PossIndex, PeriodsIndex;
    for (int j = 0; j < results.data.size(); j++) {
        if (results.data[j].GetKey() == "Possible Attack Message Count") {
            PossIndex = j;
        } else if (results.data[j].GetKey() == "Likely Attack Message Count") {
            LikelyIndex = j;
        } else if (results.data[j].GetKey() == "Attack Periods") {
            PeriodsIndex = j;
        } else{

        }
    }


    for (int h = 0; h < AllAddressesOrganized.size(); h++) {
        int count = AllAddressesOrganized[h].AttackPeriods.size();

        if (count >= likelyMCount) {
            results.data[LikelyIndex].AddValue(AllAddressesOrganized[h]);

        }
        else if (count < likelyMCount && count >= possMCount) {
            results.data[PossIndex].AddValue(AllAddressesOrganized[h]);
        }
        else {

        }
    }
    for (int a = 0; a < AllAddressesOrganized.size(); a++) {
        for (int b = 0; b < AllAddressesOrganized[a].AttackPeriods.size(); b++) {
            if (AllAddressesOrganized[a].AttackPeriods[b] != "") {
                AttacksAddress.AttackPeriods.push_back(AllAddressesOrganized[a].AttackPeriods[b]);
            }
        }
    }
    results.data[PeriodsIndex].AddValue(AttacksAddress);

    return results;
}
