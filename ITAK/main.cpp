
#include <fstream>
#include "Result.hpp"
#include "ITAK.hpp"

int main() {
    bool invalid = true;
    int Time = 0, Attacks = 0, PossAttacks = 0, PortAttacks = 0, PossPortAttacks = 0;
    std::ifstream fin("SampleData.csv");
    if(fin.is_open()){
        printf("File is open\n");
    }
    while (invalid) {
        printf("--DOS Attack Analzer--\n\n");
        printf("Time span in secconds: \n");
        std::cin >> Time;
        printf("How many messages in that time span make an attack: \n");
        std::cin >> Attacks;
        printf("How many messages for the possible attackers (Has to be less than attack): \n");
        std::cin >> PossAttacks;
        if (PossAttacks < Attacks){
            invalid = false;
        } else {
            printf("Dummy, watch list has to be smaller\n");
            main();
        }
    }

    invalid = true;

    while(invalid) {
        printf("\n\n--Port Scanner--\n\n");
        printf("Enter threshold for attack: \n");
        std::cin >> PortAttacks;
        printf("How many port calls puts someone on a watch list? (Must be fewer than  an attack)\n");
        std::cin >> PossPortAttacks;
        if (PossPortAttacks < PortAttacks) {
            invalid = false;
        } else {
            printf("You set it up wrong!\n");
            main();
        }
    }

    ITAK itak(fin, Time, Attacks, PossAttacks, PortAttacks, PossPortAttacks);

    itak.Print();


    return 0;
}
