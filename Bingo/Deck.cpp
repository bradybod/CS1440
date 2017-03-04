//
// Created by Stephen Clyde on 2/16/17.
//

#include "Deck.h"

Deck::Deck(int cardSize, int cardCount, int numberMax)
        : m_cardSize(cardSize), m_cardCount(cardCount), m_numberMax(numberMax)
{
    // TODO: Implement
    for(int i = 0; i < m_cardCount; i++){
        Card* pCard = new Card(cardSize, numberMax, i);
        deck.push_back(pCard);
    }
}

Deck::~Deck()
{
    // TODO: Implement
    for(int i = 0; i < deck.size(); i++){
        delete deck[i];
        deck[i]=nullptr;
    }
//    delete [] deck;
}

void Deck::print(std::ostream& out) const
{
    // TODO: Implement
    for(int i = 0; i < m_cardCount; i++){
        deck[i]->print(out);
    }
}

void Deck::print(std::ostream& out, int cardIndex) const
{
    // TODO: Implement
    deck[cardIndex - 1]->print(out);

}





