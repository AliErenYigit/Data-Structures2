/* 
* Dosya Adi:Main.cpp
* Dosyayi yazdiran ve konsol ekranindaki hareketleri kontrol eden fonksiyonlarin kaynak dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 13/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit==>  eren.yigit@ogr.sakarya.edu.tr
*/

#include <cstdlib>
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "DosyaYazdir.hpp"
#include "KonsoldaGoster.hpp"
#include "Exception.hpp"

using namespace std;


int main(int argc, char** argv) 
{

    DosyaYazdir * dosyaOku = new DosyaYazdir("veriler.txt");

    YoneticiListesi *yoneticiListesi = dosyaOku->GetFillYoneticiListesi();

    KonsoldaGoster *console = new KonsoldaGoster(yoneticiListesi);
    yoneticiListesi->ortSirala();
    string giris = "";
    do {
        console->yazdirYoneticiListesi();
        cin>>giris;
        if (giris == "c") 
        {
            yon yonu = yukari;
            console->ifadeAyarla(yonu);
        } else if (giris == "z") 
        {
            yon yonu = asagi;
            console->ifadeAyarla(yonu);
        } else if (giris == "k") 
        {
            int rastgeleIndex = 0;
            try {
                rastgeleIndex = console->rastgeleSecilenDugumGoster();
            } catch (...) 
            {
                continue;

            }
            cin>>giris;
            if (giris == "k") 
            {

                console->rastgeleSecilenDugumSil(rastgeleIndex);
                yoneticiListesi->ortSirala();

            }
        } 
        else if (giris == "p") 
        {
            console->YoneticiDugumSil();
        } 
        else if (giris == "d") 
        {
            console->sayfaAyarla(sayfaYukari);
        } 
        else if (giris == "a") 
        {
            console->sayfaAyarla(sayfaAsagi);
        }


    } 
    while (giris != "q");



    return 0;



}