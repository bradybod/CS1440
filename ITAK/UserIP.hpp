
#ifndef ITAK_USERIP_HPP
#define ITAK_USERIP_HPP
#include <string>
#include <iostream>
#include "KeyCount.hpp"
#include <vector>

class UserIP {
private:
    int TimeStamp;
    std::string SourceAddress;
    int SourcePort;
    int DestinationPort;
public:
    std::vector<std::string> AttackPeriods;
    UserIP() {
        TimeStamp = 000000;
        SourceAddress = "";
        SourcePort = 000000;
        DestinationPort = 000000;
        TimeStampToCount = new std::vector<KeyCount>;
        TimeStampToCount->push_back(KeyCount(TimeStamp));
        DestPortToCount = new std::vector<KeyCount>;
        DestPortToCount->push_back(KeyCount(DestinationPort));
    }
    std::vector<KeyCount>* TimeStampToCount;
    KeyCount GetTimeStampFromIndex(int index) { return (*TimeStampToCount)[index];}

    std::vector<KeyCount>* DestPortToCount;
    KeyCount GetDestPortFromIndex(int Index) { return (*DestPortToCount)[Index]; }

    UserIP(int timeStamp, std::string srcAddress, int srcPort, int destPort) {
        TimeStamp = timeStamp;
        SourceAddress = srcAddress;
        SourcePort = srcPort;
        DestinationPort = destPort;
        TimeStampToCount = new std::vector<KeyCount>;
        TimeStampToCount->push_back(KeyCount(TimeStamp));
        DestPortToCount = new std::vector<KeyCount>;
        DestPortToCount->push_back(KeyCount(DestinationPort));
    }


    void AddTimeStampCount(int timeStamp) {
        if (TimeStampToCount->size() == 0) {
            KeyCount Time(timeStamp);
            TimeStampToCount->push_back(Time);
        } else {
            for (int i = 0; i < TimeStampToCount->size(); i++) {
                if ((*TimeStampToCount)[i].GetKey() == timeStamp) {
                    (*TimeStampToCount)[i].IncrementCount();
                    return;
                }
            }
            KeyCount Time(timeStamp);
            TimeStampToCount->push_back(Time);
        }
    }

    void AddDestPortCount(int DestPort)
    {
        if (DestPortToCount->size() == 0)
        {
            KeyCount Port(DestPort);
            DestPortToCount->push_back(Port);
        } else {
            for (int i = 0; i < DestPortToCount->size(); i++) {
                if ((*DestPortToCount)[i].GetKey() == DestPort) {
                    (*DestPortToCount)[i].IncrementCount();
                    return;
                }
            }
            KeyCount Port(DestPort);
            DestPortToCount->push_back(Port);
        }
    }


    int getTimeStamp(){return TimeStamp;}
    std::string getSourceAddress(){return SourceAddress;}
    int getSourcePort(){return SourcePort;}
    int getDestinationPort(){return DestinationPort;}
    void setTimeStamp(int stamp){TimeStamp = stamp;}
    void setSourceAddress(std::string address){SourceAddress = address;}
    void setSourcePort(int port){SourcePort = port;}
    void setDestinationPort(int port){DestinationPort = port;}
    std::string PrintIpAddress(){return "IP Address: " + SourceAddress;}
    std::string Print(){return "Time Stamp: " + std::to_string(TimeStamp) + "\n" + "Source Address: " + SourceAddress + "\n"
                          + "Source Port: " + std::to_string(SourcePort) + "\n" + "Destination Port: "
                          + std::to_string(DestinationPort) + "\n";}
    void PrintAddress(){std::cout << "Time Stamp: " + std::to_string(TimeStamp) + "\n" + "Source Address: " + SourceAddress
                                + "\n" + "Source Port: " + std::to_string(SourcePort) + "\n" + "Destination Port: "
                                + std::to_string(DestinationPort) + "\n";}

    std::vector<int>* Ports;

    void SetPorts(std::vector<int>* ports) { Ports = ports; }
    int GetPortAtIndex(int Index) { return (*Ports)[Index]; }
};

#endif //ITAK_UserIP_HPP


