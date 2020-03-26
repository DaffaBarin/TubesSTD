#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED

#include <iostream>
#include "listParent.h"
#include "listChild.h"

using namespace std;

struct infotypeBase {
    int noTahanan;
    int usia;
    int durasi;
    float rerata;
};

typedef struct Base *relateAddress;

struct Base {
    address1 lapas;
    address2 tahanan;
    relateAddress next;
    relateAddress prev;
    infotypeBase info;
};

struct ListBase {
    relateAddress first;
    relateAddress last;
};
//adress1 parent, address2 child
void createListBase(ListBase &L);
relateAddress CreateElmBase(address1 P, address2 Q);
void insertBase(ListBase &L, relateAddress R);
void deleteFirstBase(ListBase &L, relateAddress &R);
void deleteAfterBase(ListBase &L, relateAddress Prec, relateAddress &P);
void deleteLastBase(ListBase &L, relateAddress &R);
void DeleteSpesificBase(ListBase &L, relateAddress &R);
void deleteListSpesificBase1(ListBase &L, relateAddress P, relateAddress Q);
void deleteListSpesificBase2(ListBase &L, relateAddress P, relateAddress Q);
relateAddress findElmBase1(ListBase &L, address1 P, address2 Q);
relateAddress findElmBase2(ListBase &L, address1 P, address2 Q);
void printInfoBase(ListBase L);

float nilaiRerataUsia(ListBase L);

#endif // LISTRELASI_H_INCLUDED
