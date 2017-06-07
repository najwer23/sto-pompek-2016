#ifndef _GRACZ_H_
#define _GRACZ_H_
#include <iostream>
#include "Trener.h"
using namespace std;

class Gracz : public Trener
{

public:

    int dzien;

    Gracz(int d=1, int t=-1)
    {
        dzien=d;
        test=t;

    }

    void nowy_trening();
    void plan_treningu();
    bool zapis(string nazwaPliku);
    bool wczytaj_zapis(string nazwaPliku);
    void czas(int a,int b);
    void kalendarz();



};
#endif
