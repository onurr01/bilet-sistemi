#include <iostream>
#include <stdexcept>
#include "bilet.h"
using namespace std ;

ostream &operator<<(ostream &output,bilet &Bilet)
{
	output<<"Bilet No    : " << Bilet.getno() << endl 
		  << "Bilet Adi   : " << Bilet.getname() << endl
		  << "Bilet Tarihi: " << Bilet.getdate() << endl
		  << "Bilet Saati : " << Bilet.getoclock()<< endl 
		  <<"Kalan Koltuk Sayisi: "<<Bilet.getkoltuk()<<endl
		  << "Bilet Ucreti: " << Bilet.getprice() << " TL"<<endl;
	
	return output;
}

bilet &bilet::operator-=(int AzaltialcakMiktari)
{
	KoltukSayisiAzalt(AzaltialcakMiktari);
	return *this;
}

bilet::bilet (int numara , string isim ,string tarih, string saat , int fiyat,int koltuk)
{
	no = numara ;
	name = isim ;
	date = tarih;
	oclock =saat;
	price =fiyat;
	koltukSayisi=koltuk;
}

bilet::bilet (int numara , string isim ,string tarih)
{
	no = numara ;
	name = isim ;
	date = tarih;

}

bilet::~bilet()
{
	biletDuzenle(0,"0","0","0",0,0);
	cout<<"Bilet Silindi!"<<endl;
}

	void bilet::setno(int _no)
	{
		no = _no;
	}
		void bilet::setname(string _name)
	{
		name = _name;
	}
	void bilet::setprice(int _price)
	{
		price = price ;
	}
	void bilet::setoclock(string _oclock)
	{
		oclock = _oclock;
	} 
	void bilet::setdate(string _date)
	{
		date = _date;
	}
	  
	  
	  
	int bilet::getno() const 
	{
		return no;
	}
	string bilet::getname() const
	{
		return name ;
	}
	string bilet::getdate() const 
	{ 
		return date;
	}
	string bilet::getoclock() const 
	{
		return oclock;
	}
	int bilet::getprice() const
	{
		return price ;
	}

void bilet::biletDuzenle(int numara, string isim,string tarih, string saat, int fiyat,int koltuk)
{
	no = numara ;
	name = isim ;
	date = tarih;
	oclock =saat;
	price =fiyat;
	koltukSayisi=koltuk;
}

void bilet::setkoltuk (int _koltuk)
{
	koltukSayisi=_koltuk;
}
int bilet::getkoltuk() const
{
	return koltukSayisi;
}

// koltuk deðiþiklelri bilgi göster friend de göre
void showInfos (bilet &Bilet)
{
	if(Bilet.getno()!=0)
	{
		cout << "Bilet No    : " << Bilet.getno() << endl ;
		cout << "Bilet Adi   : " << Bilet.getname() << endl;
		cout << "Bilet Tarihi: " << Bilet.getdate() << endl;
		cout << "Bilet Saati : " << Bilet.getoclock()<< endl ;
		cout<<"Kalan Koltuk Sayisi: "<<Bilet.getkoltuk();
		cout << "Bilet Ucreti: " << Bilet.getprice() << " TL"<< endl ;
		cout<<endl;
	}
}

void bilet::KoltukSayisiAzalt(int AzaltialcakMiktari)
{
	int Miktar;
	Miktar=getkoltuk();
	Miktar-=AzaltialcakMiktari;
	setkoltuk(Miktar);
}

