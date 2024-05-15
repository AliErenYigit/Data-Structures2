/* 
* Dosya Adi:YoneticiListesi.cpp
* YoneticiListelerini icindeki verilerle olusturan fonksiyonların kaynak dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 17/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==>eren.yigit@ogr.sakarya.edu.tr
*/

#include "YoneticiListesi.hpp"

YoneticiDugum* YoneticiListesi::oncekiKonumuBul(int index)throw (NoSuchElement)
 {
    if (index < 0 || index > boyut) throw NoSuchElement("No Such Element!!");
    YoneticiDugum *oncekisi = ilk;
    int i = 1;
    for (YoneticiDugum *itr = ilk; itr->sonraki != NULL && i != index; itr = itr->sonraki, i++)
    {
        oncekisi = oncekisi->sonraki;
    }
    return oncekisi;
}

YoneticiDugum* YoneticiListesi::BulKonumu(int index)throw (NoSuchElement) 
{
    if (index < 0 || index >= boyut) throw NoSuchElement("No Such Element!!");
    return this->oncekiKonumuBul(index + 1);

}

YoneticiListesi::YoneticiListesi() 
{
    ilk = NULL;
    boyut = 0;
}

int YoneticiListesi::boyutu()const 
{
    return boyut;
}

bool YoneticiListesi::bosmu()const 
{
    return boyut == 0;
}

void YoneticiListesi::ekle(SatirListesi*& oge) 
{
    arayaEkle(boyut, oge);
}

void YoneticiListesi::arayaEkle(int index, SatirListesi*& oge) 
{
    if (index < 0 || index > boyut)
     throw "Index Out of Range!!";
    if (index == 0) 
    {
        ilk = new YoneticiDugum(oge, ilk);
        if (ilk->sonraki != NULL) ilk->sonraki->onceki = ilk;
    } 
    else 
    {
        YoneticiDugum *oncekisi = oncekiKonumuBul(index);
        oncekisi->sonraki = new YoneticiDugum(oge, oncekisi->sonraki, oncekisi);
        if (oncekisi->sonraki->sonraki != NULL)
        {
            oncekisi->sonraki->sonraki->onceki = oncekisi->sonraki;
        }
            
    }
    boyut++;
}

SatirListesi*& YoneticiListesi::ilki()throw (NoSuchElement) 
{
    if (bosmu()) throw NoSuchElement("No such Element!!");
    return ilk->veri;
}

SatirListesi*& YoneticiListesi::sonuncusu()throw (NoSuchElement) 
{
    if (bosmu()) throw NoSuchElement("No such Element!!");
    return oncekiKonumuBul(boyut)->veri;
}

int YoneticiListesi::indexOf(SatirListesi*& oge)throw (NoSuchElement) 
{
    int index = 0;
    for (YoneticiDugum *itr = ilk; itr != NULL; itr = itr->sonraki) 
    {
        if (itr->veri == oge) return index;
        index++;
    }
    throw NoSuchElement("No such Element!!");
}

void YoneticiListesi::cikar(SatirListesi*& oge) 
{
    int index = indexOf(oge);
    aradanKaldir(index);
}

void YoneticiListesi::rasgeleSatirListesiAradanSil(int index, int satirIciIndex)throw (IndexOutOfBounds, NoSuchElement) 
{

    int boyut = this->boyutu();
    if (index < 0 || index >= boyut)
        throw IndexOutOfBounds("Index Out of Bounds!!");

    SatirListesi* satirListesi = this->elementAt(index);

    satirListesi->aradanCikar(satirIciIndex);
    ortHesap(index);

}

void YoneticiListesi::ortHesap(int index) 
{
    YoneticiDugum* YoneticiDugum = this->BulKonumu(index);

    if (YoneticiDugum == NULL) 
    {
      throw "!!!Hata!!!";
    }


    double toplam = 0;
    if (YoneticiDugum->veri->bosmu()) 
    {
        YoneticiDugum->ort = toplam;
        return;
    }


    int boyut = YoneticiDugum->veri->boyutt();
    for (int i = 0; i < boyut; ++i) 
    {
        toplam += YoneticiDugum->veri->elementAt(i);
    }
    YoneticiDugum->ort = toplam / boyut;



}

int YoneticiListesi::rastgele(int index)throw (IndexOutOfBounds, NoSuchElement) 
{
    int boyut = this->boyutu();

    if (index < 0 || index >= boyut)
        throw IndexOutOfBounds("Index Out of Bounds!!");

    srand(time(NULL));
    SatirListesi* satirListesi = this->elementAt(index);

    int aralik = satirListesi->boyutt();
    if (aralik == 0) 
    {
        throw NoSuchElement("No such Element!!");
    }
    int satirIciIndex = rand() % aralik;

    return satirIciIndex;
}

