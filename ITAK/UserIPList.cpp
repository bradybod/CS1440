//
// Created by Brady Bodily on 4/22/17.
//
#include <string>
#include "UserIPList.hpp"
UserIPList::UserIPList(std::ifstream& fin) {
    std::vector<std::string> values;
    //values.push_back("");values.push_back("");values.push_back("");values.push_back("");
    std::string tempLine;
    while(!fin.eof()) {
        for (int i = 0; i <= 3; i++) {
            getline(fin, tempLine, ',');
            values[i] = tempLine;
        }
        //values[] = tempLine;
        //getline(fin, tempLine);
        UserIP temp(stoi(values[0]), values[1], stoi(values[2]), stoi(values[3]));
        AllIPs.push_back(temp);

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