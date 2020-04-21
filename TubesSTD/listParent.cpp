#include "listParent.h"

void createListParent(List_Parent &L) {
    L.first = NULL;
}

address_parent CreateElmParent(infotypeParent X){
    address_parent P = new parent;
    P -> info = X;
    P -> next = NULL;
    P -> prev = NULL;
    return P;
}

void insertFirstParent(List_Parent &L, address_parent P){
    if (L.first == NULL) {
        L.first = P;
        P -> next = P;
        P -> prev = P;
    } else {
        P -> next = L.first;
        P -> prev = L.first -> prev;
        L.first -> prev -> next = P;
        L.first -> prev = P;
        L.first = P;
    }
}
void insertAfterParent(List_Parent &L, address_parent Prec, address_parent P){
    P -> next = Prec -> next;
    P -> prev = Prec;
    Prec -> next -> prev = P;
    Prec -> next = P;
}

void insertLastParent(List_Parent &L, address_parent P){
    P -> next = L.first;
    P -> prev = L.first -> prev;
    L.first -> prev -> next = P;
    L.first -> prev = P;
}

void deleteFirstParent(List_Parent &L, address_parent &P){
    if (L.first -> next == L.first) {
        P = L.first;
        P -> next = NULL;
        P -> prev = NULL;
        L.first = NULL;
    } else {
        P = L.first;
        L.first = P -> next;
        L.first -> prev = P -> prev;
        P -> prev -> next = L.first;
        P -> next = NULL;
        P -> prev = NULL;
    }
}

void deleteAfterParent(List_Parent &L, address_parent Prec, address_parent &P){
    P = Prec -> next;
    P -> next -> prev = Prec;
    Prec -> next = P -> next;
    P -> next = NULL;
    P -> prev = NULL;
}

void deleteLastParent(List_Parent &L, address_parent &P) {
    P = L.first -> prev;
    P -> prev -> next = L.first;
    L.first -> prev = P -> prev;
    P -> next = NULL;
    P -> prev = NULL;
}
