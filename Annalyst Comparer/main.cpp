#define _USE_MATH_DEFINES
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>


#include "TestCases.hpp"

std:: vector<int> vVector(int size) {
    std::vector<int> vNewVector;

    for (int i = 0; i < size; i++){
        vNewVector.push_back(unsigned(rand() % size)+1);
    }
    return vNewVector;

}
SortStats bubbleSort(std::vector<int>& myVector) {
    //start timer
    SortStats bubbleS = {0, 0, 0};
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    bool swapp = true;
    while (swapp) {
        swapp = false;
        for (unsigned int i = 0; i < myVector.size() - 1; i++) {
            bubbleS.compareCount++;
            if (myVector.at(i) > myVector.at(i + 1)) {
                std::swap(myVector[i], myVector[i + 1]);
                bubbleS.swapCount++;
                swapp = true;
            }
        }
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = end - start;
    bubbleS.time = time.count();
    return bubbleS;
}

SortStats selectionSort(std::vector<int>& myVector) {
    SortStats selectS = {0, 0, 0};
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    int minimumPosition = 0;
    for (unsigned int start = 0; start < myVector.size() - 1; start++) {
        minimumPosition = start;
        for (unsigned int scanPos = start + 1; scanPos < myVector.size(); scanPos++) {
            selectS.compareCount++;
            if (myVector.at(minimumPosition) > myVector.at(scanPos)) {
                minimumPosition = scanPos;
            }
        }
        if (minimumPosition != start) {
            std::swap(myVector[minimumPosition], myVector[start]);
            selectS.swapCount++;
        }
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = end - start;
    selectS.time = time.count();
    return selectS;
}

// ------------------------------------------------------------------
//
// Run the test cases to help verify the code is correct.
//
// ------------------------------------------------------------------


void runTestCases() {
	executeTest(testCase1, bubbleSort, "Bubble Sort: 10 items");
	executeTest(testCase2, bubbleSort, "Bubble Sort: 500 items");
	executeTest(testCase3, bubbleSort, "Bubble Sort: 100 to 1000 items");

	executeTest(testCase1, selectionSort, "Selection Sort: 10 items");
	executeTest(testCase2, selectionSort, "Selection Sort: 500 items");
	executeTest(testCase3, selectionSort, "Selection Sort: 100 to 1000 items");

	executeTest(testCaseCompare, bubbleSort, selectionSort, "Sort Compare Test");

}



int main(){
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	runTestCases();
    for(int x = 100; x <= 1000; x+=100){
        std::vector<int> vBubbleVector = vVector(x);
        std::vector<int> vSelectionVector = vVector(x);
        SortStats bubbleStats = bubbleSort(vBubbleVector);
        SortStats selectionStats = selectionSort(vSelectionVector);
        printf("\n      --Timing Results--\n");
        printf("Number of Items      : %d \n", x);
        printf("Bubble Sort Time     : %f \n", bubbleStats.time);
        printf("Selection Sort Time  : %f \n", selectionStats.time);
    }

	return 0;
}
