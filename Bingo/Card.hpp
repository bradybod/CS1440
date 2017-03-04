//
// Created by Brady Bodily on 2/27/17.
//

#ifndef BINGO_CARD_HPP
#define BINGO_CARD_HPP
#include <iostream>
#include <vector>

class Card {
public:
    friend class CardTester;
    friend class DeckTester;


    Card(int cardSize, int numberMax, int cardIndex);
    void print(std::ostream& out) const;

private:
    int m_cardSize;
    int m_numberMax;
    int m_cardIndex;
    std::vector<int> numbers;
    std::vector<std::vector<int>> vCard;
};


#endif //BINGO_CARD_HPP
