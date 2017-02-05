//
// Created by Brady Bodily on 2/3/17.
//

#ifndef ANALYSTCOMPARER_HISTORY_HPP
#define ANALYSTCOMPARER_HISTORY_HPP

#include <fstream>
#include <vector>

#include "PurchaseSale.hpp"

class History {

private:
    int m_numDays;
    std::vector<PurchaseSale*> m_history;
    int m_seedMoney;
public:
    History(int days, int seedMoney);
    int getNumDays();
    void newPurchaseSale(std::string symbol, int quantity, int purchaseTime, int purchasePrice, int purchaseFee,
                         int saleTime, int salePrice, int saleFee);
    int getSeedMoney();
    std::vector<PurchaseSale*> getHistory();
    double compute();

};


#endif //ANALYSTCOMPARER_HISTORY_HPP
