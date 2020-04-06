#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED

#include <iostream>
#include "listParent.h"
#include "listChild.h"

using namespace std;

struct infotypeRelasi {
    int noTahanan;
    int usia;
    int durasi;
    float rerata;
};

typedef struct Relasi *relateAddress;

struct Relasi {
    address1 lapas;
    address2 tahanan;
    relateAddress next;
    relateAddress prev;
    infotypeRelasi info;
};

struct ListR {
    relateAddress first;
    relateAddress last;
};
//adress1 parent, address2 child
void createListR(ListR &L);
relateAddress CreateElmRelasi(address1 P, address2 Q);
void insertRelasi(ListR &L, relateAddress R);
void deleteFirstBase(ListR &L, relateAddress &R);
void deleteAfterRelasi(ListR &L, relateAddress Prec, relateAddress &P);
void deleteLastRelasi(ListR &L, relateAddress &R);
void deleteSpesificRelasi(ListR &L, relateAddress &R);
void deleteSpesificRelasi1(ListR &L, relateAddress P, relateAddress Q);
void deleteSpesificRelasi2(ListR &L, relateAddress P, relateAddress Q);
relateAddress findElmRelasi1(ListR &L, address1 P, address2 Q);
relateAddress findElmRelasi2(ListR &L, address1 P, address2 Q);
void printInfoRelasi(ListR L);

#endif // LISTRELASI_H_INCLUDED
