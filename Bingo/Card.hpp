//
// Created by Brady Bodily on 2/27/17.
//

#ifndef BINGO_CARD_HPP
#define BINGO_CARD_HPP
#include <iostream>
#include <vector>

class Card {
public:
    Card(int cardSize, int numberMax, int cardIndex);
    void print(std::ostream& out) const;

private:
    int m_cardSize;
    int m_numberMax;
    int m_cardIndex;
    std::vector<int> numbers;
};


#endif //BINGO_CARD_HPP