void YoneticiListesi::aradanKaldir(int index) 
{
    if (index < 0 || index >= boyut) throw "Index Out of Range!!";
    YoneticiDugum *sil;
    if (index == 0) 
    {
        sil = ilk;
        ilk = ilk->sonraki;
        if (ilk != NULL) ilk->onceki = NULL;
    } 
    else 
    {
        YoneticiDugum *oncekisi = oncekiKonumuBul(index);
        sil = oncekisi->sonraki;
        oncekisi->sonraki = sil->sonraki;
        if (sil->sonraki != NULL)
            sil->sonraki->onceki = oncekisi;
    }
    boyut--;
    delete sil;
}

void YoneticiListesi::dugumIleriGeri(int from, int to)throw (IndexOutOfBounds) 
{
    if (from < 0 || from >= boyut) throw IndexOutOfBounds("Index Out of Bound!!");
    YoneticiDugum *sil;
    if (from == 0) 
    {
        
        sil = ilk;
        ilk = ilk->sonraki;
        if (ilk != NULL) ilk->onceki = NULL;
    } else {
        YoneticiDugum *oncekisi = oncekiKonumuBul(from);
        sil = oncekisi->sonraki;
        oncekisi->sonraki = sil->sonraki;
        if (sil->sonraki != NULL)
            sil->sonraki->onceki = oncekisi;
    }
    boyut--;
    if (to < 0 || to > boyut) throw "Index Out of Range!!";
    if (to == 0) 
    {
        
        sil->sonraki = ilk;
        sil->onceki = NULL;
        ilk = sil;
        if (ilk->sonraki != NULL) ilk->sonraki->onceki = ilk;
    } 
    else 
    {
        YoneticiDugum *oncekisi = oncekiKonumuBul(to);

        sil->sonraki = oncekisi->sonraki;
        sil->onceki = oncekisi;
        oncekisi->sonraki = sil;
        if (oncekisi->sonraki->sonraki != NULL)
        {
            oncekisi->sonraki->sonraki->onceki = oncekisi->sonraki;
        }
            
    }
    boyut++;
}

bool YoneticiListesi::ogeBul(SatirListesi*& oge) 
{
    for (YoneticiDugum *itr = ilk; itr != NULL; itr = itr->sonraki) 
    {
        if (itr->veri == oge) return true;
    }
    return false;
}

void YoneticiListesi::tersYap() 
{
    for (YoneticiDugum *itr = ilk; itr != NULL;) 
    {
        YoneticiDugum *gec = itr->sonraki;
        itr->sonraki = itr->onceki;
        itr->onceki = gec;
        if (gec == NULL) 
        {
            ilk = itr;
            break;
        }
        itr = gec;
    }
}

void YoneticiListesi::ortSirala() 
{
    if (this->boyut <= 1)
        return;

    for (int basamak = 0; basamak < boyut; ++basamak) 
    {


        for (int i = 0; i < boyut - basamak - 1; ++i) 
        {
            YoneticiDugum *gec = this->BulKonumu(i);
            YoneticiDugum *gecc = gec->sonraki;

            if (gec->ort > gecc->ort) 
            {


                this->dugumIleriGeri(i + 1, i);
            }
        }
    }

}

SatirListesi*& YoneticiListesi::elementAt(int index)throw (NoSuchElement) 
{
    if (index < 0 || index >= boyut) throw NoSuchElement("No such Element!!");
    if (index == 0) return ilk->veri;
    return oncekiKonumuBul(index)->sonraki->veri;
}

void YoneticiListesi::temizle() 
{
    while (!bosmu())
        aradanKaldir(0);
}

void YoneticiListesi::indexYazdir(int index, int x, int y) 
{
    YoneticiDugum *dugum = this->BulKonumu(index);
    KonsolPozisyon.gotoxy(x, y);
    cout << fixed << setprecision(2);
    cout <<" "<< dugum << "\n";

    KonsolPozisyon.gotoxy(x,y+1 ); 
    cout << "----------\n";

    KonsolPozisyon.gotoxy(x,y+2);

   
    if(dugum->onceki==0)
    {
    cout <<"|00000000|\n";
    }
    else
    {
    cout <<"|"<< dugum->onceki << "|\n";
    }



    KonsolPozisyon.gotoxy(x,y+3);
    cout << "----------\n";

    KonsolPozisyon.gotoxy(x,y+4);
    cout << "|"  << dugum->ort << setw(4) << "|" << endl;

    KonsolPozisyon.gotoxy(x,y+5);
    cout << "----------\n";

    KonsolPozisyon.gotoxy(x,y+6);
    cout << "|" << dugum->sonraki << setw(2) << "|\n";

    KonsolPozisyon.gotoxy(x,y+7);
    cout << "----------\n\n";

}

YoneticiListesi::~YoneticiListesi() 
{
    temizle();
}