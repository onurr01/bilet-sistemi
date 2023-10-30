#ifndef BILET_H
#define BILET_H

#include <iostream>
#include <string>
using namespace std;

class bilet {
friend void showInfos(bilet &Bilet);
friend ostream &operator<<(ostream &output,bilet &Bilet);
protected :
	
	int no ;	
	string name;
	string date ;
	string oclock ;
	int price ;
	int koltukSayisi;
	
	
public :
	void biletDuzenle(int numara, string isim,string tarih, string saat, int fiyat,int koltuk);
	explicit bilet (int numara=0 , string isim ="0",string tarih="0", string saat=" " , int fiyat=0,int koltuk=0);
	explicit bilet (int numara , string isim ,string tarih);
	~bilet();
	
	bilet &operator-=(int AzaltialcakMiktari);
	void KoltukSayisiAzalt(int AzaltialcakMiktari);

	void setkoltuk (int);
	

 	void setno (int);
 	
 	void setname (string);
 	
	void setdate(string);

	void setoclock(string);
	
	void setprice (int);
	
	int getkoltuk() const;
	
	int getno() const;

	string getname () const ;
	
	string getdate() const ;
	
	string getoclock () const ;
	
	int getprice() const ;

};
#endif
