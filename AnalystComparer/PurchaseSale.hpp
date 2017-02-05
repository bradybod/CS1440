//
// Created by Brady Bodily on 2/3/17.
//

#ifndef ANALYSTCOMPARER_PURCHASESALES_HPP
#define ANALYSTCOMPARER_PURCHASESALES_HPP
#include <fstream>
#include <string>

class PurchaseSale {
public:
    PurchaseSale(std::string symbol, int quantity, int purchaseTime,
                 int purchasePrice, int purchaseFee, int saleTime, int salePrice, int saleFee);
    double computePL();
    std::string getSymbol();
    int getPTime();
    int getSTime();
private:
    std::string m_symbol;

    int m_purchasePrice;
    int m_saleTime;
    int m_quantity;
    int m_purchaseTime;
    int m_salePrice;
    int m_saleFee;
    int m_purchaseFee;

};

#endif //ANALYSTCOMPARER_PURCHASESALES_HPP
