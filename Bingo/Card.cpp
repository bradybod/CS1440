//
// Created by Brady Bodily on 2/27/17.
//

#include "Card.hpp"
#include <vector>
#include <algorithm>

Card::Card(int cardSize, int numberMax, int cardIndex):
    m_cardSize(cardSize), m_numberMax(numberMax), m_cardIndex(cardIndex)
{

    std::vector<std::vector<int>> vCard;
    for(int i = 0; i < m_numberMax; i++){
        for(int i = 1; i < m_numberMax; i++){
            numbers.push_back(i);
        }
        std::random_shuffle(numbers.begin(), numbers.end());
        vCard.emplace_back();
        for (int j = 0; j < m_cardSize; ++j) {
            vCard[i].push_back(numbers[i]);
            numbers.erase();
        }
    }
}

void Card::print(std::ostream &out) const {


}