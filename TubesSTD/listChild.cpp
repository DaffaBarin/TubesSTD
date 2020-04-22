#include "listChild.h"
void createListChild(List2 &L){
    first(L) = Nil;
}
address2 CreateElmChild(infotypeChild st){
    address2 P;
/*Algoritma*/
    P=(address)malloc(sizeof(child));
    if(P!=Nil){
        info(P)=st;
        next(P)=Nil;
    }
    return P;

}

void insertFirstChild(List2 &L, address2 P){
    address2 last;

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
void insertAfterChild(List2 &L, address2 Prec, address2 P){
    if (first(L) == Nil){
        insertFirstChild(L, P);
    }
    else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void insertLastChild(List2 &L, address2 P){
    address2 last;
    if (first(L) == Nil){
        first(L) = P;
        next(P) = P;
    }
    else{
        Last = first(L);
        while (next(last) != first(L)){
            last = next(last);
        }
        next(last) = P;
        next(P) = first(L);
    }
}
void insertSortChild(List2 &L, infotypeChild st);
void deleteFirstChild(List2 &L, address2 &P){
    address2 last;
    if (first(L) != Nil){
        last = first(L);
        P = createListChild(info(last));
        if (next(last) == first(L)){
            delete last;
            createListChild(L);
        }
        else{
            while (next(last) != first(L)){
                last = next(last);
            }
            first(L) = next(first(L));
            delete next(last);
            next(last) = first(L);
        }
    }
}
void deleteAfterChild(List2 &L, address2 Prec, address2 &P){
     if (first(L) != Nil){
        P = next(Prec);
        if (P != first(L)){
            next(Prec) = next(P);
            P = createListChild(info(P));
            delete P;
        }
        else{
            P = Nil;
        }
    }
}
void deleteLastChild(List2 &L, address2 &P){
    address2 last;
     if(first(L) != Nil){
        last = first(L);
        if (next(last) == first(L)){
            P = createListChild(info(last));
            delete last;
            createListChild(L);
        }
        else{
            Prec = Nil;
            while (next(Last) != first(L)){
                Prec = last;
                last = next(last);
            }
            next(Prec) = first(L);
            P = createListChild(info(last));
            delete last;
        }
    }
}
void deleteSpesificChild(List2 &L, string X);
address2 findElmChild(List2 &L, string X){
    bool found;
    address2 P;

    found = false;
    if (first(L) != Nil){
        P = first(L);
        do{
            if (info(P) == X){
                found = true;
            }
            else{
                P = next(P);
            }
        }while ((next(P) != first(L)) && (found != true));
    }
    if (found == false){
        P = Nil;
    }
    return P;
}
void printInfoChild(List2 L){
    address2 P;
    if (first(L) != Nil) {
        P = first(L);
        while (next(P) != first(L)){
            printf("%d ",info(P));
            P = next(P);
        }
        printf("%d\n",info(P));
    }
}