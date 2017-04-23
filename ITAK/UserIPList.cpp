//
// Created by Brady Bodily on 4/22/17.
//
#include <string>
#include "UserIPList.hpp"
#include <sstream>
UserIPList::UserIPList(std::ifstream* fin) {
    //std::vector<std::string> values;
    //values.push_back("");values.push_back("");values.push_back("");values.push_back("");
    std::string tempLine;
    while (!fin->eof()) {
        std::getline(*fin, tempLine);
        //std::cout << tempLine << "after getline" << std::endl;
        std::string values[4];
        std::stringstream ss;
        ss.str(tempLine);
        std::string item;
        int i = 0;
        while (std::getline(ss, item, ',') && i < 4) {
            values[i++] = item;
        }
        UserIP *temp = new UserIP(std::stoi(values[0]), values[1], std::stoi(values[2]), std::stoi(values[3]));
        AllIPs.push_back(*temp);


    }
}




void UserIPList::PrintAll() {
    for (int i = 0; i < AllIPs.size(); i++) {
        std::cout << "User Number: " << i + 1 << std::endl;
        AllIPs[i].Print();
        std::cout << std::endl << std::endl;
    }

}

UserIP UserIPList::GetAddressByIP(std::string IP) {
    for (int i = 0; i < AllIPs.size(); i++) {
        if (AllIPs[i].getSourceAddress() == IP) {
            return AllIPs[i];
        }
    }
}

void UserIPList::PrintFromIndex(int index) {
    AllIPs[index].PrintAddress();
}

UserIP UserIPList::GetAddressFromIndex(int index) {
    return AllIPs[index];
}