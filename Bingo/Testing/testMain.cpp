//
// Created by Stephen Clyde on 2/20/17.
//

#include <iostream>
#include <ctime>

#include "MenuOptionTester.h"
#include "MenuTester.h"
#include "CardTester.hpp"
#include "DeckTester.hpp"

int main()
{

    // Initialize the random number generator
    unsigned int seed = (unsigned int) time(NULL);
    srand(seed);

    // TODO: Test your components

    MenuOptionTester menuOptionTester;
    menuOptionTester.testConstructorAndGetter();

    MenuTester menuTester;
    menuTester.testConstructorAndGetter();

    CardTester cardTester;
    printf("\nTest Suite: CardTester::testDuplicates\n");
    cardTester.testDuplicates(1);
    cardTester.testDuplicates(2);
    cardTester.testDuplicates(3);

    printf("\nTest Suite: CardTester::testConstructor\n");
    cardTester.testConstructor(15, 400, 3, 1);
    cardTester.testConstructor(10, 550, 10, 2);
    cardTester.testConstructor(9, 300, 100, 3);

    DeckTester deckTester;
    printf("\nTest Suite: DeckTester::testConstructor\n");
    deckTester.testConstructor(3, 18, 3, 1);
    deckTester.testConstructor(15, 900, 1000, 2);
    deckTester.testConstructor(8, 100, 3, 3);

    printf("\nTest Suite: DeckTester::testNoDecksAreTheSame\n");
    deckTester.testNoDecksAreTheSame(1);
    deckTester.testNoDecksAreTheSame(2);
    deckTester.testNoDecksAreTheSame(3);

}