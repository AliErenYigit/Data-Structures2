/* 
* Dosya Adi:Exception.hpp
* Exception hatasini firlatan fonksiyonun baslik dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 14/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/

#ifndef Exception_hpp
#define Exception_hpp

#include <iostream>

using namespace std;

class Exception 
{
private:
    string message;
public:

    Exception(const string &msg) : message(msg) 
    {}
    string Message()const;
};


#endif