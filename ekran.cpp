#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "ekran.h"
using namespace std;
void ekranlar::Giris()
{
	
	cout << "******************************" << endl;
    cout << "**     EBILET SITESINE      **" << endl;
    cout << "**          HOS             **" << endl;
    cout << "**        GELDINIZ          **" << endl;
    cout << "******************************" << endl;
    cout << endl;
    cout << endl;
    cout << "*****************************" << endl;
    cout << "**    1. Uye girisi        **" << endl;
    cout << "**    2. Yetkili girisi    **" << endl;
    cout << "*****************************" << endl;

}

void ekranlar::girisEkrani ()
{
	Baslangic();
	Giris();

	int secim;
	
	cout << "Lutfen secim yapiniz :";
	cin >> secim ;
    cout << endl;
    switch (secim)
    {
    	case 1:
    		etkinlikSecimEkrani();
    		break;
    	case 2:
    		AdminEkran();
    		break;
    	default:
    		cout<<"Yanlis Tuslama Yaptiniz!!"<<endl;
    		girisEkrani();
    		break;
    		
	}
}

void ekranlar::etkinlikSecimEkrani()
{
	int secim;
	cout << "1.Mac Biletleri"  << endl ;
	cout << "2.Sinema Biletleri" << endl ;
	cout << "3.Konser Biletleri"  << endl ;
	cout << "4.Geri Don"  << endl ;
	cout << endl ;
	
	cout << "Lutfen bilet turunu seciniz: " ;
	cin >> secim ;
	cout << endl ;
	cout << endl ;
	cout << endl ;
	cout << endl ;
				
	switch (secim)
	{
		case 1:
			macshowInfos();
		break;
		case 2:
			sinemashowInfos();
		break;
		case 3:
			konsershowInfos();
		break;
		case 4:
			girisEkrani();
		break;
		default:
			cout<<"Yanlis tercih yaptiniz!!"<<endl;
			etkinlikSecimEkrani();
		break;
	}
}
int ekranlar::macbiletTercihEkrani()
{
	int id;
	cout<<"[0] Geri Don"<<endl;
	cout<<"Bilet ID:";
	cin>>id;
	return id;
	
}
int ekranlar::konserbiletTercihEkrani()
{
	int id;
	cout<<"[0] Geri Don"<<endl;
	cout<<"Bilet ID:";
	cin>>id;
	return id;
	
}
int ekranlar::sinemabiletTercihEkrani()
{
	int id;
	

	cout<<"[0] Geri Don"<<endl;
	cout<<"Bilet ID:";
	cin>>id;
	return id;
	
}


void ekranlar::konsershowInfos ()
{
	int sayac,id;
	for (sayac=0;sayac<20;sayac++)
	{
		if(konserbiletler[sayac].getno()!=0)
		{
			cout<<konserbiletler[sayac]<<endl;
		}
		
	}
	id=konserbiletTercihEkrani();
	if (id==0)
	{
		etkinlikSecimEkrani();
		cout<<endl;
	}
	else
	{
		konserBiletAlmaEkrani(id);
	}
	

}
void ekranlar::sinemashowInfos()
{
	int sayac,id;
	for (sayac=0;sayac<20;sayac++)
	{
		if(sinemabiletler[sayac].getno()!=0)
		{
			cout<<sinemabiletler[sayac];
			cout<<endl;
		}
	}
	
	id=sinemabiletTercihEkrani();
		if (id==0)
	{
		etkinlikSecimEkrani();
	}
	else
	{
		sinemaBiletAlmaEkrani(id);
	}


}
void ekranlar::macshowInfos ()
{
	int id;
	int sayac;
	for (sayac=0;sayac<20;sayac++)
	{
		if(macbiletler[sayac].getno()!=0)
		{
			cout<<macbiletler[sayac]<<endl;
		}
	
		
	}
	id=macbiletTercihEkrani();
	if (id==0)
	{
		etkinlikSecimEkrani();
	}
	else
	{
		macBiletAlmaEkrani(id);	
	}
	
	
}
void ekranlar::sinemaBiletAlmaEkrani(int id)
{
	int miktar,toplamFiyat;
	cout<<"Lutfen almak istediginiz bilet miktarini giriniz:" << endl;
	cin >> miktar ;
			
	toplamFiyat = miktar * sinemabiletler[id].getprice() ;
			
	cout << "Odenecek tutar: "<< toplamFiyat << " TL"<< endl ;
	sinemabiletler[id]-=miktar;
	SinemaBiletiYaz();
	etkinlikSecimEkrani();
}
void ekranlar::konserBiletAlmaEkrani(int id)
{
	int miktar,toplamFiyat;
	cout<<"Lutfen almak istediginiz bilet miktarini giriniz:" << endl;
	cin >> miktar ;
			
	toplamFiyat = miktar * konserbiletler[id].getprice() ;
			
	cout << "Odenecek tutar: "<< toplamFiyat << " TL"<< endl ;
	konserbiletler[id]-=miktar;
	KonserBiletiYaz();
	etkinlikSecimEkrani();
}

