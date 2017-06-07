#ifndef _TRENER_H_
#define _TRENER_H_

#include <iostream>
#include <vector>
using namespace std;


class Trener
{
public:
    int tydzien;
    int test, test2;
    int dzien;
    int przerwa;
    int ile_serii;
    vector <int> szablon_serii;

    Trener()
    : tydzien (0)
    , test (0)
    , test2 (0)
    , dzien (0)
    , przerwa (0)
    , ile_serii (0)
    {}

    ~Trener()
    {}

    void jaki_trening(int t_test, int t_dzien);// jaki trening ma wczytac trener
    char tak_nie();



};
#endif
