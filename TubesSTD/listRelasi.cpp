#include "listRelasi.h"

using namespace std;

void createListRelasi(List_Relasi &L){
    L.first = NULL;
    L.last = NULL;
}
relateAddress CreateElmRelasi(address_parent P, address_child Q){
    relateAddress R = new Relasi;
    R -> lapas = P;
    R -> tahanan = Q;
    R -> next = NULL;
    R -> prev = NULL;
    P -> info.countLapas++;
    Q -> info.countTahanan++;
    return R;
}
void insertRelasi(List_Relasi &L, relateAddress R){
    if (L.first == NULL) {
        L.first = R;
        L.last = R;
    } else {
        L.last -> next = R;
        R -> prev = L.last;
        L.last = R;
    }
}

void deleteFirstRelasi(List_Relasi &L, relateAddress &R){
    if (L.first != L.last) {
        R = L.first;
        L.first = R -> next;
        R -> next = NULL;
        L.first -> prev = NULL;
    }else {
        R = L.first;
        L.first = NULL;
        L.last = NULL;
    }
    deallocateRelasi(R);
}
void deleteAfterRelasi(List_Relasi &L, relateAddress Prec, relateAddress &R){
    R = Prec -> next;
    Prec -> next = R -> next;
    R -> next -> prev = Prec;
    R -> prev = NULL;
    R -> next = NULL;
    deallocateRelasi(R);
}
void deleteLastRelasi(List_Relasi &L, relateAddress &R){
    R = L.last;
    L.last = R -> prev;
    R -> prev = NULL;
    L.last -> next = NULL;
    deallocateRelasi(R);
}
void deleteSpesificRelasi(List_Relasi &L, address_parent P, address_child Q){
    relateAddress R = L.first;
    if (R != NULL){
        if (L.first -> lapas == P && L.first -> tahanan == Q){
            deleteFirstRelasi(L,R);
        } else if (L.last -> lapas == P){
            deleteLastRelasi(L,R);
        } else {
            while (R != NULL && (R -> lapas != P && R -> tahanan != Q)){
                R = R -> next;
            }
                if (R != NULL) {
                    deleteAfterRelasi(L,R -> prev,R);
                }else {
                    cout<<"Belum ada relasi."<<endl;
                }
        }
    }else {
        cout<<"Tidak ada relasi saat ini."<<endl;
    }
    cout<<endl;
}
relateAddress findElmRelasiParent(List_Relasi &L, string out){
    relateAddress R = L.first;
    while (R != NULL){
      if (R -> lapas -> info.namaLapas == out){
        return R;
      }
      R = R -> next;
    }
    return NULL;
}

void deleteAllRelasiParent(List_Relasi &L, address_parent P){
    relateAddress R;
    while (findElmRelasiParent(L,P->info.namaLapas) != NULL){
        if (L.first -> lapas == P){
            deleteFirstRelasi(L,R);
        }
         else if (L.last -> lapas == P){
            deleteLastRelasi(L,R);
        }else {
            R = L.first;
            while (findElmRelasiParent(L,P->info.namaLapas) != NULL){
                if (R -> lapas == P){
                    deleteAfterRelasi(L,R -> prev,R);
                }
                R = R -> next;
            }
        }
    }
}

relateAddress findElmRelasiChild(List_Relasi &L, string out){
    relateAddress R = L.first;
    while (R != NULL){
      if (R -> tahanan -> info.namaTahanan == out){
        return R;
      }
      R = R -> next;
    }
    return NULL;
}

void deleteAllRelasiChild(List_Relasi &L, address_child Q){
    relateAddress R;
    while (findElmRelasiChild(L,Q->info.namaTahanan) != NULL){
        if (L.first -> tahanan == Q){
            deleteFirstRelasi(L,R);
        }
         else if (L.last -> tahanan == Q){
            deleteLastRelasi(L,R);
        }else {
            R = L.first;
            while (findElmRelasiChild(L,Q->info.namaTahanan) != NULL){
                if (R -> tahanan == Q){
                    deleteAfterRelasi(L,R -> prev,R);
                }
                R = R -> next;
            }
        }
    }
}

void countRelasiByChild(List_Relasi L){
    relateAddress R = L.first;
    relateAddress P;
    int max = 0;
    if (R != NULL) {
        while (R != NULL){
            if (max < R -> tahanan -> info.countTahanan){
                max = R -> tahanan -> info.countTahanan;
                P = R;
            }
            R = R -> next;
        }
        cout<<"Tahanan dengan riwayat ditahan terbanyak adalah ";
        cout<<P -> tahanan -> info.namaTahanan<<endl;
        printRelasiByChild(L,P -> tahanan -> info.namaTahanan);
    }
}

void printRelasiByChild(List_Relasi L, string out){
    relateAddress R = L.first;
    while (R != NULL){
        if (R -> tahanan -> info.namaTahanan == out){
            cout<<R -> lapas -> info.namaLapas<<" ";
        }
        R = R -> next;
    }
    cout<<endl;
}

void countRelasiByParent(List_Relasi L){
    relateAddress R = L.first;
    relateAddress P;
    int max = 0;
    if (R != NULL) {
        while (R != NULL){
            if (max < R -> lapas -> info.countLapas){
                max = R -> lapas -> info.countLapas;
                P = R;
            }
            R = R -> next;
        }
        cout<<"Lapas dengan tahanan terbanyak adalah ";
        cout<<P -> lapas -> info.namaLapas<<endl;
        printRelasiByChild(L,P -> lapas -> info.namaLapas);
    }

}

void printRelasiByParent(List_Relasi L, string out){
    relateAddress R = L.first;
    while (R != NULL){
        if (R -> lapas -> info.namaLapas == out){
            cout<<R -> tahanan -> info.namaTahanan<<" ";
        }
        R = R -> next;
    }
    cout<<endl;
}

void printInfoRelasi(List_Relasi L){
    relateAddress R = L.first;
    while (R!=NULL){
        cout<<R -> tahanan -> info.namaTahanan<<" ditahan di ";
        cout<<R -> lapas -> info.namaLapas<<endl;
        R = R -> next;
    }
    cout<<endl;
}

void deallocateRelasi(relateAddress R){
    delete R;
}