void ekranlar::macBiletAlmaEkrani(int id)
{
	int miktar,toplamFiyat;
	cout<<"Lutfen almak istediginiz bilet miktarini giriniz:" << endl;
	cin >> miktar ;
			
	toplamFiyat = miktar * macbiletler[id].getprice() ;
			
	cout << "Odenecek tutar: "<< toplamFiyat << " TL"<< endl ;
	macbiletler[id]-=miktar;
	MacBiletiYaz();
	etkinlikSecimEkrani();
	
	
}




void ekranlar::macBiletiEkleme()
{
	static int sayi=1;	
	sayi=a1();
	string name;
	string date ;
	string oclock ;
	int price,koltuk ;
	cout<<"Mac Isimi: ";
	cin>>name;
	cout<<"Tarih: ";
	cin>>date;
	cout<<"Saat: ";
	cin>>oclock;
	cout<<"Fiyat: ";
	cin>>price;
	cout<<"Koltuk: ";
	cin>>koltuk;
	macbiletler[sayi].biletDuzenle(sayi,name,date,oclock,price,koltuk);
	MacBiletiYaz();
	sayi++;
	i1(sayi);
	AdminEkran();
}
void ekranlar::konserBiletiEkleme()
{
	static int sayi=1;
	sayi=a2();	
	string name;
	string date ;
	string oclock ;
	int price,koltuk ;
	cout<<"Konser Ismi: ";
	cin>>name;
	cout<<"Tarih: ";
	cin>>date;
	cout<<"Saat: ";
	cin>>oclock;
	cout<<"Fiyat: ";
	cin>>price;
	cout<<"Koltuk: ";
	cin>>koltuk;
	konserbiletler[sayi].biletDuzenle(sayi,name,date,oclock,price,koltuk);
	KonserBiletiYaz();
	sayi++;
	i2(sayi);
	AdminEkran();
}
void ekranlar::sinemaBiletiEkleme()
{
	static int sayi=1;
	sayi=a3();
	string name;
	string date ;
	string oclock ;
	int price ,koltuk;
	cout<<"Sinema isimi: ";
	cin>>name;
	cout<<"Tarih: ";
	cin>>date;
	cout<<"Saat: ";
	cin>>oclock;
	cout<<"Fiyat: ";
	cin>>price;
	cout<<"Koltuk: ";
	cin>>koltuk;
	sinemabiletler[sayi].biletDuzenle(sayi,name,date,oclock,price,koltuk);
	SinemaBiletiYaz();
	sayi++;
	i3(sayi);
	AdminEkran();
}

void ekranlar::AdminEkran()
{
	int secim;
	cout << "1.Mac Bileti "  << endl ;
	cout << "2.Sinema Bileti " << endl ;
	cout << "3.Konser Bileti "  << endl ;
	cout << "4.Geri Don"  << endl ;
	cout << endl ;
	
	cout << "Lutfen bilet turunu seciniz: " ;
	cin >> secim ;
	cout << endl ;
	cout << endl ;
	cout << endl ;
	cout << endl ;
				
	switch (secim)
	{
		case 1:
			macBiletiIslemleri();
		break;
		case 2:
			sinemaBiletiIslemleri();
		break;
		case 3:
			konserBiletiIslemleri();
		break;
		case 4:
			girisEkrani();
		break;
		default:
			cout<<"Yanlis tercih yaptiniz!!"<<endl;
			AdminEkran();
		break;
	}
}

