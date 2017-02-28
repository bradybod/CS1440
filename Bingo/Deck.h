//
// Created by Stephen Clyde on 2/16/17.
//

#ifndef BINGO_DECK_H
#define BINGO_DECK_H

#include <ostream>
#include <vector>
#include "Card.hpp"

// TODO: Extend this definition as you see fit

class Deck {

public:
    Deck(int cardSize, int cardCount, int numberMax);
    ~Deck();

    void print(std::ostream& out) const;
    void print(std::ostream& out, int cardIndex) const;

private:
    std::vector<Card*> deck;
    int m_cardSize = 0;
    int m_numberMax = 0;
    int m_cardCount = 0;
};

#endif //BINGO_DECK_H
