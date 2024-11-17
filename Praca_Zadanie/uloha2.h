#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <set>


class Zviera {
public:
    virtual void pozdrav() const = 0;
    virtual ~Zviera() = default;
};


template <typename T>
class ZvieraTemplate : public Zviera {
public:
    void pozdrav() const override {
        std::cout << T::getNazov() << std::endl;
    }
};


class Kacka {
public:
    static const char* getNazov() { return "kačka"; }
};

class Kon {
public:
    static const char* getNazov() { return "kôň"; }
};

class Panda {
public:
    static const char* getNazov() { return "panda"; }
};

class Krava {
public:
    static const char* getNazov() { return "krava"; }
};

class Medved {
public:
    static const char* getNazov() { return "medveď"; }
};

class Macka {
public:
    static const char* getNazov() { return "mačka"; }
};

class Pes {
public:
    static const char* getNazov() { return "pes"; }
};

class Slon {
public:
    static const char* getNazov() { return "slon"; }
};

class Ovca {
public:
    static const char* getNazov() { return "ovca"; }
};

class Koza {
public:
    static const char* getNazov() { return "koza"; }
};

std::vector<std::shared_ptr<Zviera>> vytvorZoznamZvierat();
void zobrazZoznamZvierat(const std::vector<std::shared_ptr<Zviera>>& zvierata);
void vyberZviera();