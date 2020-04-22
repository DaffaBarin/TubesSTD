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

void insertSortedChild(List_Child &L, infotypeChild in){
    if (L.first != NULL) {
        if (findElmChild(L,in.namaTahanan) == NULL){
            if (in.namaTahanan < L.first -> info.namaTahanan){
                insertFirstChild(L,CreateElmChild(in));

            } else if (in.namaTahanan > L.last -> info.namaTahanan){
                insertLastChild(L,CreateElmChild(in));
            } else {
                address_child P = L.first;
                while (P != NULL && in.namaTahanan > P -> info.namaTahanan){
                    P = P -> next;
                }
                insertAfterChild(L,P,CreateElmChild(in));
            }
        } else {
            cout << "Tahanan sudah terdaftar"<<endl;
        }
    }else {
        insertFirstChild(L,CreateElmChild(in));
    }
}
void deleteFirstChild(List_Child &L, address_child &P){
    if (L.first != L.last) {
        P = L.first;
        L.first = P -> next;
        P -> next = NULL;
    }else {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    }
}
void deleteAfterChild(List_Child &L, address_child Prec, address_child &P){
    P -> next = Prec -> next;
    Prec -> next = P -> next;
}
void deleteLastChild(List_Child &L, address_child &P){
    address_child Q = L.first;
    while (Q -> next -> next != NULL) {
        Q = Q -> next;
    }
    P = Q -> next;
    Q -> next = NULL;
}
void deleteSpesificChild(List_Child &L, string X){
    address_child P = findElmChild(L,X);
    if (L.first != NULL && P != NULL){
        if (L.first -> info.namaTahanan == X){
            deleteFirstChild(L,P);
        } else if (L.last -> info.namaTahanan == X) {
            deleteLastChild(L,P);
        } else {
            P = L.first;
            address_child Q;
            while (P -> info.namaTahanan != X){
                Q = P;
                P = P -> next;
            }
            deleteAfterChild(L,Q,P);
        }
        cout<<"Penghapusan tahanan "<<X<<"telah berhasil"<<endl;
    } else {
        cout<<"Tahanan sudah tidak ada."<<endl;
    }
    cout<<endl;
}
address_child findElmChild(List_Child &L, string X){
    address_child P = L.first;
    while (P != NULL && P -> info.namaTahanan != X && P -> info.IDTahanan != X) {
        P = P -> next;
    }
    return P;
}

void printInfoChild(List_Child L){
    address_child P = L.first;
    while (P!=NULL){
        cout<<"Nama:"<<P -> info.namaTahanan<<endl;
        cout<<"Usia:"<<P -> info.usiaTahanan<<endl;
        cout<<"ID:"<<P -> info.IDTahanan<<endl;
        P = P -> next;
        cout<<endl;
    }
    cout<<endl;
}

string generatorIDChild(){
    int r;
    stringstream ss;
    srand((int)time(0));
    r = (rand() % 850) + 1;
    ss<<r;
    string s;
    ss>>s;
    return s;
}
