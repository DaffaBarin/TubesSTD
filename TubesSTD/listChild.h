#include <iostream>
#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define First(L) ((L).First)
using namespace std;

struct infotypeChild {
    string namaTahanan;
    string IDTahanan;
    int usiaTahanan;
};

typedef struct child *address2;

struct child {
    infotypeChild info;
    address2 next;
};

struct List2 {
    address2 first;
    address2 last;
};

void createListChild(List2 &L);
address2 CreateElmChild(infotypeChild st);
void insertFirstChild(List2 &L, address2 P);
void insertAfterChild(List2 &L, address2 Prec, address2 P);
void insertLastChild(List2 &L, address2 P);
void insertSortChild(List2 &L, infotypeChild st);
void deleteFirstChild(List2 &L, address2 &P);
void deleteAfterChild(List2 &L, address2 Prec, address2 &P);
void deleteLastChild(List2 &L, address2 &P);
void deleteSpesificChild(List2 &L, string X);
address2 findElmChild(List2 &L, string X);
void printInfoChild(List2 L);
