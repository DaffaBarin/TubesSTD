#include "listChild.h"

void createListChild(List_Child &L){
    L.first = NULL;
}

address_child CreateElmChild(infotypeChild X){
    address_child P = new child;
    P -> info = X;
    P -> next = NULL;
    return P;
}

void insertFirstChild(List_Child &L, address_child P){
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P -> next = L.first;
        L.first = P;
    }
}

void insertAfterChild(List_Child &L, address_child Prec, address_child P){
    P -> next = Prec -> next;
    Prec -> next = P;
}

void insertLastChild(List_Child &L, address_child P){
    if (L.first == NULL){
        insertLastChild(L,P);
    }else {
        L.last -> next = P;
        L.last = P;
    }
}

void insertSortedChild(List_Child &L, infotypeChild X){
    address_child P = L.first;
//    if ()
}
void deleteFirstChild(List_Child &L, address_child &P){
}
void deleteAfterChild(List_Child &L, address_child Prec, address_child &P){
}
void deleteLastChild(List_Child &L, address_child &P){
}
void deleteSpesificChild(List_Child &L, string X){
}
address_child findElmChild(List_Child &L, string X){
}
void printInfoChild(List_Child L){
}
