#ifndef List_RelasiELASI_H_INCLUDED
#define List_RelasiELASI_H_INCLUDED

#include <iostream>
#include "listParent.h"
#include "listChild.h"

using namespace std;

typedef struct Relasi *relateAddress;

struct Relasi {
    address_parent lapas;
    address_child tahanan;
    relateAddress next;
    relateAddress prev;
};

struct List_Relasi {
    relateAddress first;
    relateAddress last;
};

void createListRelasi(List_Relasi &L);
relateAddress CreateElmRelasi(address_parent P, address_child Q);
void insertRelasi(List_Relasi &L, relateAddress R);
void deleteFirstRelasi(List_Relasi &L, relateAddress &R);
void deleteAfterRelasi(List_Relasi &L, relateAddress Prec, relateAddress &R);
void deleteLastRelasi(List_Relasi &L, relateAddress &R);
void deleteSpesificRelasi(List_Relasi &L, string out);
relateAddress findElmRelasiParent(List_Relasi &L, address_parent P);
relateAddress findElmRelasiChild(List_Relasi &L,address_child Q);
void printInfoRelasi(List_Relasi L);

#endif // List_RelasiELASI_H_INCLUDED
