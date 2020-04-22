#include "listChild.h"
void createListChild(List2 &L){
    first(L) = Nil;
}
address2 CreateElmChild(infotypeChild st){
    address P;
/*Algoritma*/
    P=(address)malloc(sizeof(child));
    if(P!=Nil){
        info(P)=st;
        next(P)=Nil;
    }
    return P;

}

void insertFirstChild(List2 &L, address2 P){
    address last;

/*algoritma*/
    if (first(L) == Nil){
        first(L) = P;
        next(P) = P;
    }
    else{
        last = first(L);
        while (next(last) != first(L)){
            last = next(last);
        }
        next(last) = P;
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfterChild(List2 &L, address2 Prec, address2 P);
void insertLastChild(List2 &L, address2 P);
void insertSortChild(List2 &L, infotypeChild st);
void deleteFirstChild(List2 &L, address2 &P);
void deleteAfterChild(List2 &L, address2 Prec, address2 &P);
void deleteLastChild(List2 &L, address2 &P);
void deleteSpesificChild(List2 &L, string X);
address2 findElmChild(List2 &L, string X);
void printInfoChild(List2 L);