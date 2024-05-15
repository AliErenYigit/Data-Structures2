/* 
* Dosya Adi:KonsoldaGoster.cpp 
* Verileri konsolda gösterin kodlarin kaynak dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 16/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/

#include "KonsoldaGoster.hpp"

KonsoldaGoster::KonsoldaGoster(YoneticiListesi* yoneticiListe) 
{
    this->yoneticiListe = yoneticiListe;
    if (this->yoneticiListe->boyutu() <GoruntulenenSayfa) 
    {
        this->bitir = this->yoneticiListe->boyutu();
    } 
    else 
    {
        this->bitir =GoruntulenenSayfa;
    }

    this->baslat = baslat;

}

void KonsoldaGoster::denklestir()
{
    int sayfa = ifade /GoruntulenenSayfa;
    this->baslat =GoruntulenenSayfa*sayfa;
    this->bitir =GoruntulenenSayfa * (sayfa + 1);
    if (this->bitir >= this->yoneticiListe->boyutu()) 
    {
        this->bitir = this->yoneticiListe->boyutu();

    }
}

void KonsoldaGoster::ifadeAyarla(yon yn) 
{

    if (yn == yukari) 
    {
        if (ifade >= this->yoneticiListe->boyutu() - 1) 
        {
            return;
        }
        ++ifade;
        denklestir();
    } 
    else if (yn == asagi) 
    {
        if (ifade <= 0) 
        {

            return;
        }
        --ifade;
        denklestir();
    } 
    else if (yn == yenile) 
    {
        denklestir();
    }

}

void KonsoldaGoster::sayfaAyarla(sayfaYon syn) 
{
    if (syn == sayfaAsagi) 
    {
        for (int i = 0; i <GoruntulenenSayfa; ++i) 
        {
            this->ifadeAyarla(asagi);
        }
    } else if (syn == sayfaYukari) 
    {
        for (int i = 0; i <GoruntulenenSayfa; ++i) 
        {
            this->ifadeAyarla(yukari);
        }
    }
}

void KonsoldaGoster::yazdirYoneticiListesi() 
{

    int boyut = yoneticiListe->boyutu();
    system("cls");
    if (boyut == 0) 
    {
        cout << "YoneticiListesi bulunamadi!!\n";
        exit(1);
        return;
    }
    KonsolPozisyon.gotoxy(0, 0);
    if (this->baslat == 0) 
    {
        cout << "<===ilk sayfa===|";
       
    } 
    else 
    {
        cout << "<===geri git===|";
       
    }
    int dugumSayisiGoster = this->bitir - this->baslat;
    dugumSayisiGoster *= 13;

    KonsolPozisyon.gotoxy(dugumSayisiGoster, 0);

    if (this->bitir == yoneticiListe->boyutu()) 
    {
        cout << "|===son sayfa===>";
       
    } 
    else 
    {
        cout << "|===ileri git===>";
        
    }
    for (int i = this->baslat; i<this->bitir; ++i) 
    {
        int mod = i %GoruntulenenSayfa;
        this->yoneticiListe->indexYazdir(i, 15 * mod, 1);

    }
    this->secilenSatirListesiYazdir((this->ifade %GoruntulenenSayfa) *15, 9);
}

 void KonsoldaGoster::secilenSatirListesiYazdir(int x, int y) 
 {
        this->yoneticiListe->elementAt(this->ifade)->SatirListesiYazdir(x, y);
 }
  int KonsoldaGoster::rastgeleSecilenDugumGoster()throw (IndexOutOfBounds, NoSuchElement) 
  {

        int rastgeleSec = this->yoneticiListe->rastgele(this->ifade);
        int xPozisyon = ((this->ifade %GoruntulenenSayfa) + 1)*15;
        int yPozisyon = (rastgeleSec)*6;
        yPozisyon += 12;
        KonsolPozisyon.gotoxy(xPozisyon, yPozisyon);
        cout << "<==== Bu SatirListesinin silinmesi icin tekrar 'k' giriniz..";
        
        yPozisyon = this->yoneticiListe->elementAt(this->ifade)->boyutt()*6 + 12;

        KonsolPozisyon.gotoxy(0, yPozisyon - 1);


        return rastgeleSec;

    }
  void KonsoldaGoster::YoneticiDugumSil() 
  {
     this->yoneticiListe->aradanKaldir(this->ifade);
     this->ifadeAyarla(yenile);
      
        if(this->ifade==this->bitir)
        {
            this->ifade--;
        }
    this->ifadeAyarla(yenile);

   

    }
  void KonsoldaGoster::rastgeleSecilenDugumSil(int rastgeleIndex)throw (IndexOutOfBounds, NoSuchElement) 
  {
        this->yoneticiListe->rasgeleSatirListesiAradanSil(this->ifade, rastgeleIndex);
    }