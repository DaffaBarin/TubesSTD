#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <cstdlib>
#include <ctime>


using namespace std;

struct infotypeParent {
    string namaLapas;
    string IDLapas;
    int luasLapas;
    int countLapas;
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
address_parent CreateElmParent(infotypeParent in);
void insertFirstParent(List_Parent &L, address_parent P);
void insertAfterParent(List_Parent &L, address_parent Prec, address_parent P);
void insertLastParent(List_Parent &L, address_parent P);
//agar semua insert bisa terpakai
void insertSortedParent(List_Parent &L, infotypeParent in);
void deleteFirstParent(List_Parent &L, address_parent &P);
void deleteAfterParent(List_Parent &L, address_parent Prec, address_parent &P);
void deleteLastParent(List_Parent &L, address_parent &P);
//agar semua delete bisa terpakai
void deleteSpesificParent(List_Parent &L, string X);
address_parent findElmParent(List_Parent L, string X);
void printInfoParent(List_Parent L);

void inputDataLapas(List_Parent L,infotypeParent &in);

//string 3 digit
string generatorIDParent();
void deallocateParent(address_parent &P);
