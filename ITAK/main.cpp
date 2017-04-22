#include <iostream>
#include <string>
#include "Result.hpp"
#include "UserIPList.hpp"
#include "ITAK.hpp"
using namespace std;


int main() {
    bool invalid = true;
    int Time, Attacks, PossAttacks, PortAttacks, PossPortAttacks;
    ifstream fin("SampleData.csv");
    while (invalid) {
        printf("--DOS Attack Analzer--\n\n");
        printf("Time span in secconds: \n");
        cin >> Time;
        printf("How many messages in that time span make an attack: \n");
        cin >> Attacks;
        printf("How many messages for the possible attackers (Has to be less than attack): \n");
        cin >> PossAttacks;
        if (PossAttacks < Attacks){
            invalid = false;
        } else {
            cout << "Invalid Configurations, limit should be greater than watch list value" << endl;
        }
    }

    invalid = true;

    while(invalid) {
        printf("\n\n--Port Scanner--\n\n");
        printf("Enter threshold for attack: \n");
        cin >> PortAttacks;
        cout << "How many port calls puts someone on a watch list? (Must be fewer than  an attack)" << endl;
        cin >> PossPortAttacks;
        if (PossPortAttacks < PortAttacks) {
            invalid = false;
        } else {
            printf("You set it up wrong!\n");
        }
    }

    ITAK itak(fin, Time, Attacks, PossAttacks, PortAttacks, PossPortAttacks);

    itak.Print();


    return 0;
}
