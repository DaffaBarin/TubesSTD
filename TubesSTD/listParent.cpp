#include "listParent.h"
boolean IsEmpty(List1 &L){

    if(First(L) == Nil){
        return true;
    }
    else{
        return false;
    }
}

void createListParent(List1 &L){
    first(L) = Nil;

}
address1 CreateElmParent(infotypeParent st){
    address1 P;
    P = new parent;
    info(P) = st;
    next(P) = Nil;
    return P;
}
void insertFirstParent(List1 &L, address1 P){
    address1 Q;
    if (first(L) == Nil) 
    {
        first(L) = P;
        next(P) = P;
    } else
    {
        Q = first(L);
        while (next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
        
    }
    
    
}
void insertAfterParent(List1 &L, address1 Prec, address1 P){
    next(P) = next(Prec);
	prev(next(P)) = P;
	next(Prec) = P;
	prev(P) = Prec;
}
void insertLastParent(List1 &L, address1 P){
    address1 Q;
    if(!IsEmpty(L)){
		Q = first(L);
		while(next(Q) != first(L)){
			Q = next(Q);
		}
		insertAfterParent(L, P, Q);
	}
	else{/*Jika kosong*/
		insertFirstParent(L, P);
	}
}
}
void deleteFirstParent(List1 &L, address1 &P);
void deleteAfterParent(List1 &L, address1 Prec, address1 &P);
void deleteLastParent(List1 &L, address1 &P);
void deleteSpesificParent(List1 &L, string X);
address1 findElmParent(List1 &L, string X);
void printInfoParent(List1 L);