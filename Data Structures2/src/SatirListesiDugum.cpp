/* 
* Dosya Adi:SatilListesiDugum.cpp
* SatirListeleri arasinda dugum kuran fonksiyonların kaynak dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 14/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/

#include "SatirListesiDugum.hpp"

SatirListesiDugum::SatirListesiDugum(const int veri, SatirListesiDugum *sonraki , SatirListesiDugum *onceki ) 
{
    this->veri = veri;
    this->sonraki = sonraki;
    this->onceki = onceki;
}
SatirListesiDugum::SatirListesiDugum(const int veri, SatirListesiDugum *sonraki) 
{
    this->veri = veri;
    this->sonraki = sonraki;
    this->onceki = onceki;
}
SatirListesiDugum::SatirListesiDugum(const int veri) 
{
    this->veri = veri;
    this->sonraki = sonraki;
    this->onceki = onceki;
}