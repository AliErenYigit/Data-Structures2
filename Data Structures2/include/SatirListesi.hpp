/* 
* Dosya Adi:SatirListesi.hpp
* SatirListelerini olusturan fonksiyonların baslik dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 11/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/

#ifndef SatirListesi_hpp
#define SatirListesi_hpp

#include "SatirListesiDugum.hpp"
#include "NoSuchElement.hpp"
#include <iomanip>

class SatirListesi
{
private:
    SatirListesiDugum *ilk;
    int boyut;

    SatirListesiDugum* OncekiBul(int index)throw (NoSuchElement);
public:
    SatirListesi();
    int boyutt()const;
    bool bosmu()const;
    void ekle(const int& oge);
    void arayaEkle(int index, const int& oge);
    const int& ilki()throw (NoSuchElement);
    const int& sonuncusu()throw (NoSuchElement);
    int indexOf(const int& oge)throw (NoSuchElement);
    void ogeCikar(const int& oge);
    void aradanCikar(int index);
    bool ogeBul(const int& oge);
    void tersi();
    const int& elementAt(int index)throw (NoSuchElement);
    void temizle();
    friend ostream& operator<<(ostream& ekran, SatirListesi& sag);
    void yazdirTersDugum(int index)throw (NoSuchElement);
    void yazdirTersSirayi();
    void SatirListesiYazdir(int x, int y);
    ~SatirListesi();

};


#endif