void ekranlar::macBiletiDuzenle()
{
	int Id;
	int Fiyat,koltuk;
	string Isim,Tarih,Saat;

	cout<<"-Mac Bileti Duzenleme-"<<endl;
	cout<<"ID: ";
	cin>>Id;
	if(Id!=0 && macbiletler[Id].getno()!=0)
	{
		cout<<"Mac Isimi: ";
		cin>>Isim;
		cout<<"Tarih: ";
		cin>>Tarih;
		cout<<"Saat: ";
		cin>>Saat;
		cout<<"Fiyat: ";
		cin>>Fiyat;
		cout<<"Koltuk: ";
		cin>>koltuk;
		macbiletler[Id].biletDuzenle(Id,Isim,Tarih,Saat,Fiyat,koltuk);
		MacBiletiYaz();
	}
	else
	{
		cout<<"Mac Bileti Bulunamadi!"<<endl;
	}
	AdminEkran();
}

void ekranlar::konserBiletiDuzenle()
{
	int Id,koltuk;
	float Fiyat;
	string Isim,Tarih,Saat;

	cout<<"-Konser Bileti Duzenleme-"<<endl;
	cout<<"ID: ";
	cin>>Id;
	if(Id!=0 && konserbiletler[Id].getno()!=0)
	{
		cout<<"Konser Isimi: ";
		cin>>Isim;
		cout<<"Tarih: ";
		cin>>Tarih;
		cout<<"Saat: ";
		cin>>Saat;
		cout<<"Fiyat: ";
		cin>>Fiyat;
		cout<<"Koltuk: ";
		cin>>koltuk;
		konserbiletler[Id].biletDuzenle(Id,Isim,Tarih,Saat,Fiyat,koltuk);
		KonserBiletiYaz();
	}
	else
	{
		cout<<"Konser Bileti Bulunamadi!"<<endl;
	}
	AdminEkran();
}

void ekranlar::sinemaBiletiDuzenle()
{
	int Id,koltuk;
	float Fiyat;
	string Isim,Tarih,Saat;

	cout<<"-Sinema Bileti Duzenleme-"<<endl;
	cout<<"ID: ";
	cin>>Id;
	if(Id!=0 && sinemabiletler[Id].getno()!=0)
	{
		cout<<"Sinema Isimi: ";
		cin>>Isim;
		cout<<"Tarih: ";
		cin>>Tarih;
		cout<<"Saat: ";
		cin>>Saat;
		cout<<"Fiyat: ";
		cin>>Fiyat;
		cout<<"Koltuk: ";
		cin>>koltuk;
		sinemabiletler[Id].biletDuzenle(Id,Isim,Tarih,Saat,Fiyat,koltuk);
		SinemaBiletiYaz();
	}
	else
	{
		cout<<"Sinema Bileti Bulunamadi!"<<endl;
	}
	AdminEkran();
}

void ekranlar::macBiletiIslemleri()
{
	int secim;
	cout << "1.Mac Bileti Ekle "  << endl ;
	cout << "2.Mac Bileti Duzenle" << endl ;
	cout << "3.Mac Sil"  << endl ;
	cout << "4.Geri Don"  << endl ;
	cout << endl ;
	
	cout << "Lutfen bilet turunu seciniz: " ;
	cin >> secim ;
	cout << endl ;
	cout << endl ;
	cout << endl ;
	cout << endl ;
				
	switch (secim)
	{
		case 1:
			macBiletiEkleme();
		break;
		case 2:
			macBiletiDuzenle();
		break;
		case 3:
			macBiletiSil();
		break;
		case 4:
			AdminEkran();
		break;
		default:
			cout<<"Yanlis tercih yaptiniz!!"<<endl;
			macBiletiIslemleri();
		break;
	}
}

