#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib> // dla atoi - konwertuje string na liczbe
#include "Trener.h"
using namespace std;

char Trener :: tak_nie()
{
    char pytanie;
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );

    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
    cout<<" Czy chcesz zapisac postepy? (";
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<"y";
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"/";
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout<<"n";
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
    cout<<") -> ";
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cin>>pytanie;

            while(pytanie!='y'&&pytanie!='n')
            {
                cin.ignore(100,'\n');
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
                cout<<" Przestan! Zapisac postepy?  (";
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
                cout<<"y";
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout<<"/";
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
                cout<<"n";
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
                cout<<") -> ";
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
                cin>>pytanie;
            }
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    return pytanie;

}

void Trener :: jaki_trening(int t_test, int t_dzien)
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    fstream plik;
    string linia; // linia tekstu
    int nr_linii=1; // liczy linie wczytanego pliku


     if(t_test>=0&&t_test<=5)//0-5
   {
       switch(t_dzien)
       {
           case 1: plik.open("treningi\\t0d1.txt", ios::in); break;
           case 2: plik.open("treningi\\t0d2.txt", ios::in); break;
           case 3: plik.open("treningi\\t0d3.txt", ios::in); break;
           case 4: plik.open("treningi\\t0d4.txt", ios::in); break;
           case 5: plik.open("treningi\\t0d5.txt", ios::in); break;
           case 6: plik.open("treningi\\t0d6.txt", ios::in); break;
       }

   }

    if(t_test>=6&&t_test<=10)//6-10
   {
       switch(t_dzien)
       {
           case 1: plik.open("treningi\\t1d1.txt", ios::in); break;
           case 2: plik.open("treningi\\t1d2.txt", ios::in); break;
           case 3: plik.open("treningi\\t1d3.txt", ios::in); break;
           case 4: plik.open("treningi\\t1d4.txt", ios::in); break;
           case 5: plik.open("treningi\\t1d5.txt", ios::in); break;
           case 6: plik.open("treningi\\t1d6.txt", ios::in); break;
       }

   }

    if(t_test>=11&&t_test<=20)//11-20
   {
       switch(t_dzien)
       {
           case 1: plik.open("treningi\\t2d1.txt", ios::in); break;
           case 2: plik.open("treningi\\t2d2.txt", ios::in); break;
           case 3: plik.open("treningi\\t2d3.txt", ios::in); break;
           case 4: plik.open("treningi\\t2d4.txt", ios::in); break;
           case 5: plik.open("treningi\\t2d5.txt", ios::in); break;
           case 6: plik.open("treningi\\t2d6.txt", ios::in); break;
       }

   }

    if(t_test>=21&&t_test<=25)//21-25
   {
       switch(t_dzien)
       {
           case 1: plik.open("treningi\\t3d1.txt", ios::in); break;
           case 2: plik.open("treningi\\t3d2.txt", ios::in); break;
           case 3: plik.open("treningi\\t3d3.txt", ios::in); break;
           case 4: plik.open("treningi\\t3d4.txt", ios::in); break;
           case 5: plik.open("treningi\\t3d5.txt", ios::in); break;
           case 6: plik.open("treningi\\t3d6.txt", ios::in); break;
       }

   }

    if(t_test>=26&&t_test<=30)//26-30
   {
       switch(t_dzien)
       {
           case 1: plik.open("treningi\\t4d1.txt", ios::in); break;
           case 2: plik.open("treningi\\t4d2.txt", ios::in); break;
           case 3: plik.open("treningi\\t4d3.txt", ios::in); break;
           case 4: plik.open("treningi\\t4d4.txt", ios::in); break;
           case 5: plik.open("treningi\\t4d5.txt", ios::in); break;
           case 6: plik.open("treningi\\t4d6.txt", ios::in); break;
       }

   }

    if(t_test>=31&&t_test<=35)//31-35
   {
       switch(t_dzien)
       {
           case 1: plik.open("treningi\\t5d1.txt", ios::in); break;
           case 2: plik.open("treningi\\t5d2.txt", ios::in); break;
           case 3: plik.open("treningi\\t5d3.txt", ios::in); break;
       }

   }

    if(t_test>=36&&t_test<=40)//36-40
   {
       switch(t_dzien)
       {
           case 1: plik.open("treningi\\t6d1.txt", ios::in); break;
           case 2: plik.open("treningi\\t6d2.txt", ios::in); break;
           case 3: plik.open("treningi\\t6d3.txt", ios::in); break;
       }

   }

    if(t_test>=41&&t_test<=45)//41-45
   {
       switch(t_dzien)
       {
           case 1: plik.open("treningi\\t7d1.txt", ios::in); break;
           case 2: plik.open("treningi\\t7d2.txt", ios::in); break;
           case 3: plik.open("treningi\\t7d3.txt", ios::in); break;
       }

   }

    if(t_test>=46&&t_test<=50)//46-50
   {
       switch(t_dzien)
       {
           case 1: plik.open("treningi\\t8d1.txt", ios::in); break;
           case 2: plik.open("treningi\\t8d2.txt", ios::in); break;
           case 3: plik.open("treningi\\t8d3.txt", ios::in); break;
       }

   }

    if(t_test>=51&&t_test<=55)//51-55
   {
       switch(t_dzien)
       {
           case 1: plik.open("treningi\\t9d1.txt", ios::in); break;
           case 2: plik.open("treningi\\t9d2.txt", ios::in); break;
           case 3: plik.open("treningi\\t9d3.txt", ios::in); break;
       }

   }

   if(t_test>=56&&t_test<=59)//51-55
   {
       switch(t_dzien)
       {
           case 1: plik.open("treningi\\t10d1.txt", ios::in); break;
           case 2: plik.open("treningi\\t10d2.txt", ios::in); break;
           case 3: plik.open("treningi\\t10d3.txt", ios::in); break;
       }

   }

   if(t_test>=60&&t_test<=99)//60-99
   {
       switch(t_dzien)
       {
           case 1: plik.open("treningi\\t11d1.txt", ios::in); break;
           case 2: plik.open("treningi\\t11d2.txt", ios::in); break;
           case 3: plik.open("treningi\\t11d3.txt", ios::in); break;
       }

   }

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //WCZYTUJE TRENING
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  if(plik.good()==true)
    {
        while (getline(plik,linia))
        {
            if(nr_linii<7)
            {
                switch(nr_linii)
                {
                    case 1: tydzien   =atoi(linia.c_str()); break;
                    case 2: test2     =atoi(linia.c_str()); break;
                    case 3: dzien     =atoi(linia.c_str()); break;
                    case 4: przerwa   =atoi(linia.c_str()); break;
                    case 5: ile_serii =atoi(linia.c_str()); break;
                }
                nr_linii++;
            }
            else
            {
                szablon_serii.push_back(atoi(linia.c_str()));
            }

        }

        plik.close();
    }
    else
    {
        SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
        cout<<" Blad !!! Brak dostepu do plikow treningowych (*.txt)"<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    }

}
