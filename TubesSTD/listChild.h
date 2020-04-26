#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

struct infotypeChild {
    string namaTahanan;
    string IDTahanan;
    int usiaTahanan;
    int countTahanan;
};

typedef struct child *address_child;

struct child {
    infotypeChild info;
    address_child next;
};

struct List_Child {
    address_child first;
    address_child last;
};


void createListChild(List_Child &L);
address_child CreateElmChild(infotypeChild in);
void insertFirstChild(List_Child &L, address_child P);
void insertAfterChild(List_Child &L, address_child Prec, address_child P);
void insertLastChild(List_Child &L, address_child P);
//agar semua fungsi bisa terpakai
void insertSortedChild(List_Child &L, infotypeChild X);
void deleteFirstChild(List_Child &L, address_child &P);
void deleteAfterChild(List_Child &L, address_child Prec, address_child &P);
void deleteLastChild(List_Child &L, address_child &P);
void deleteSpesificChild(List_Child &L, string X);
address_child findElmChild(List_Child &L, string X);
void printInfoChild(List_Child L);

void inputDataTahanan(List_Child L,infotypeChild &in);

//string 3 digit
string generatorIDChild();
void deallocateChild(address_child &P);
