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
        case 1:
            //insert parent
            cout<<"1.Mendaftarkan Lapas"<<endl;
            break;
        case 2:
            //insert child
            cout<<"2.Mendaftarkan Tahanan"<<endl;
            break;
        case 3:
            //print parent
            cout<<"3.Melihat semua Lapas terdaftar"<<endl;
            break;
        case 4:
            //print child
            cout<<"4.Melihat semua Tahanan terdaftar"<<endl;
            break;
        case 5:
            //connect relasi
            cout<<"5.Memilih Lapas untuk Tahanan"<<endl;
            break;
        case 6:
            //print relasi
            cout<<"6.Melihat tahanan dan lokasi lapasnya"<<endl;
            break;
        case 7:
            //case fungsi 1
            cout<<"7.Melihat rata-rata usia Tahanan pada Lapas tertentu"<<endl;
            break;
        case 8:
            //case fungsi 2
            cout<<"8.Melihat Lapas dengan jumlah tahanan terbanyak"<<endl;
            break;
        case 9:
            //delete parent dan dealokasi
            cout<<"9.Menghapus Lapas dari daftar Lapas"<<endl;
            break;
        case 10:
            //delete child dan dealokasi
            cout<<"10.Menghapus Tahanan dari daftar Tahanan"<<endl;
            break;
        case 11:
            //disconnect relasi
            cout<<"11.Melepas tahanan dari lapas"<<endl;
            break;
        cout<<"Pilihan menu: ";
        cin>>pilih;

    }while(pilih>0);
    return 0;
}
