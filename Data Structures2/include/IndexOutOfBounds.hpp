/* 
* Dosya Adi:IndexOutOfBounds.hpp
* IndexOutOfBounds hatasini firlatan fonksiyonun baslik dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 14/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/

#ifndef IndexOutOfBounds_hpp
#define IndexOutOfBounds_hpp

#include "Exception.hpp"

class IndexOutOfBounds : public Exception
{
public:

    IndexOutOfBounds(const string &msg) : Exception(msg)
    {}
};


#endif