#include "uloha2.h"
#include <cctype> 

std::vector<std::shared_ptr<Zviera>> vytvorZoznamZvierat() {
    return {
        std::make_shared<ZvieraTemplate<Kacka>>(),
        std::make_shared<ZvieraTemplate<Kon>>(),
        std::make_shared<ZvieraTemplate<Panda>>(),
        std::make_shared<ZvieraTemplate<Krava>>(),
        std::make_shared<ZvieraTemplate<Medved>>(),
        std::make_shared<ZvieraTemplate<Macka>>(),
        std::make_shared<ZvieraTemplate<Pes>>(),
        std::make_shared<ZvieraTemplate<Slon>>(),
        std::make_shared<ZvieraTemplate<Ovca>>(),
        std::make_shared<ZvieraTemplate<Koza>>()
    };
}

void zobrazZoznamZvierat(const std::vector<std::shared_ptr<Zviera>>& zvierata) {
    std::cout << "Prosím zvoľte si zo zoznamu zvierat, číslo voľby oddeľte čiarkou:" << std::endl;
    for (size_t i = 0; i < zvierata.size(); ++i) {
        std::cout << i + 1 << ". ";
        zvierata[i]->pozdrav();
    }
}


bool jeCislo(const std::string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}


bool spracujVyber(const std::string& volba, const std::vector<std::shared_ptr<Zviera>>& zvierata,
    std::set<int>& vybrateZviera, std::vector<int>& indexy) {
    if (!jeCislo(volba)) { 
        std::cout << "Chyba: '" << volba << "' nie je platné číslo. Prosím, zadajte len čísla." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    int vyber = std::stoi(volba) - 1;

    if (vybrateZviera.count(vyber) > 0) {
        std::cout << "Chyba: Zviera s číslom " << vyber + 1 << " ste už vybrali." << std::endl;
        return false;
    }
    if (vyber >= 0 && vyber < zvierata.size()) {
        vybrateZviera.insert(vyber);
        indexy.push_back(vyber);
        return true;
    }
    else {
        std::cout << "Neplatná voľba: " << vyber + 1 << std::endl;
        return false;
    }
}

void vyberZviera() {
    auto zvierata = vytvorZoznamZvierat();
    zobrazZoznamZvierat(zvierata);

    std::cout << "Vaše voľby (oddeľte čiarkou): ";
    std::string volby;
    std::getline(std::cin, volby);

    std::set<int> vybrateZviera;
    std::vector<int> indexy;
    size_t pozicia = 0;

   
    while ((pozicia = volby.find(',')) != std::string::npos) {
        std::string volba = volby.substr(0, pozicia);
        spracujVyber(volba, zvierata, vybrateZviera, indexy);
        volby.erase(0, pozicia + 1);
    }

    
    if (!volby.empty()) {
        spracujVyber(volby, zvierata, vybrateZviera, indexy);
    }

    
    std::cout << "Zvolili ste si nasledovné zvieratá:" << std::endl;
    for (size_t i = 0; i < indexy.size(); ++i) {
        std::cout << i + 1 << ". Ja som ";
        zvierata[indexy[i]]->pozdrav();
    }
}
