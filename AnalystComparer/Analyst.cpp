//
// Created by Brady Bodily on 2/3/17.
//

#include <string>
#include <vector>

#include "Analyst.hpp"

Analyst::Analyst(std::string name, std::string initials, int days, int seedMoney) :
        m_name(name),
        m_initials(initials),
        m_history(days, seedMoney)
{}
std::string Analyst::getName() {
    return m_name;
}

std::string Analyst::getInitials() {
    return m_initials;
}

std::vector<std::string> Analyst::getStocks() {
    std::vector<PurchaseSale*> history = m_history.getHistory();
    std::vector<std::string> stocks;

    for (PurchaseSale* i : history) stocks.push_back(i->getSymbol());

    return stocks;
}

int Analyst::getDays() {
    return m_history.getNumDays();
}

int Analyst::getSeedMoney() {
    return m_history.getSeedMoney();
}

double Analyst::computeTLPD() {
    double totalLoss = m_history.compute();
    if (m_history.getNumDays() != 0) return (totalLoss / m_history.getNumDays()) / 100.00;
    else return 0.0;
}


  //  return (totalLoss / ) / 100.00;
}
