
#include "Result.hpp"
#include <iostream>
void Result::PrintDictionary() {

    for (int i = 0; i < data.size(); i++) {
        if (data[i].Key == "Attack Periods") {
            std::cout << std::endl << std::endl << "Key: " << data[i].Key << std::endl << "Value: ";
            for (int j = 0; j < data[i].Value.size(); j++) {
                for (int g = 0; g < data[i].Value[j].AttackPeriods.size(); g++) {
                    std::cout << std::endl << "       " <<  data[i].Value[j].AttackPeriods[g];
                }
            }
        }
        else if (data[i].Key == "TimeSpan") {
            std::cout << std::endl << std::endl << "Key: " << "TimeSpan" << std::endl;
            std::cout << "Value: " << TimeSpan << std::endl;
        }
        else if(data[i].Key == "Likely Attack Port Count") {
            std::cout << std::endl << std::endl << "Key: " << data[i].Key << std::endl << "Value: ";
            for (int j = 0; j < data[i].Value.size(); j++) {
                std::cout << std::endl << "       " << data[i].Value[j].getSourceAddress();
            }
        }
        else if (data[i].Key == "Possible Attack Port Count") {
            std::cout << std::endl << std::endl << "Key: " << data[i].Key << std::endl << "Value: ";
            for (int j = 0; j < data[i].Value.size(); j++) {
                std::cout << std::endl << "       " << data[i].Value[j].getSourceAddress();
            }
        }
        else if (data[i].Key == "Port Count") {
            std::cout << std::endl << std::endl << "Key: " << data[i].Key << std::endl << "Value: ";
            for (int j = 0; j < data[i].Value[0].Ports->size(); j++) {

                std::cout << std::endl << "       " << data[i].Value[0].GetPortAtIndex(j);
            }
        }
        else {
            std::cout << std::endl << std::endl << "Key: " << data[i].Key << std::endl << "Value: ";
            for (int j = 0; j < data[i].Value.size(); j++) {
                std::cout << std::endl << "       " << data[i].Value[j].getSourceAddress();
            }
        }

    }
}

Result::Result() { data = this->Dictionary::GetData(); }
void Result::AddToKey(std::string key) {}
void Result::Add(KeyValue dataToAdd) { data.push_back(dataToAdd); }