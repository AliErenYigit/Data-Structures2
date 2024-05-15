/* 
* Dosya Adi:NoSuchElement.hpp
* NoSuchElement hatasini firlatan fonksiyonun baslik dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 14/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/

#ifndef NoSuchElement_hpp
#define NoSuchElement_hpp

#include "Exception.hpp"

class NoSuchElement : public Exception 

{
public:

    NoSuchElement(const string &msg) : Exception(msg)
    {}
};


#endif