void ekranlar::konserBiletiIslemleri()
{
		int secim;
	cout << "1.Konser Bileti Ekle "  << endl ;
	cout << "2.Konser Bileti Duzenle" << endl ;
	cout << "3.Konser Sil"  << endl ;
	cout << "4.Geri Don"  << endl ;
	cout << endl ;
	
	cout << "Lutfen bilet turunu seciniz: " ;
	cin >> secim ;
	cout << endl ;
	cout << endl ;
	cout << endl ;
	cout << endl ;
				
	switch (secim)
	{
		case 1:
			konserBiletiEkleme();
		break;
		case 2:
			konserBiletiDuzenle();
		break;
		case 3:
			konserBiletiSil();
		break;
		case 4:
			AdminEkran();
		break;
		default:
			cout<<"Yanlis tercih yaptiniz!!"<<endl;
			konserBiletiIslemleri();
		break;
	}
}
void ekranlar::sinemaBiletiIslemleri()
{
	int secim;
	cout << "1.Sinema Bileti Ekle "  << endl ;
	cout << "2.Sinema Bileti Duzenle" << endl ;
	cout << "3.Sinema Sil"  << endl ;
	cout << "4.Geri Don"  << endl ;
	cout << endl ;
	
	cout << "Lutfen bilet turunu seciniz: " ;
	cin >> secim ;
	cout << endl ;
	cout << endl ;
	cout << endl ;
	cout << endl ;
				
	switch (secim)
	{
		case 1:
			sinemaBiletiEkleme();
		break;
		case 2:
			sinemaBiletiDuzenle();
		break;
		case 3:
			sinemaBiletiSil();
		break;
		case 4:
			AdminEkran();
		break;
		default:
			cout<<"Yanlis tercih yaptiniz!!"<<endl;
			sinemaBiletiIslemleri();
		break;
	}
}

void ekranlar::macBiletiSil()
{
	int Id;
	cout<<"-Mac Bileti Sil-"<<endl;
	cout<<"ID: ";
	cin>>Id;
	macbiletler[Id].~bilet();
	MacBiletiYaz();
	macBiletiIslemleri();
	
}

void ekranlar::konserBiletiSil()
{
	int Id;
	cout<<"-Konser Bileti Sil-"<<endl;
	cout<<"ID: ";
	cin>>Id;
	konserbiletler[Id].~bilet();
	KonserBiletiYaz();
	konserBiletiIslemleri();
}

void ekranlar::sinemaBiletiSil()
{
	int Id;
	cout<<"-Sinema Bileti Sil-"<<endl;
	cout<<"ID: ";
	cin>>Id;
	sinemabiletler[Id].~bilet();
	SinemaBiletiYaz();
	sinemaBiletiIslemleri();
}

void ekranlar::MacBiletiYaz()
{
	int i;
	remove("MacBiletleri.txt");
	ofstream MacBileti;
	MacBileti.open("MacBiletleri.txt",ios::app);
	for(i=1;i<20;++i)
	{
		if(macbiletler[i].getno()!=0)
		{
			MacBileti<<endl<<macbiletler[i].getno()<<setw(20)<<macbiletler[i].getname()<<setw(20)<<macbiletler[i].getdate()<<setw(20)<<macbiletler[i].getoclock()<<setw(20)<<macbiletler[i].getprice()<<setw(20)<<macbiletler[i].getkoltuk();
		}
	}
}

void ekranlar::MacBiletiYukle()
{
	int numara,koltuk;
	float fiyat;
	string saat,isim,tarih;
	ifstream MacBiletiY("MacBiletleri.txt");
	while(!(MacBiletiY.eof()))
	{
		MacBiletiY>>numara>>isim>>tarih>>saat>>fiyat>>koltuk;
		macbiletler[numara].biletDuzenle(numara,isim,tarih,saat,fiyat,koltuk);
	}
	MacBiletiY.close();
}

