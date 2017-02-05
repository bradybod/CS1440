//
// Created by Brady Bodily on 2/3/17.
//

#include "History.hpp"


History::History(int days, int seedMoney) :
        m_numDays(days),
        m_seedMoney(seedMoney)
{
    m_history = std::vector<PurchaseSale*>();
}

void History::newPurchaseSale(std::string symbol, int quantity, int purchaseTime,
                              int purchasePrice, int purchaseFee, int saleTime, int salePrice, int saleFee) {
    m_history.push_back(new PurchaseSale(symbol, quantity, purchaseTime, purchasePrice,
                                         purchaseFee, saleTime, salePrice, saleFee));
}
int History::getNumDays() {
    return m_numDays;
}

int History::getSeedMoney() {
    return m_seedMoney;
}

std::vector<PurchaseSale*> History::getHistory() {
    return m_history;
}

double History::compute() {
    double tpl = 0;

    for (PurchaseSale* i : m_history) tpl += i->computePL();

    return tpl;
}

