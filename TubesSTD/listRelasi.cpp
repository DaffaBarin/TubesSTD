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
        L.last = R;
    }
}

void deleteFirstRelasi(List_Relasi &L, relateAddress &R){
    if (L.first != L.last) {
        R = L.first;
        L.first = R -> next;
        R -> next = NULL;
    }else {
        R = L.first;
        L.first = NULL;
        L.last = NULL;
    }
}
void deleteAfterRelasi(List_Relasi &L, relateAddress Prec, relateAddress &R){
    R -> next = Prec -> next;
    Prec -> next = R -> next;
}
void deleteLastRelasi(List_Relasi &L, relateAddress &R){
    relateAddress Q = L.first;
    while (Q -> next -> next != NULL) {
        Q = Q -> next;
    }
    R = Q -> next;
    Q -> next = NULL;
}
void deleteSpesificRelasi(List_Relasi &L, string out){
    relateAddress R = L.first;
    if (R != NULL){
        if (L.first -> lapas -> info.namaLapas == out){
            deleteFirstRelasi(L,R);
        } else if (L.first -> tahanan -> info.namaTahanan == out){
            deleteLastRelasi(L,R);
        } else {
            while (R != NULL && R -> lapas -> info.namaLapas != out && R -> tahanan -> info.namaTahanan != out){
                R = R -> next;
            }
            if (R -> lapas -> info.namaLapas == out || R -> tahanan -> info.namaTahanan == out) {
                deleteAfterRelasi(L,R -> prev,R);
            }else {
                cout<<out<<" tidak ada pada relasi."<<endl;
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
        cout<<R -> lapas -> info.namaLapas;
        R = R -> next;
    }
    cout<<endl;
}
