#include <iostream>
#include "listRelasi.h"
using namespace std;

int main()
{
    int pilih;
    List_Parent List_Parent;
    List_Child List_Child;
    List_Relasi List_Relasi;
    infotypeParent DataLapas;
    infotypeChild DataTahanan;
    address_parent P;
    address_child Q;
    relateAddress R;
    createListParent(List_Parent);
    createListChild(List_Child);
    createListRelasi(List_Relasi);

    do{ cout<<"************************************"<<endl;
        cout<<"         SELAMAT DATANG DI          "<<endl;
        cout<<"   Menu Administrasi Lapas Tahanan  "<<endl;
        cout<<"             V.1.0                  "<<endl;
        cout<<"************************************"<<endl<<endl;

        //insert parent
        cout<<"1.Mendaftarkan Lapas"<<endl;
        //insert child
        cout<<"2.Mendaftarkan Tahanan"<<endl;
        //print parent
        cout<<"3.Melihat semua Lapas terdaftar"<<endl;
        //print child
        cout<<"4.Melihat semua Tahanan terdaftar"<<endl;
        //connect relasi
        cout<<"5.Memilih Lapas untuk Tahanan"<<endl;
        //print relasi
        cout<<"6.Melihat tahanan dan lokasi lapasnya"<<endl;
        //case fungsi 1
        cout<<"7.Melihat Tahanan yang paling sering ditahan"<<endl;
        //case fungsi 2
        cout<<"8.Melihat Lapas dengan jumlah Tahanan terbanyak"<<endl;
        //delete parent dan dealokasi
        cout<<"9.Menghapus Lapas dari daftar Lapas"<<endl;
        //delete child dan dealokasi
        cout<<"10.Menghapus Tahanan dari daftar Tahanan"<<endl;
        //disconnect relasi
        cout<<"11.Melepas tahanan dari lapas"<<endl;
        cout<<"Pilihan menu: ";
        cin>>pilih;
        cout<<endl<<endl;

    system ("cls");
        switch (pilih){
            case 1 :
                inputDataLapas(List_Parent,DataLapas);
                insertSortedParent(List_Parent,DataLapas);
                break;
            case 2 :
                inputDataTahanan(List_Child,DataTahanan);
                insertSortedChild(List_Child,DataTahanan);
                break;
            case 3 :
                printInfoParent(List_Parent);
                break;
            case 4 :
                printInfoChild(List_Child);
                break;
            case 5 :
                cout<<"Nama Lapas:"<<endl;
                cin.get();
                getline(cin,DataLapas.namaLapas);
                P = findElmParent(List_Parent,DataLapas.namaLapas);
                cout<<"Nama Tahanan:"<<endl;
                getline(cin,DataTahanan.namaTahanan);
                Q = findElmChild(List_Child,DataTahanan.namaTahanan);
                if (P != NULL && Q != NULL){
                    R = CreateElmRelasi(P,Q);
                    insertRelasi(List_Relasi,R);
                } else {
                    if (P == NULL){
                        cout<<"Lapas belum terdaftar"<<endl;
                    }
                    if (Q == NULL){
                        cout<<"Tahanan belum terdaftar"<<endl;
                    }
                }
                break;
            case 6 :
                printInfoRelasi(List_Relasi);
                break;
            case 7 :
                countRelasiByChild(List_Relasi);
                break;
            case 8 :
                countRelasiByParent(List_Relasi);
                break;
            case 9 :
                cout<<"Nama lapas: ";
                cin.get();
                getline(cin,DataLapas.namaLapas);
                P = findElmParent(List_Parent,DataLapas.namaLapas);
                R = findElmRelasiParent(List_Relasi,P->info.namaLapas);
                if (P != NULL){
                    if (R != NULL){
                        deleteAllRelasiParent(List_Relasi,P);
                    }
                    deleteSpesificParent(List_Parent,P -> info.namaLapas);
                    deallocateParent(P);
                }else {
                    cout<<"Lapas belum terdaftar."<<endl;
                }
                break;
            case 10 :
                cout<<"Nama Tahanan:"<<endl;
                cin.get();
                getline(cin,DataTahanan.namaTahanan);
                Q = findElmChild(List_Child,DataTahanan.namaTahanan);
                R = findElmRelasiChild(List_Relasi,Q->info.namaTahanan);
                if (Q != NULL){
                    if (R != NULL){
                        deleteAllRelasiChild(List_Relasi,Q);
                    }
                    deleteSpesificChild(List_Child,Q -> info.namaTahanan);
                    deallocateChild(Q);
                }else {
                    cout<<"Tahanan belum terdaftar."<<endl;
                }
                break;
            case 11 :
                cout<<"Nama Lapas:"<<endl;
                cin.get();
                getline(cin,DataLapas.namaLapas);
                cout<<"Nama Tahanan:"<<endl;
                getline(cin,DataTahanan.namaTahanan);
                deleteSpesificRelasi(List_Relasi,DataLapas.namaLapas,DataTahanan.namaTahanan);
                break;
            default:
                cout<<"************************************"<<endl;
                cout<<"Maaf nilai yang anda masukkan salah"<<endl;
                cout<<"       Silahkan ulangi lagi :) "<<endl;
                cout<<"*************************************"<<endl<<endl;
        }

    }while(pilih>0);
    return 0;
}
