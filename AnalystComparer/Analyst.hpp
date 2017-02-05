//
// Created by Brady Bodily on 2/3/17.
//

#ifndef ANALYSTCOMPARER_ANALYST_HPP
#define ANALYSTCOMPARER_ANALYST_HPP

#include <string>
#include <vector>

#include "History.hpp"

class Analyst {
private:
    std::string m_name;
    std::string m_initials;
    History m_history;

public:
    Analyst(std::string name, std::string initials, int days, int seedMoney);
    std::string getName();
    std::string getInitials();
    std::vector<std::string> getStocks();
    double computeTLPD();
    int getDays();
    int getSeedMoney();
   };


#endif //ANALYSTCOMPARER_ANALYST_HPP
