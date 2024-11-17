#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> multiply(const vector<int>& num, int x) {
    vector<int> result;
    int carry = 0;

    for (int digit : num) {
        int prod = digit * x + carry;
        result.push_back(prod % 10);
        carry = prod / 10;
    }

    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }

    return result;
}


vector<int> vypocitajFaktorial(int cislo) {
    vector<int> result = { 1 }; 

    for (int i = 2; i <= cislo; ++i) {
        result = multiply(result, i);
    }

    return result;
}


void printNumber(const vector<int>& num) {
    for (auto it = num.rbegin(); it != num.rend(); ++it) {
        cout << *it;
    }
    cout << endl;
}


void hlavnyProgram() {
    while (true) {
        cout << "Príliš veľké čísla môžu spôsobiť chybu v dôsledku rekurzie \n";
        cout << "Zadajte celé kladné číslo (alebo 'koniec' na ukončenie): ";
        string vstup;
        cin >> vstup;

        if (vstup == "koniec" || vstup == "KONIEC") {
            cout << "Program sa ukončil. Ďakujeme za použitie!" << endl;
            break;
        }

        bool jeCislo = true;
        for (char znak : vstup) {
            if (!isdigit(znak)) {
                jeCislo = false;
                break;
            }
        }

        if (!jeCislo) {
            cout << "Neplatný vstup! Prosím, zadajte celé číslo." << endl;
            continue;
        }

        int cislo = stoi(vstup);

        if (cislo < 0) {
            cout << "Prosím, zadajte kladné číslo." << endl;
        }
        else {
            vector<int> vysledok = vypocitajFaktorial(cislo);
            cout << "Faktoriál čísla " << cislo << " je ";
            printNumber(vysledok);
        }
    }
}
