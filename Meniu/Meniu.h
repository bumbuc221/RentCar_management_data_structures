
#include "../Masini/Masini.cpp"
#include "../Masini/Standard.cpp"
#include "../Masini/Offroad.cpp"
#include "../Masini/Premium.cpp"
#include "../Structuri/RBTree.h"
#include "../Structuri/HashMap.h"
#include "../Structuri/RBTreeInt.h"
#include <fstream>
#ifndef PROIECT_MENIU_H
#define PROIECT_MENIU_H


class Meniu {
    int l;
    HashMap *h;
    RBTree *t;
    RBTreeInt *in;
public:
    static int nr;
    Meniu();
    int lungime();
    Standard* citire_standard(char *d);
    Offroad* citire_offroad(char*d);
    Premium* citire_premium(char *d);
    Inchirieri* citire_inchiriere(char* linie);
    void citireFisierInchirieri();
    void scriereFisierInchirieri();
    void citireFisier();
    void scriereFisier();
    HashMap* get_HasMap()
    {
        return h;
    }
    RBTree* get_RBTree()
    {
        return t;
    }
    RBTreeInt* get_Rb()
    {
        return in;
    }
};


#endif //PROIECT_MENIU_H
