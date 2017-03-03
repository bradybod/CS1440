//
// Created by Brady Bodily on 3/1/17.
//

#include "DeckTester.hpp"
#include "../Deck.h"
#include "../Card.hpp"
#include <set>


void DeckTester::testConstructor(int size, int num, int index, int testCase) {
    printf("Test Case %u", testCase);
    Deck testDeck(size, index, num);
    if (testDeck.m_cardSize != size) {
        printf(" TEST FAILED SIZE IS NOT AS SPECIFIED\n");
    }
    if (testDeck.m_numberMax != num) {
        printf(" TEST FAILED MAX NUMBER IS NOT AS SPECIFIED\n");
    }
    if (testDeck.deck.size()!= index) {
        printf(" TEST FAILED CARD INDEX IS NOT AS SPECIFIED\n");
    }else {printf(" Pass\n");}

}

void DeckTester::testNoDecksAreTheSame(int testCase){
    printf("Test Case %u", testCase);
    int size = (std::rand() % 13)+3;
    //  printf("size %u\n", size);
    int cMin = 2*size*size;
    int cMax = 2*cMin;
    //printf("cMax %u\n", cMax);
    int dif = cMax-cMin;
    int bingoNum = std::rand()% dif + cMin;
    int numOfCards = (std::rand() % 997) + 3;
    // printf("bingoNum %u\n", bingoNum);
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
