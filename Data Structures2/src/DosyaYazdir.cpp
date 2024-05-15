/* 
* Dosya Adi:DosyaYazdir.cpp
* Dosya icindeki verileri yazdiran fonsiyonlar.
* 2.sinif 1-C Sinifi
* 1.Odev
* 23/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/




#include "DosyaYazdir.hpp"

YoneticiListesi* DosyaYazdir::GetFillYoneticiListesi()
{
    readLine();
    YoneticiListesi *gec=new YoneticiListesi();
    int boyut=satirBoyutu();
    for(int i=0;i<boyut;++i){
        gec->ekle(this->satir[i]);
    }
    return gec;
    
}



DosyaYazdir::DosyaYazdir(string dosyaAdi) 
{
    this->dosyaAdi = dosyaAdi;


    int satirNo = satirBoyutu();
    this->satir = new SatirListesi*[satirNo];
    for (int i = 0; i < satirNo; i++) 
    {
    
        this->satir[i] = new SatirListesi();
    }
}

int DosyaYazdir::satirBoyutu() 
{
    int counter = 0;
    ifstream file(this->dosyaAdi);
    string unused;
    while (getline(file, unused))
        ++counter;

    file.close();
    return counter;
}

void DosyaYazdir::readLine() 
{
    string token;
    ifstream file(this->dosyaAdi);
    string str;
    int index = 0;
    while (getline(file, token))
    {
        std::istringstream ss(token);

        while (getline(ss, str, ' ')) 
        {
            this->satir[index]->ekle(stoi(str));
        }
        index++;

    }
    file.close();
}

DosyaYazdir::~DosyaYazdir()
{
	if(satir!=0){
		int boyut =satirBoyutu();
		for (int i = 0; i < boyut; i++)
        {
			if(satir[i]!=0) delete satir[i];
		}
		delete[] satir;
	}
	
}