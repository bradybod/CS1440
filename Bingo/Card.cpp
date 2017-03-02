//
// Created by Brady Bodily on 2/27/17.
//

#include "Card.hpp"
#include <iomanip>

Card::Card(int cardSize, int numberMax, int cardIndex):
    m_cardSize(cardSize), m_numberMax(numberMax), m_cardIndex(cardIndex) {
    for (int i = 1; i <= m_numberMax; i++) {
        numbers.push_back(i);
    }
    for (int i = 0; i < m_numberMax; i++) {
        std::vector<int> tmpCard;
        std::random_shuffle(numbers.begin(), numbers.end());
        for (int j = 0; j < m_cardSize; ++j) {
            tmpCard.emplace_back(numbers[j]);
        }
        vCard.emplace_back(tmpCard);
    }

}

void Card::print(std::ostream &out) const {
    out << "Card #" << m_cardIndex+1 << std::endl;
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