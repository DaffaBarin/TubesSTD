#include <iostream>
#include "listRelasi.h"

using namespace std;

void createList_Relasi(List_Relasi &L){
    L.first = NULL;
    L.last = NULL;
}
relateAddress CreateElmRelasi(address_parent P, address_child Q){
    relateAddress R = new Relasi;
    R -> lapas = P;
    R -> tahanan = Q;
    R -> next = NULL;
    R -> prev = NULL;
    return R;
}
void insertRelasi(List_Relasi &L, relateAddress R){
    if (L.first == NULL) {
        L.first = R;
        L.last = R;
    } else {
        L.last -> next = R;
        L.last = R;
    }
}

void deleteFirstRelasi(List_Relasi &L, relateAddress &R){
    if (L.first != L.last) {
        R = L.first;
        L.first = R -> next;
        R -> next = NULL;
    }else {
        R = L.first;
        L.first = NULL;
        L.last = NULL;
    }
}
void deleteAfterRelasi(List_Relasi &L, relateAddress Prec, relateAddress &R){
    R -> next = Prec -> next;
    Prec -> next = R -> next;
}
void deleteLastRelasi(List_Relasi &L, relateAddress &R){
    relateAddress Q = L.first;
    while (Q -> next -> next != NULL) {
        Q = Q -> next;
    }
    R = Q -> next;
    Q -> next = NULL;
}
void deleteSpesificRelasi(List_Relasi &L, relateAddress &R){

}
relateAddress findElmRelasiParent(List_Relasi &L, address_parent P){

}
relateAddress findElmRelasiChild(List_Relasi &L,address_child Q){

}
void printInfoRelasi(List_Relasi L){

}
