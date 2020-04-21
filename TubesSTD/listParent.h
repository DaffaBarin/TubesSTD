#include <iostream>


using namespace std;

struct infotypeParent {
    string namaPenjara;
    string IDPenjara;
    int luasPenjara;
};

typedef struct parent *address_parent;

struct parent {
    infotypeParent info;
    address_parent next;
    address_parent prev;
};

struct List_Parent {
    address_parent first;
};

void createListParent(List_Parent &L);
address_parent CreateElmParent(infotypeParent X);
void insertFirstParent(List_Parent &L, address_parent P);
void insertAfterParent(List_Parent &L, address_parent Prec, address_parent P);
void insertLastParent(List_Parent &L, address_parent P);
//void insertSortedParent(List_Parent &L, infotypeParent X);
void deleteFirstParent(List_Parent &L, address_parent &P);
void deleteAfterParent(List_Parent &L, address_parent Prec, address_parent &P);
void deleteLastParent(List_Parent &L, address_parent &P);
void deleteSpesificParent(List_Parent &L, string X);
address_parent findElmParent(List_Parent &L, string X);
void printInfoParent(List_Parent L);
