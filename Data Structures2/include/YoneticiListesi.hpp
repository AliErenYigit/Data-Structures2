/* 
* Dosya Adi:YoneticiListesi.hpp 
* YoneticiListelerini olusturan fonksiyonların baslik dosyasi.
* 2.sinif 1-C Sinifi
* 1.Odev
* 15/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/

#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp

#include <iostream>
#include "SatirListesi.hpp"
#include "YoneticiDugum.hpp"
#include <stdlib.h>     
#include <time.h>       
#include "IndexOutOfBounds.hpp"
#include "KonsolPozisyon.hpp"

class YoneticiListesi 
{
private:
    YoneticiDugum *ilk;
    int boyut;

    YoneticiDugum* oncekiKonumuBul(int index)throw (NoSuchElement);
    YoneticiDugum* BulKonumu(int index)throw (NoSuchElement);

public:

    YoneticiListesi();
    int boyutu()const;
    bool bosmu()const;
    void ekle(SatirListesi*& oge);
    void arayaEkle(int index, SatirListesi*& oge);
    SatirListesi*& ilki()throw (NoSuchElement);
    SatirListesi*& sonuncusu()throw (NoSuchElement);
    int indexOf(SatirListesi*& oge)throw (NoSuchElement);
    void cikar(SatirListesi*& oge);
    void rasgeleSatirListesiAradanSil(int index, int satirIciIndex)throw (IndexOutOfBounds, NoSuchElement);
    void ortHesap(int index);
    int rastgele(int index)throw (IndexOutOfBounds, NoSuchElement);
    void aradanKaldir(int index);
    void dugumIleriGeri(int from, int to)throw (IndexOutOfBounds);
    bool ogeBul(SatirListesi*& oge);
    void tersYap();
    void ortSirala();
    SatirListesi*& elementAt(int index)throw (NoSuchElement);
    void temizle();
    void indexYazdir(int index, int x, int y);
    ~YoneticiListesi();

};


#endif