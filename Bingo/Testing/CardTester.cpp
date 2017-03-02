//
// Created by Brady Bodily on 3/1/17.
//

#include "CardTester.hpp"
#include "../Card.hpp"

#include "iomanip"


void CardTester::testDuplicates(int testCase)
{
    printf("Test Case %u", testCase);
    int size = (std::rand() % 13)+3;
    int cMax = (2*(2*(size * size)));
    int cMin = (size*size);
    int dif = cMax-cMin;
    int bingoNum = std::rand()% dif + cMin;
    Card testCard(size,bingoNum,0);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    for (int l = 0; l < size; l++) {
                        if (testCard.vCard[i][j] == testCard.vCard[k][l] && !(i == k && j == l)) {
                            printf("CardTester::testDuplicates::There are duplicates on card\n");
                            //Prints card if its bad
                            for (int m = 0; m < size; m++) {
                                for (int m = 0; m < size; m++) {
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
                            std::cout << "+\n";
                        }
                    }
                }
            }
        }
    printf(" Pass\n");
}

void CardTester::testMinimums(int size, int num, int testCase){
    printf("Test Case %u", testCase);
    Card testCard(size,num,0);
    if(testCard.m_isValid){
        printf(" TEST FAILED WITH INVALID NUMBERS\n");
    }else{printf(" Pass\n");}
}

void CardTester::testMaximums(int size, int num, int testCase){
    printf("Test Case %u", testCase);
    Card testCard(size,num,0);
    if(testCard.m_isValid){
        printf(" TEST FAILED WITH INVALID NUMBERS\n");
    }else{printf(" Pass\n");}
}