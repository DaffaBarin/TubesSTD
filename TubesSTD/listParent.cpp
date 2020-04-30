#include <iostream>
#include "listParent.h"
//DAFFA BARIN 1301190369
void createListParent(List_Parent &L) {
    L.first = NULL;
}
//DAFFA BARIN 1301190369
void inputDataLapas(List_Parent L, infotypeParent &in){
    cout<<"Nama Lapas: ";
    cin>>in.namaLapas;
    while (findElmParent(L , in.namaLapas) != NULL ) {
        cout<<"Lapas sudah ada. Input kembali."<<endl;
        cout<<"Nama Lapas: ";
        cin>>in.namaLapas;
    }
    cout<<"Ukuran Lapas: ";
    cin >> in.luasLapas;
    in.IDLapas = generatorIDParent();
    while (findElmParent(L,in.IDLapas) != NULL){
        in.IDLapas = generatorIDParent();
    }
    cout<<"ID Lapas: "<<in.IDLapas;
    in.countLapas = 0;
}
//DAFFA BARIN 1301190369
address_parent CreateElmParent(infotypeParent in){
    address_parent P = new parent;
    P -> info = in;
    P -> next = NULL;
    P -> prev = NULL;
    return P;
}
//DAFFA BARIN 1301190369
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
//DAFFA BARIN 1301190369
void insertAfterParent(List_Parent &L, address_parent Prec, address_parent P){
    P -> next = Prec -> next;
    P -> prev = Prec;
    Prec -> next -> prev = P;
    Prec -> next = P;
}
//DAFFA BARIN 1301190369
void insertLastParent(List_Parent &L, address_parent P){
    P -> next = L.first;
    L.first -> prev = P;
    L.first = P;
}
//DAFFA BARIN 1301190369
void insertSortedParent(List_Parent &L, infotypeParent in){
    if (L.first != NULL) {
        if (findElmParent(L,in.namaLapas) == NULL){
            if (in.namaLapas < L.first -> info.namaLapas){
                insertFirstParent(L,CreateElmParent(in));
            } else {
                address_parent P = L.first;
                do {
                    P = P -> next;
                } while(P!= L.first && P -> info.namaLapas > in.namaLapas);
                insertAfterParent(L,P -> prev,CreateElmParent(in));
            }
        } else {
            cout << "Lapas sudah terdaftar"<<endl;
        }
    }else {
        insertFirstParent(L,CreateElmParent(in));
    }
}
//DAFFA BARIN 1301190369
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
//DAFFA BARIN 1301190369
void deleteAfterParent(List_Parent &L, address_parent Prec, address_parent &P){
    P = Prec -> next;
    P -> next -> prev = Prec;
    Prec -> next = P -> next;
    P -> next = NULL;
    P -> prev = NULL;
}
//DAFFA BARIN 1301190369
void deleteLastParent(List_Parent &L, address_parent &P) {
    P = L.first -> prev;
    P -> prev -> next = L.first;
    L.first -> prev = P -> prev;
    P -> next = NULL;
    P -> prev = NULL;
}
//DAFFA BARIN 1301190369
void deleteSpesificParent(List_Parent &L, string X){
    address_parent P = findElmParent(L,X);
    if (P != NULL && P -> next != NULL && P -> prev != NULL){
        if (P = L.first){
            deleteFirstParent(L,P);
        } else {
            deleteAfterParent(L,P -> prev,P);
        }
        cout<<"Penghapusan lapas "<<X<<" telah berhasil"<<endl;
    }else {
        cout << "Lapas tidak ditemukan"<<endl;
    }
}
//DAFFA BARIN 1301190369
void deallocateParent(address_parent &P){
    delete P;
}
//DAFFA BARIN 1301190369
address_parent findElmParent(List_Parent L, string X){
    address_parent P = L.first;
    if (P!= NULL) {
        do {
            P = P -> next;
             if (P -> info.namaLapas == X || P -> info.IDLapas == X){
                return P;
             }
        } while (P != L.first && P -> info.namaLapas != X && P -> info.IDLapas != X);
    }
    return NULL;
}


//DAFFA BARIN 1301190369
void printInfoParent(List_Parent L){
    address_parent P = L.first;
    if (P != NULL){
        do {
            cout<<"************************************"<<endl;
            cout<<"Lapas: "<<P -> info.namaLapas<<endl;
            cout<<"Luas lapas: "<< P -> info.luasLapas<<endl;
            cout<<"ID: "<<P -> info.IDLapas<<endl;
            cout<<"************************************"<<endl<<endl;
            P = P -> next;
        }while(P != L.first);
    }
    cout<<endl;
}
//DAFFA BARIN 1301190369
string generatorIDParent(){
    int r;
    stringstream sss;
    srand((int)time(0));
    r = (rand() % 850) + 1;
    sss<<r;
    string s;
    sss>>s;
    return s;
}
