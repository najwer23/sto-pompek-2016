#include <iostream>
#include <windows.h> // dla system pause
#include "Trener.h"  // klasa trener (info o treningach)
#include "Gracz.h"

using namespace std;

void menu(); //menu.cpp


int main()
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    char pytanie='p';    //pytanie do menu
    Trener Trener;
    Gracz Gracz;

    while(pytanie!='e')
    {
        switch(pytanie)
        {
            case 'p' :  {
                        menu();
                        cin>>pytanie;
                        break;
                        }

            case 'z' :  {
                        cin.sync();
                        Gracz.nowy_trening();
                        cout<<"  >> ";
                        cin>>pytanie;
                        break;
                        }

            case 'k' :  {
                        cin.sync();
                        string nazwaPliku = "treningi\\zapis.txt";
                        if(Gracz.wczytaj_zapis(nazwaPliku))
                            {
                                Gracz.jaki_trening(Gracz.test,Gracz.dzien);
                                Gracz.plan_treningu();
                            }
                        else
                            {
                                Gracz.jaki_trening(Gracz.test,Gracz.dzien);
                                Gracz.plan_treningu();
                            }

                        cout<<"  >> ";
                        cin>>pytanie;
                        break;
                        }

            case 'c' :  {
                        cin.sync();
                        Gracz.kalendarz();
                        cout<<"  >> ";
                        cin>>pytanie;
                        break;
                        }

            default  :  {
                        cin.ignore(100,'\n'); // gdy napotka spacje przestanie ignorowac
                        SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
                        cout<<" Blad !!! Bledny znak. Sprobuj ponownie."<<endl<<endl;
                        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
                        cout<<"  >> ";
                        cin>>pytanie;
                        break;
                        }
        }
    }
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<" Koniec \"Sto Pompek 2016\" :) "<<endl<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED  );
    system("pause");

    return 0;
}
