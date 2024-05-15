/* 
* Dosya Adi:SatirListesi.cpp
* SatirListelerini içindeki veriler ile  olusturan fonksiyonların kaynak dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 11/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/


#include "SatirListesi.hpp"
#include "KonsolPozisyon.hpp"

SatirListesiDugum* SatirListesi::OncekiBul(int index)throw (NoSuchElement) 
{
    if (index < 0 || index > boyut) throw NoSuchElement("No such Element!!");
    SatirListesiDugum *oncekisi = ilk;
    int i = 1;
    for (SatirListesiDugum*itr = ilk; itr->sonraki != NULL && i != index; itr = itr->sonraki, i++) 
    {
        oncekisi = oncekisi->sonraki;
    }
    return oncekisi;
}

SatirListesi::SatirListesi() 
{
    ilk = NULL;
    boyut = 0;
}

int SatirListesi::boyutt()const 
{
    return boyut;
}

bool SatirListesi::bosmu()const 
{
    return boyut == 0;
}

void SatirListesi::ekle(const int& oge) 
{
    arayaEkle(boyut, oge);
}

void SatirListesi::arayaEkle(int index, const int& oge) 
{
    if (index < 0 || index > boyut) throw "Index Out of Range!!";
    if (index == 0) {
        ilk = new SatirListesiDugum(oge, ilk);
        if (ilk->sonraki != NULL) ilk->sonraki->onceki = ilk;
    } else {
        SatirListesiDugum *oncekisi = OncekiBul(index);
        oncekisi->sonraki = new SatirListesiDugum(oge, oncekisi->sonraki, oncekisi);
        if (oncekisi->sonraki->sonraki != NULL)
            oncekisi->sonraki->sonraki->onceki = oncekisi->sonraki;
    }
    boyut++;
}

const int& SatirListesi::ilki()throw (NoSuchElement) 
{
    if (bosmu()) throw NoSuchElement("No such Element!!");
    return ilk->veri;
}

const int& SatirListesi::sonuncusu()throw (NoSuchElement) 
{
    if (bosmu()) throw NoSuchElement("No such Element!!");
    return OncekiBul(boyut)->veri;
}

int SatirListesi::indexOf(const int& oge)throw (NoSuchElement) 
{
    int index = 0;
    for (SatirListesiDugum *itr = ilk; itr != NULL; itr = itr->sonraki) 
    {
        if (itr->veri == oge) return index;
        index++;
    }
    throw NoSuchElement("No such Element!!");
}

void SatirListesi::ogeCikar(const int& oge) 
{
    int index = indexOf(oge);
    aradanCikar(index);
}

void SatirListesi::aradanCikar(int index) 
{
    if (index < 0 || index >= boyut) throw "Index Out of Range!!";
    SatirListesiDugum *sil;
    if (index == 0) {
        sil = ilk;
        ilk = ilk->sonraki;
        if (ilk != NULL) ilk->sonraki = NULL;
    } else {
        SatirListesiDugum *oncekisi = OncekiBul(index);
        sil = oncekisi->sonraki;
        oncekisi->sonraki = sil->sonraki;
        if (sil->sonraki != NULL)
            sil->sonraki->onceki = oncekisi;
    }
    boyut--;
    delete sil;
}

bool SatirListesi::ogeBul(const int& oge) 
{
    for (SatirListesiDugum *itr = ilk; itr != NULL; itr = itr->sonraki) 
    {
        if (itr->veri == oge) return true;
    }
    return false;
}

void SatirListesi::tersi() 
{
    for (SatirListesiDugum *itr = ilk; itr != NULL;) 
    {
        SatirListesiDugum *gec = itr->sonraki;
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

const int& SatirListesi::elementAt(int index)throw (NoSuchElement) 
{
    if (index < 0 || index >= boyut) throw NoSuchElement("No such Element!!");

    if (index == 0) return ilk->veri;
    return OncekiBul(index)->sonraki->veri;
}

void SatirListesi::temizle() {
    while (!bosmu())
        aradanCikar(0);
}

ostream& operator <<(ostream& os, SatirListesi& sag) 
{

    for (SatirListesiDugum *itr = sag.ilk; itr != NULL; itr = itr->sonraki) 
    {
        
        os<<" "<<itr<<"\n";
       
        os<<"----------\n";
        os<<"|"<<setw(5)<<itr->veri<<setw(4)<<"|"<<endl;
        os<<"----------\n";
        os<<"|"<<itr->sonraki<<setw(2)<<"|\n";
        os<<"----------\n\n";
    }
    os << endl;
    return os;
}

void SatirListesi::yazdirTersDugum(int index)throw (NoSuchElement) 
{
    if (index < 0 || index >= boyut) throw NoSuchElement("No such Element!!");

    for (SatirListesiDugum *itr = OncekiBul(index + 1); itr != NULL; itr = itr->sonraki) 
    {
        
        cout << itr->veri << " <----> ";
    }
    cout << endl;
}

void SatirListesi::yazdirTersSirayi() 
{
    yazdirTersDugum(boyut - 1);
}
void SatirListesi::SatirListesiYazdir(int x,int y)
{
    int yIndex=y; 

    KonsolPozisyon.gotoxy(x,yIndex);
     
     cout<<"vvvvvvvvvv\n"; 
     

     for (SatirListesiDugum *itr = this->ilk; itr != NULL; itr = itr->sonraki) 
     {
      
        KonsolPozisyon.gotoxy(x,++yIndex);
        cout<<" "<<itr<<"\n";
        
        KonsolPozisyon.gotoxy(x,++yIndex);
        cout<<"----------\n";

        KonsolPozisyon.gotoxy(x,++yIndex);
        cout<<"|"<<setw(5)<<itr->veri<<setw(4)<<"|"<<endl;

        KonsolPozisyon.gotoxy(x,++yIndex);
        cout<<"----------\n";

        KonsolPozisyon.gotoxy(x,++yIndex);
        if(itr->sonraki==0)
        {
        cout<<"|00000000|"<<endl;
        }
        else
        {
        cout<<"|"<<setw(5)<<itr->sonraki<<"|"<<endl;
        }
        

        KonsolPozisyon.gotoxy(x,++yIndex);
        cout<<"----------\n\n";
    }
   
}

SatirListesi::~SatirListesi() 
{
    temizle();
}