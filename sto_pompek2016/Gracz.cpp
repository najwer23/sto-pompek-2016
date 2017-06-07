#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>   // potrzebna ale po co?
#include "Gracz.h"
using namespace std;



void Gracz :: kalendarz()
{
    fstream plik;
    string nazwaPliku="treningi\\tabelka.txt";
    plik.open(nazwaPliku.c_str(), ios :: in);

    int liczba=1;
    int ile_suma=0;
    string  DATA;
    string DZIEN;
    string GODZINA;
    int ilosc;

    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );

    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
    cout<<" L.p       Data        Godzina    Nr dnia    Ilosc"<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    while(true) //petla nieskonczona
    {
        plik>>DATA>>GODZINA>>DZIEN>>ilosc; /// ROZWIAZANIE KTOREGO NIE KUMAM, ALE DZIALA
        if(plik.good())
        {
            if(DZIEN=="T")
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
                cout.width( 3 );
                cout<<liczba<<"     "<<DATA<<"      "<<GODZINA<<"        "<<DZIEN;
                cout.width( 11 );
                cout<<ilosc<<endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            }
            else
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
                cout.width( 3 );
                cout<<liczba<<"     "<<DATA<<"      "<<GODZINA<<"        "<<DZIEN;
                cout.width( 11 );
                cout<<ilosc<<endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            }


            liczba++;
            ile_suma+=ilosc;

        }
        else
            break; //zakoncz wczytywanie danych

    } //while
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
    cout<<endl<<" Zrobiles juz: ";
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout<<ile_suma;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
    cout<<" push-ups."<<endl;
    cout<<" Spaliles juz: ";
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout<<ile_suma*0.007;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
    cout<<" kcal."<<endl<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );


}


void Gracz :: czas(int a, int b)
{
   HANDLE hOut;
   hOut = GetStdHandle( STD_OUTPUT_HANDLE );
   int t=a;
   int suma=b;
   fstream plik;
   SYSTEMTIME st;//struktura
   GetLocalTime(&st);

   int godzina = st.wHour;
   int minuta  = st.wMinute;
   int Dzien = st.wDay;
   int miesiac = st.wMonth;
   int rok = st.wYear;

    plik.open( "treningi\\tabelka.txt", ios::in | ios::out | ios::app); //niejawnie ios::out
            if( plik.good() == true )
            {
                if(test!=-1)
                {
                plik.width( 2 );
                plik.fill( '0' );
                plik<<Dzien<<".";
                plik.width( 2 );
                plik.fill( '0' );
                plik<<miesiac<<"."<<rok<<" ";
                //2
                plik.width( 2 );
                plik.fill( '0' );
                plik<<godzina<<":";
                plik.width( 2 );
                plik.fill( '0' );
                plik<<minuta<<" ";
                //3
                if(t==1)
                plik<<"T"<<" ";
                else
                plik<<dzien<<" ";
                //4
                if(suma>0)
                plik<<suma;
                else
                plik<<test;
                plik<<endl;
                plik.close();
                }

            }
            else
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
                cout << " Blad !!! Brak dostepu do pliku tabelka.txt" <<endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Gracz :: nowy_trening()
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    char pytanie;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout<<" Dzis nalezy wykonac test ";
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout<<"!!!"<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout<<" Twoj wynik testu -> ";
    int a=1;
    while(a>0) //dopoty warunek spelniony petla dziala
    {
        cin>>test;
        if(test<0)
        {
            SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
            cout << " Blad !!! Liczba ujemna ???" <<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout<<" Twoj wynik testu -> ";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        }
        if(test>0)
            a=-1;
    }
    if(test>=100)
    {
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
        cout<<" Gratulacje ";
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout<<"!!!"<<endl;
        cout<<" Pokorne i ambitne osoby skazane sa na sukces."<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );
        cout<<" A zrobisz 140 pompek w ciagu minuty ???"<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED  );
    }

    else
        {
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );
            cout<<" Po wykonanym tescie nalezy odpoczac min 48 godz. ";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout<<"!!!"<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        }


    pytanie=tak_nie();
    if(pytanie=='y')
    {
        string nazwa="treningi\\zapis.txt";
        zapis(nazwa);
        czas(1,0);
    }
    else
        cout<<endl;

    //tutaj zapis do kalendarza

}

