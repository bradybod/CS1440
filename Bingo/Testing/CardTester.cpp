//
// Created by Brady Bodily on 3/1/17.
//

#include "CardTester.hpp"
#include "../Card.hpp"
#include <sstream>
#include <ostream>
#include <set>
#include "iomanip"
#include "../Deck.h"


void CardTester::testDuplicates(int testCase)
{
    //Creates Random Card
    printf("Test Case %u", testCase);
    int size = (std::rand() % 13)+3;
    int cMin = 2*size*size;
    int cMax = 2*cMin;
    int dif = cMax-cMin;
    int bingoNum = std::rand()% dif + cMin;
    Card testCard(size,bingoNum,0);
    //Creates a set
    std::set<int> set;
    for(int i  = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                set.insert(testCard.vCard[i][j]);
            }
        }
    }
    if(set.size() == size*size){
        printf(" Pass\n");
    }else{printf("There is a Duplicate  in the Card");
        for (int m = 0; m < size; m++) {
            for (int n = 0; n < size; n++) {
                std::cout << "+----";
            }
            std::cout << "+\n";
            for (int n = 0; n < size; n++) {
                std::cout << "|" << std::setw(4) << std::left << testCard.vCard[m][n];
            }
            std::cout << "|\n";
        }
        for (int o = 0; o < size; o++) {
            std::cout << "+----";
        }
        std::cout << "+\n";}
}

void CardTester::testConstructor(int size, int num, int index, int testCase) {
    printf("Test Case %u", testCase);
    Card testCard(size, num, index);
    if (testCard.m_cardSize != size) {
        printf(" TEST FAILED SIZE IS NOT AS SPECIFIED\n");
    }
    if (testCard.m_numberMax != num) {
        printf(" TEST FAILED MAX NUMBER IS NOT AS SPECIFIED\n");
    }
    if (testCard.m_cardIndex != index) {
        printf(" TEST FAILED CARD INDEX IS NOT AS SPECIFIED\n");
    }else {printf(" Pass\n");}

}

