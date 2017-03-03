//
// Created by Brady Bodily on 2/27/17.
//

#include "Card.hpp"
#include <iomanip>

Card::Card(int cardSize, int numberMax, int cardIndex):
    m_cardSize(cardSize), m_numberMax(numberMax), m_cardIndex(cardIndex), m_isValid(false){
        for (int i = 1; i <+ m_numberMax; i++) {
            numbers.push_back(i);
        }
        std::random_shuffle(numbers.begin(), numbers.end());
        int count = 0;
        for (int i = 0; i < m_numberMax; i++) {
            std::vector<int> tmpCard;
            for (int j = 0; j < m_cardSize; ++j) {
                tmpCard.emplace_back(numbers[count]);
                count++;
            }
            vCard.emplace_back(tmpCard);
            m_isValid = true;
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

