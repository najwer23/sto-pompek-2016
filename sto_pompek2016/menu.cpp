#include <iostream>
#include <windows.h>
using namespace std;

void menu()
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );

    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY ); //mocny srebny
    cout<<" Menu - Sto Pompek 2016 "<<endl;
    cout<<" Autor: Mariusz Najwer, 09 luty 2016"<<endl<<endl;
    cout<<" p --- Pokaz Menu."<<endl;
    cout<<" z --- Zaczynam trening."<<endl;
    cout<<" k --- Kontynuuje trening."<<endl;
    cout<<" c --- Kalendarz treningow."<<endl;
    cout<<" e --- Koniec \"Sto Pompek 2016\"."<<endl<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<"  >> ";
}
