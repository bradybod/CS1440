//
// Created by Brady Bodily on 4/22/17.
//

#ifndef ITAK_USERIPLIST_HPP
#define ITAK_USERIPLIST_HPP

#include "UserIP.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class UserIPList {
private:
    std::vector<UserIP> AllIPs;

public:
    UserIPList(std::ifstream& fin);
    void PrintFromIndex(int index);
    UserIP GetAddressFromIndex(int index);
    UserIP GetAddressByIP(std::string IP);
    void PrintAll();
    int size(){return AllIPs.size();};

};

#endif //ITAK_USERIPLIST_HPP
