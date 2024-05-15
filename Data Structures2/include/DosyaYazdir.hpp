/* 
* Dosya Adi:DosyaYazdir.hpp
* Dosya icindeki verileri yazdiran fonsiyonlarin baslik dosyasi.
* 2.sinif 1-C Sinifi
* 1.Odev
* 22/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/

#ifndef DosyaYazdir_hpp
#define DosyaYazdir_hpp

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"

class DosyaYazdir 
{
private:
    string dosyaAdi;
    int satirBoyutu();
    SatirListesi **satir;
    void readLine();
public:
    DosyaYazdir(string);
    ~DosyaYazdir();
    YoneticiListesi* GetFillYoneticiListesi();
};

#endif