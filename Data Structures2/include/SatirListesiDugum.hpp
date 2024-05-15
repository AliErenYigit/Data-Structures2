/* 
* Dosya Adi:SatirListesiDugum.hpp
* SatirListeleri arasinda dugum kuran fonksiyonların baslik dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 12/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/

#ifndef SatirListesiDugum_hpp
#define SatirListesiDugum_hpp

#include <iostream>

using namespace std;

class SatirListesiDugum 
{
public:
    int veri;
    SatirListesiDugum *sonraki;
    SatirListesiDugum *onceki;

    SatirListesiDugum(const int veri, SatirListesiDugum *sonraki, SatirListesiDugum *onceki);
    SatirListesiDugum(const int veri, SatirListesiDugum *sonraki);
    SatirListesiDugum(const int veri);
};



#endif