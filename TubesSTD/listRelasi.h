#ifndef List_RelasiELASI_H_INCLUDED
#define List_RelasiELASI_H_INCLUDED

#include <iostream>
#include "listParent.h"
#include "listChild.h"

using namespace std;
/*
struct infotypeRelasi {
    int noTahanan;
    int usia;
    int durasi;
    float rerata;
};
*/
typedef struct Relasi *relateAddress;

struct Relasi {
    address_Parent lapas;
    address_Child tahanan;
    relateAddress next;
    relateAddress prev;
    //infotypeRelasi info;
};

struct List_Relasi {
    relateAddress first;
    relateAddress last;
};
//adress1 parent, address_Child child
void createList_Relasi(List_Relasi &L);
relateAddress CreateElmRelasi(address_Parent P, address_Child Q);
void insertRelasi(List_Relasi &L, relateAddress R);
void deleteFirstBase(List_Relasi &L, relateAddress &R);
void deleteAfterRelasi(List_Relasi &L, relateAddress Prec, relateAddress &P);
void deleteLastRelasi(List_Relasi &L, relateAddress &R);
void deleteSpesificRelasi(List_Relasi &L, relateAddress &R);
void deleteSpesificRelasi1(List_Relasi &L, relateAddress P, relateAddress Q);
void deleteSpesificRelasi2(List_Relasi &L, relateAddress P, relateAddress Q);
relateAddress findElmRelasi1(List_Relasi &L, address_Parent P, address_Child Q);
relateAddress findElmRelasi2(List_Relasi &L, address_Parent P, address_Child Q);
void printInfoRelasi(List_Relasi L);

#endif // List_RelasiELASI_H_INCLUDED
