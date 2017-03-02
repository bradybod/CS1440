//
// Created by Stephen Clyde on 2/20/17.
//

#include <iostream>
#include <ctime>

#include "MenuOptionTester.h"
#include "MenuTester.h"
#include "CardTester.hpp"

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
    printf("\nTest Suite: CardTester::testMinimums\n");
    cardTester.testMinimums(0,15,1);
    cardTester.testMinimums(1,14,2);
    cardTester.testMinimums(2,13,3);
    printf("\nTest Suite: CardTester::testMaximums\n");
    cardTester.testMinimums(4,15,1);
    cardTester.testMinimums(15,40,2);
    cardTester.testMinimums(16,42,3);
}