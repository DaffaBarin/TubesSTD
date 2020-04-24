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

    do{
        cout<<"Menu Administrasi Lapas Tahanan"<<endl;

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
        cout<<"7.Melihat rata-rata usia Tahanan pada Lapas tertentu"<<endl;
        //case fungsi 2
        cout<<"8.Melihat Lapas dengan jumlah tahanan terbanyak"<<endl;
        //delete parent dan dealokasi
        cout<<"9.Menghapus Lapas dari daftar Lapas"<<endl;
        //delete child dan dealokasi
        cout<<"10.Menghapus Tahanan dari daftar Tahanan"<<endl;
        //disconnect relasi
        cout<<"11.Melepas tahanan dari lapas"<<endl;
        cout<<"Pilihan menu: ";
        cin>>pilih;

    }while(pilih>0);
    return 0;
}