void Gracz :: plan_treningu()
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    Gracz Gracz;
    if(test==-1)
    {
        Gracz.nowy_trening();
        czas(1,0);
    }
    if(test>100)
    {
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
        cout<<" Gratulacje ";
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout<<"!!!"<<endl;
        cout<<" Pokorne i ambitne osoby skazane sa na sukces."<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    }
    if(test>0&&test<100)
    {
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
        cout<<" Tydzien     Dzien     Twoj Test     Test prog     Przerwa"<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
        cout.width( 3 );
        cout<<"    "<<tydzien<<"          "<<dzien<<"          "<<test<<"            "<<test2;
        cout.width( 14 );
        cout<<przerwa<<endl<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

    //TUTAJ ZMIANA WYSWIETLANIA
    /*
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
        for( int i = 0; i < szablon_serii.size(); i++ )
        {
            cout <<" Seria"<<i+1<<" ";
            cout.width( 3 );
        }
        cout<<endl;

        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
        for( int i = 0; i < szablon_serii.size(); i++ )
        {
            if(szablon_serii[i]>9)
            cout.width( 3 );
            else
            cout.width( 4 );
            cout<<"   "<<szablon_serii[ i ]<<"   ";
        }
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        cout<<endl<<endl;

    */

        int ile_musi=0;
        for( int i = 0; i < szablon_serii.size(); i++ )
        {
            cout <<" Seria"<<i+1<<":    ";
            cout.width( 3 );
            cout<< szablon_serii[ i ] << endl;
            ile_musi+=szablon_serii[ i ];
        }

        cout<<endl;

        int zrobione=0;
        double suma=0;
        char pytanie='k';
        int flaga=1;

        for( int i = 0; i < szablon_serii.size(); i++ )
        {
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
            cout <<" Seria"<<i+1<<":    ";
            cout.width( 3 );
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
            cout<< szablon_serii[ i ] ;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
            cout<<"      Zrobione:  ";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
            cin>>zrobione;
            suma+=zrobione;

            if(szablon_serii.size()!=flaga)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED   );
                cout<<" Minutnik?           (";
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
                cout<<"y";
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED  );
                cout<<"/";
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
                cout<<"n";
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED  );
                cout<<") ->   ";

                cin>>pytanie;
                while(pytanie!='y'&&pytanie!='n')
                {

                    cin.ignore(100,'\n');
                    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED   );
                    cout<<" Minutnik?           (";
                    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
                    cout<<"y";
                    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED  );
                    cout<<"/";
                    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
                    cout<<"n";
                    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED  );
                    cout<<") ->   ";
                    cin>>pytanie;

                }
            }
            if(flaga==szablon_serii.size())
                pytanie='n';

            flaga++;
            if(pytanie=='y')
            {

                for (int i = przerwa; i >=0; i--)
                {
                    cout << "\r Odpocznij: ";
                    cout.width( 3 );
                    if(i<11)
                    {
                        SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
                        cout<<i;
                        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED  ); //mocny srebny

                    }
                    else
                    cout<<i;
                    Sleep(1000);
                    cout << "\b\b\b  ";

                }
                cout<<"0"<<endl;
                Beep(2000,790);
            }

        }

        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
        cout<<endl<<" Dzis udalo ci sie zrobic: ";
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout<<suma;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
        cout<<" push-ups."<<endl;
        cout<<" Dzis udalo ci sie spalic: ";
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout<<suma*0.007;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
        cout<<" kcal."<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

        pytanie=tak_nie();
        if(pytanie=='y')
        {
            czas(0,suma);
        }

       if(ile_musi<=suma)
        {
        dzien+=1;
        }

        if(dzien>6)
        {
            test=-1;
            dzien=1;
        }
        if(dzien>3&&test>30)
        {
            test=-1;
            dzien=1;
        }

        if(pytanie=='y')
        {
            string nazwa="treningi\\zapis.txt";
            zapis(nazwa);

        }
        else
        cout<<endl;
        szablon_serii.clear();


    }

}

bool Gracz :: zapis(string nazwaPliku)
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    fstream plik;
    plik.open( nazwaPliku.c_str(), ios::out);
        if( plik.good() == true )
        {
            plik<<test<<endl;
            jaki_trening(test, dzien);
            plik<<dzien<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );
            cout<<" Postepy zostaly zapisane ";
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout<<"!!!"<<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

            plik.close();
        }
        else
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
                cout << " Blad !!! Brak dostepu do pliku zapis.txt." <<endl;
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

            }
        szablon_serii.clear();
        cout<<endl;
        return true;
}

bool Gracz :: wczytaj_zapis(string nazwaPliku)
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    fstream plik;
    string linia;
    test=-1;
    int nr_linii=1;
    plik.open(nazwaPliku.c_str(), ios::in);
        if(plik.good()==true)
        {

            while (getline(plik,linia))
            {
                switch(nr_linii)
                {
                    case 1: test=atoi(linia.c_str());
                    case 2: dzien=atoi(linia.c_str());
                }
                nr_linii++;
            }
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );
        cout<<" Wczytano ostatni postep ";
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout<<"!!!"<<endl;
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );

        plik.close();
        return true;
        }
        else
        {
            SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
            cout << " Blad !!! Brak dostepu do pliku zapis.txt. -- funkcja wczytujaca" <<endl;
            cout << " Nastapi stworzenie pliku zapis.txt" <<endl;
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            return false;

        }


}



