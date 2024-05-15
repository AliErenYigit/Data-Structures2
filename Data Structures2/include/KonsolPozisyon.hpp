/* 
* Dosya Adi:KonsolPozisyon.hpp
* Konsoldaki verilerin kordinatlarının baslik dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 15/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/

#ifndef KonsolPozisyon_hpp
#define KonsolPozisyon_hpp

#include <windows.h>

static class KonsolPozisyon 
{
public:

    static void gotoxy(int x, int y) 
    {
        COORD kord;
        kord.X = x;
        kord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), kord);
    }


} 
KonsolPozisyon;


#endif