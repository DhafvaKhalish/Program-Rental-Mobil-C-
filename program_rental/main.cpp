#include <iostream>
#include <conio.h>
#include <string.h>
#include <dos.h>
#include<iomanip>
#include<cstdlib>
using namespace std;
struct mobil
{
	int kodeB,sewa,stock;
	char judul[20];
	int b;
}mobil[100];
struct pinjam
{
	int kodepinjam,d,kB,tglpin,tglbalik,dipinjem;
	char namap[40];
	char alamat[40];
	char status;
}pinjemmobil[100];


int main(){
	system("cls");

	int jmlbuk,a,c,e,f,g,h,jmlpin,hs,lp,kodepin,stok;
	int b =-1;
	int d =-1;
	char yn,ch,temp;


	login:
	string user = "";
	string pass = "";
	cout<<"\n\n\n\n\n\n\n\n";
	cout<<"\t\t ------- Program Aplikasi Rental Mobil Sederhana  --------\n\n";
	cout << "\t\t\t  Username : "; cin>>user;
	cout << "\t\t\t  Password : ";
	ch = _getch();
    while(ch != 13){
    pass.push_back(ch);
    cout << '*';
    ch = _getch();
    }
    cout<<endl;
	if(user == "admin" && pass == "123"){
		cout << "\n\n Anda berhasil login. \n" << endl;
		system("pause");
		system("cls");
		goto mulaimenu;
	}else{
		cout<<" Password Anda Salah \n";
   	    system("pause");
   	    system("cls");
	 	goto login;
	}


	mulaimenu:
	int pil;
	cout<<"---- Aplikasi Rental mobil ----"<<endl;
    cout<<"-------- Menu ----------\n";
    cout<<" 1. Input mobil        \n";
    cout<<" 2. Daftar mobil       \n";
    cout<<" 3. Peminjaman      \n";
    cout<<" 4. Pengembalian    \n";
    cout<<" 5. Laporan   \n";
    cout<<" 6. Exit                \n";
    cout<<"----------------------\n";
    cout<<"Masukan Pilihan anda[ 1 s.d. 6 ] = ";cin>>pil;

	if(pil ==1){
		inbuk:
		system("cls");
		cout<<"\n"<<endl;
		cout<<"\t\t\tInput mobil : \n";
		cout<<"\t\t\t________\n"<<endl;
		cout<<endl;
		b++;
			cout<<" Masukan data mobil Ke \t: "<<b+1<<endl;
			cout<<" No Polisi \t\t:";scanf("%d%c", &mobil[b].kodeB, &temp);
			cout<<" Merek mobil\t\t:";gets(mobil[b].judul);
			cout<<" Harga Sewa \t\t:";scanf("%d%c", &mobil[b].sewa, &temp);
			cout<<" Jumlah mobil\t\t:";scanf("%d%c", &mobil[b].stock, &temp);
			cout<<endl;
			cout<<"Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) :";cin>>yn;
			if(yn=='y'||yn=='Y'){
				goto inbuk;
			}else{
				cout << "\n\n Data Berhasil Disimpan \n" << endl;
				system("pause");
				system("cls");
				goto mulaimenu;
			}
		{
			cout << "\n\n Data Berhasil Disimpan \n" << endl;
			system("pause");
			system("cls");
			goto mulaimenu;
		}

	}else if( pil == 2 ){
		system("cls");
		cout<<"\n"<<endl;
		cout<<"\t\t\tDaftar mobil"<<endl;
		cout<<"\t\t\t_____\n"<<endl;
		cout<<"------------------------------------------------------------------\n";
		cout<<" No  No Polisi     Merek mobil    Harga Sewa    Jumlah mobil     mobil Keluar \n";
		cout<<"------------------------------------------------------------------\n";
		for(c=0;c<=b;c++){
			stok = mobil[c].stock-pinjemmobil[c].dipinjem;
			cout<<setw(2)<<c+1<<setw(8)<<mobil[c].kodeB<<setw(22)<<mobil[c].judul<<setw(10)<<mobil[c].sewa<<setw(14)<<stok<<setw(12)<<pinjemmobil[c].dipinjem;
			cout<<endl;
		}
		cout<<endl;
		system("pause");
		system("cls");
		goto mulaimenu;

	}else if(pil == 3){
		transaksipinjem:
			d++;
			system("cls");
			cout<<"\n"<<endl;
			cout<<"\t\t\t Transaksi Peminjaman : \n";
			cout<<"\t\t\t________\n"<<endl;
			cout<<endl;
				cout<<" Masukan data Pinjaman Ke \t: "<<d+1<<endl;
				cout<<" NO NIK \t\t\t:";scanf("%d%c", &pinjemmobil[d].kodepinjam, &temp);
				cout<<" NO Polisi \t\t\t:";scanf("%d%c", &pinjemmobil[d].kB, &temp);



				cout<<" Nama Penyewa mobil \t\t:";gets(pinjemmobil[d].namap);
				cout<<" Alamat Penyewa \t\t:";gets(pinjemmobil[d].alamat);
				cout<<" Tanggal Pinjam (DDMMYYYY)\t:";scanf("%d%c", &pinjemmobil[d].tglpin, &temp);
				cout<<" Tanggal Balik (DDMMYYYY)\t:";scanf("%d%c", &pinjemmobil[d].tglbalik, &temp);
				lp = (pinjemmobil[d].tglbalik-pinjemmobil[d].tglpin)/1000000;
				cout<<" Lama Pinjaman \t\t\t:"<<lp<<" Hari"<<endl;
				cout<<" banyak mobil yang di pinjam  \t:";scanf("%d%c", &pinjemmobil[d].dipinjem, &temp);
				hs = pinjemmobil[d].dipinjem*mobil[d].sewa;
				cout<<" Harga Sewa \t\t\t:"<<hs;
				cout<<endl;
				cout<<" Status dipinjam (y) ? \t\t:";cin>>pinjemmobil[d].status;
				cout<<endl;
			cout<<"Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) :";cin>>yn;

			if(yn=='y'||yn=='Y'){
				goto transaksipinjem;
			}else{
				cout << "\n\n Data Berhasil Disimpan \n" << endl;
				system("pause");
				system("cls");
				goto mulaimenu;
			}

	}else if(pil == 4){
		system("cls");
		pengembalian:
			cout<<"\n"<<endl;
			cout<<"\t\t\tMasukan kode Peminjaman :";cin>>kodepin;
			cout<<"\t\t\t________\n"<<endl;
			cout<<endl;
			for(f=0;f<=d;f++){
				if(pinjemmobil[f].kodepinjam==kodepin){
					cout<<" Nama Penyewa mobil \t\t:"<<pinjemmobil[f].namap;
					cout<<endl;
					cout<<" Alamat Penyewa \t\t:"<<pinjemmobil[f].alamat;
					cout<<endl;
					if(mobil[f].kodeB==pinjemmobil[f].kB){
						cout<<" Judul mobil \t\t\t:"<<mobil[f].judul<<endl;
					}
					cout<<" Tanggal Pinjam (DDMMYYYY)\t:"<<pinjemmobil[f].tglpin;
					cout<<endl;
					cout<<" Tanggal Balik (DDMMYYYY)\t:"<<pinjemmobil[f].tglbalik;
					cout<<endl;
					lp = (pinjemmobil[f].tglbalik-pinjemmobil[f].tglpin)/1000000;
					cout<<" Lama Pinjaman \t\t\t:"<<lp<<" Hari"<<endl;
					cout<<endl;
					cout<<" banyak mobil yang di pinjam  \t:"<<pinjemmobil[f].dipinjem;
					cout<<endl;
					hs = pinjemmobil[f].dipinjem*mobil[f].sewa;
					cout<<" Harga Sewa \t\t\t:"<<hs<<endl;
					cout<<" Status : "<<pinjemmobil[f].status;
					if((pinjemmobil[f].status == 'y') || (pinjemmobil[f].status == 'Y')){
						cout<<" (di Pinjam) "<<endl;
					}else{
						cout<<" (di kembalikan) "<<endl;
					}
					cout<<endl;
					cout<<" Sudah di kembalikan ? (y/n) : ";cin>>yn;
					if((yn == 'Y') || (yn == 'y')){
						cout<<" ganti status ( input n ) :";
						cin>>pinjemmobil[f].status;
						cout << "\n\n Data Berhasil Disimpan \n" << endl;
						system("pause");
						system("cls");
						goto mulaimenu;
					}else{
						cout << "\n\n Data Berhasil Disimpan \n" << endl;
						system("pause");
						system("cls");
						goto mulaimenu;
					}
				}else{
					cout << "\n\n Data Tidak Di temukan \n" << endl;
					cout<<" Apakah ingin mengulang kembali ? (y/n) : ";cin>>yn;
					if(yn == 'Y' || yn == 'y'){
						system("cls");
						goto pengembalian;
					}else{
						system("cls");
						goto mulaimenu;
					}
				}
			}
	}else if(pil == 5){
		system("cls");
			cout<<"\n"<<endl;
			cout<<"\t\t\t laporan mobil\n";
			cout<<"\t\t\t________\n"<<endl;
			cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
			cout<<" No  NIK  Judul mobil  Nama Peminjam    Alamat     Tanggal Pinjam  Tanggal Balik   Status   mobil Keluar \n";
			cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
			for(g=0;g<=b;g++){
				if(pinjemmobil[g].kB==mobil[g].kodeB){
					cout<<setw(2)<<g+1<<setw(10)<<pinjemmobil[g].kodepinjam<<setw(13)<<mobil[g].judul<<setw(12)<<pinjemmobil[g].namap
					<<setw(14)<<pinjemmobil[g].alamat<<setw(20)<<pinjemmobil[g].tglpin<<setw(10)<<pinjemmobil[g].tglbalik
					<<setw(12)<<pinjemmobil[g].status;
					if((pinjemmobil[g].status == 'y') || (pinjemmobil[g].status == 'Y')){
						cout<<" (di Pinjam) "<<endl;
					}else{
						cout<<" (di kembalikan) "<<endl;
					}
					cout<<setw(12)<<pinjemmobil[g].dipinjem;
					cout<<endl;
				}
			}
		system("pause");
		system("cls");
		goto mulaimenu;


	}else if(pil == 6){
		cout<<"-- Anda Telah Logout -- \n";

		system("pause");
		system("cls");
		goto login;

	}else{
		system("cls");
		goto mulaimenu;
	}


}
