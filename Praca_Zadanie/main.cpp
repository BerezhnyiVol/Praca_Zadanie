#include <iostream>
#include "uloha1.h"
#include "uloha2.h"

using namespace std;

int main() {
    int vyber;
    cout << "Vyberte úlohu na spustenie:\n1. Factorial\n2. Výber zvierat\nZadajte 1 alebo 2: ";
    cin >> vyber;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //aby pracoval getline

    if (vyber == 1) {
        hlavnyProgram();
    }
    else if (vyber == 2) {
        vyberZviera();

    }
    else {
        cout << "Neplatná voľba!" << endl;
    }

    return 0;
}