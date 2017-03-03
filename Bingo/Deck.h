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
    friend class DeckTester;
    Deck(int cardSize, int cardCount, int numberMax);
    ~Deck();

    void print(std::ostream& out) const;
    void print(std::ostream& out, int cardIndex) const;

private:
    std::vector<Card*> deck;
    int m_cardSize;
    int m_numberMax;
    int m_cardCount;
};

#endif //BINGO_DECK_H
