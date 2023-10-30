#ifndef EKRAN_H
#define EKRAN_H
#include <iostream>
#include "bilet.h"
#include "macbilet.h"
#include "sinemabilet.h"
#include "konserbilet.h"
using namespace std ;
#include <string>

class ekranlar {
	public :
	static void Giris();
	void AdminEkran();
	void girisEkrani ();
	void biletTercihEkrani();
	void odemeEkrani();
	
	void macBiletiIslemleri();
	void konserBiletiIslemleri();
	void sinemaBiletiIslemleri();
	
	void macBiletiEkleme();
	void konserBiletiEkleme();
	void sinemaBiletiEkleme();

	void macBiletiDuzenle();
	void konserBiletiDuzenle();
	void sinemaBiletiDuzenle();
	
	void macBiletiSil();
	void konserBiletiSil();
	void sinemaBiletiSil();
	
	void etkinlikSecimEkrani();
	
	int macbiletTercihEkrani();
	int konserbiletTercihEkrani();
	int sinemabiletTercihEkrani();
	
	void sinemaBiletAlmaEkrani(int id);
	void konserBiletAlmaEkrani(int id);
	void macBiletAlmaEkrani(int id);
	
	void macshowInfos ();
	void sinemashowInfos ();
	void konsershowInfos ();
	
	void MacBiletiYaz();
	void MacBiletiYukle();
	void SinemaBiletiYaz();
	void SinemaBiletiYukle();
	void KonserBiletiYaz();
	void KonserBiletiYukle();
	
	void i1(int a);
	int a1();
	void i2(int a);
	int a2();
	void i3(int a);
	int a3();
	
	void Baslangic();
	private:
		sinemabilet sinemabiletler[20];
		macbilet macbiletler[20];
		konserbilet konserbiletler[20];

		
};

#endif
