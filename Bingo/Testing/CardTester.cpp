//
// Created by Brady Bodily on 3/1/17.
//

#include "CardTester.hpp"
#include "../Card.hpp"

#include "iomanip"

void CardTester::testDuplicates()
{
    int size = (std::rand() % 13)+3;
    //printf("%u\n", size);
    int cMax = (2*(2*(size * size)));
    int cMin = (size*size);
    int dif = cMax-cMin;
    int bingoNum = std::rand()% dif + cMin;
    //printf("%u\n", bingoNum);
    Card testCard(size,bingoNum,0);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    for (int l = 0; l < size; l++) {
                        if (testCard.vCard[i][j] == testCard.vCard[k][l] && !(i == k && j == l)) {
                            printf("CardTester::testDuplicates::There are duplicates on card\n");
                            for (int m = 0; m < size; m++) {
                                for (int i = 0; i < size; i++) {
                                    std::cout << "+----";
                                }
                                std::cout << "+\n";
                                for (int i = 0; i < size; i++) {
                                    std::cout << "|" << std::setw(4) << std::left << testCard.vCard[j][i];
                                }
                                std::cout << "|\n";
                            }
                            for (int i = 0; i < size; i++) {
                                std::cout << "+----";
                            }
                            std::cout << "+\n";
                        }
                    }
                }
            }
        }
    printf("Test Case 1 Pass\n");

}