void ekranlar::SinemaBiletiYaz()
{
	int i;
	remove("SinemaBiletleri.txt");
	ofstream SinemaBileti;
	SinemaBileti.open("SinemaBiletleri.txt",ios::app);
	for(i=1;i<20;++i)
	{
		if(sinemabiletler[i].getno()!=0)
		{
			SinemaBileti<<endl<<sinemabiletler[i].getno()<<setw(20)<<sinemabiletler[i].getname()<<setw(20)<<sinemabiletler[i].getdate()<<setw(20)<<sinemabiletler[i].getoclock()<<setw(20)<<sinemabiletler[i].getprice()<<setw(20)<<sinemabiletler[i].getkoltuk();
		}
	}
}

void ekranlar::SinemaBiletiYukle()
{
	int numara,koltuk;
	float fiyat;
	string saat,isim,tarih;
	ifstream SinemaBiletiY("SinemaBiletleri.txt");
	while(!(SinemaBiletiY.eof()))
	{
		SinemaBiletiY>>numara>>isim>>tarih>>saat>>fiyat>>koltuk;
		sinemabiletler[numara].biletDuzenle(numara,isim,tarih,saat,fiyat,koltuk);
	}
	SinemaBiletiY.close();
}

void ekranlar::KonserBiletiYaz()
{
	int i;
	remove("KonserBiletleri.txt");
	ofstream KonserBileti;
	KonserBileti.open("KonserBiletleri.txt",ios::app);
	for(i=1;i<20;++i)
	{
		if(konserbiletler[i].getno()!=0)
		{
			KonserBileti<<endl<<konserbiletler[i].getno()<<setw(20)<<konserbiletler[i].getname()<<setw(20)<<konserbiletler[i].getdate()<<setw(20)<<konserbiletler[i].getoclock()<<setw(20)<<konserbiletler[i].getprice()<<setw(20)<<konserbiletler[i].getkoltuk();
		}
	}
}

void ekranlar::KonserBiletiYukle()
{
	int numara,koltuk;
	float fiyat;
	string saat,isim,tarih;
	ifstream KonserBiletiY("KonserBiletleri.txt");
	while(!(KonserBiletiY.eof()))
	{
		KonserBiletiY>>numara>>isim>>tarih>>saat>>fiyat>>koltuk;
		konserbiletler[numara].biletDuzenle(numara,isim,tarih,saat,fiyat,koltuk);
	}
	KonserBiletiY.close();
}

void ekranlar::i1(int a)
{
	remove("i1.txt");
	ofstream ia1;
	ia1.open("i1.txt",ios::app);
	ia1<<a;
}

int ekranlar::a1()
{
	int a;
	ifstream ai1("i1.txt");
	ai1>>a;
	
	
	return a;
}
void ekranlar::i2(int a)
{
	remove("i2.txt");
	ofstream ia2;
	ia2.open("i2.txt",ios::app);
	ia2<<a;
}

int ekranlar::a2()
{
	int a;
	ifstream ai2("i2.txt");
	ai2>>a;
	return a;
}
void ekranlar::i3(int a)
{
	remove("i3.txt");
	ofstream ia3;
	ia3.open("i3.txt",ios::app);
	ia3<<a;
}

int ekranlar::a3()
{
	int a;
	ifstream ai3("i3.txt");
	ai3>>a;
	return a;
}

void ekranlar::Baslangic()
{
	ofstream MacBileti;
	MacBileti.open("MacBiletleri.txt",ios::app);
	MacBileti.close();
	ofstream SinemaBileti;
	SinemaBileti.open("SinemaBiletleri.txt",ios::app);
	SinemaBileti.close();
	ofstream KonserBileti;
	KonserBileti.open("KonserBiletleri.txt",ios::app);
	KonserBileti.close();
	ofstream ia1;
	ia1.open("i1.txt",ios::app);
	ia1.close();
	ofstream ia2;
	ia2.open("i2.txt",ios::app);
	ia2.close();
	ofstream ia3;
	ia3.open("i3.txt",ios::app);
	ia3.close();
	KonserBiletiYukle();
	MacBiletiYukle();
	SinemaBiletiYukle();
	
}
