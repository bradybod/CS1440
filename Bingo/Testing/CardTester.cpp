//
// Created by Brady Bodily on 3/1/17.
//

#include "CardTester.hpp"
#include "../Card.hpp"
#include <sstream>
#include <string>

#include "iomanip"


void CardTester::testDuplicates(int testCase)
{
    printf("Test Case %u", testCase);
    int size = (std::rand() % 13)+3;
  //  printf("size %u\n", size);
    int cMin = 2*size*size;
    int cMax = 2*cMin;
    //printf("cMax %u\n", cMax);

    int dif = cMax-cMin;
    int bingoNum = std::rand()% dif + cMin;
   // printf("bingoNum %u\n", bingoNum);

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
        //printf("%u\n", testCard.m_cardIndex);

    }else {printf(" Pass\n");}

}
