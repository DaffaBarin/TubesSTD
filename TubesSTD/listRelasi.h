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

typedef struct Base *connect;

struct Base {
    address1 lapas;
    address2 tahanan;
    connect next;
    connect prev;
    infotypeBase info;
};

struct ListBase {
    connect first;
    connect last;
};
//adress1 parent, address2 child
void createListBase(ListBase &L);
connect CreateElmBase(address1 P, address2 Q);
void insertBase(ListBase &L, connect R);
void deleteFirstBase(ListBase &L, connect &R);
void deleteAfterBase(ListBase &L, connect Prec, connect &P);
void deleteLastBase(ListBase &L, connect &R);
void DeleteSpesificBase(ListBase &L, connect &R);
void deleteListSpesificBase1(ListBase &L, connect P, connect Q);
void deleteListSpesificBase2(ListBase &L, connect P, connect Q);
connect findElmBase1(ListBase &L, address1 P, address2 Q);
connect findElmBase2(ListBase &L, address1 P, address2 Q);
void printInfoBase(ListBase L);

float nilaiRerataUsia(ListBase L);

#endif // LISTRELASI_H_INCLUDED
