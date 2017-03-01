//
// Created by Brady Bodily on 2/27/17.
//

#include "Card.hpp"
#include <vector>
#include <algorithm>
#include <iomanip>

Card::Card(int cardSize, int numberMax, int cardIndex):
    m_cardSize(cardSize), m_numberMax(numberMax), m_cardIndex(cardIndex)
{

   // std::vector<std::vector<int>> vCard;
    for(int i = 1; i < m_numberMax; i++){
        numbers.push_back(i);
    }
    for(int i = 0; i < m_numberMax; i++){
        std::random_shuffle(numbers.begin(), numbers.end());
        for (int j = 0; j < m_cardSize; ++j) {
            vCard[i].emplace_back(numbers[i]);
            numbers.erase(numbers.begin() + j);
        }

   }
}

void Card::print(std::ostream &out) const {
    out << "Card #" << m_cardIndex << std::endl;
    for (int j = 0; j < m_cardSize; j++) {
        for (int i = 0; i < m_cardSize; i++) {
            out << "+----";
        }
        out << "+\n";
        for (int i = 0; i < m_cardSize; i++) {
            out << "|" << std::setw(4) << std::left << vCard[j][i];
        }
        out << "|\n";
    }
    for (int i = 0; i < m_cardSize; i++){
        out << "+----";
    }
    out << "+\n";
}
