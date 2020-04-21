#include <iostream>

using namespace std;

struct infotypeChild {
    string namaTahanan;
    string IDTahanan;
    int usiaTahanan;
};

typedef struct child *address_Child;

struct child {
    infotypeChild info;
    address_Child next;
};

struct List2 {
    address_Child first;
    address_Child last;
};

void createListChild(List2 &L);
address_Child CreateElmChild(infotypeChild st);
void insertFirstChild(List2 &L, address_Child P);
void insertAfterChild(List2 &L, address_Child Prec, address_Child P);
void insertLastChild(List2 &L, address_Child P);
//void insertSortedChild(List2 &L, infotypeChild X);
void deleteFirstChild(List2 &L, address_Child &P);
void deleteAfterChild(List2 &L, address_Child Prec, address_Child &P);
void deleteLastChild(List2 &L, address_Child &P);
void deleteSpesificChild(List2 &L, string X);
address_Child findElmChild(List2 &L, string X);
void printInfoChild(List2 L);
