//
// Created by Brady Bodily on 3/1/17.
//

#include "../Deck.h"
#include <set>
#include "DeckTester.hpp"


void DeckTester::testConstructor(int size, int num, int index, int testCase) {
    printf("Test Case %u", testCase);
    Deck testDeck(size, index, num);
    if (testDeck.deck[1]->m_cardSize != size) {
        printf(" Test failed size is not as specivfied\n");
    }
    if (testDeck.deck[1]->m_numberMax != num) {
        printf(" Test failed max number is not as specified\n");
    }
    if (testDeck.deck.size() != index) {
        printf(" Test failed deck size is not as specified\n");
    }else {printf(" Pass\n");}

}

void DeckTester::testNoDecksAreTheSame(int testCase){
    //Creates Random Deck
    printf("Test Case %u", testCase);
    int size = (std::rand() % 13)+3;
    int cMin = 2*size*size;
    int cMax = 2*cMin;
    int dif = cMax-cMin;
    int bingoNum = std::rand()% dif + cMin;
    int numOfCards = (std::rand() % 997) + 3;
    Deck testDeck(size, numOfCards, bingoNum);

    std::set<int> hash;
    for(int i  = 0; i < numOfCards; i++){
        int createHash = 13;
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                createHash = (createHash * 397) + testDeck.deck[i]->vCard[j][k];
            }
        }
        hash.insert(createHash);
    }
    if(hash.size() == numOfCards){
        printf(" Pass\n");
    }else{printf("There is a Duplicate Card");}



}
