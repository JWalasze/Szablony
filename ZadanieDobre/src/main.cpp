#include <iostream>
#include "Wektor.hh"
#include "LZespolona.hh"
#include "Macierz.hh"
#include <fstream>
#include <cstdlib>
#include "UkladRownanLiniowych.hh"
#include <iomanip>



using namespace std;

int main()
{
    cout << "Start programu" << endl;
    fstream plik;
    plik.open("plikz.txt");

    if( plik.good()==false )
    {
        cout << "Brak takiego pliku" << endl;
        exit(0);
    }
    char znak;
    plik >> znak;
    if(znak=='z')
    {
        MacierzKw<LZespolona, 5> Macierz;
        Wektor<LZespolona, 5> Wek;
        plik >> Macierz >> Wek;
        plik.close();

        UkladRownanLiniowych<LZespolona, 5> Ukl;
        Ukl.set_A(Macierz);
        Ukl.set_b(Wek);
        cout << endl << "Macierz wspolczynnikow - A" << endl;
        cout << Ukl.get_A() << endl;

        cout << "Wektor wyrazow wolnych - b" << endl;
        cout << Ukl.get_b() << endl;

        Wektor<LZespolona, 5> Wynik = Ukl.Oblicz();

        cout << "Rozwiazanie x = (x1, x2, x3, x4, x5):" << endl;
        cout << fixed << setprecision(2);
        cout << Wynik << endl;

        cout << scientific << setprecision(1);
        cout << "Wektor bledu: Ax-b = " << Ukl.WektorBledu() << endl;
        cout << "Dlugosc wektora bledu: ||Ax-b|| = " << Ukl.DlugoscWektoraBledu() << endl;
    }
    else if(znak=='r')
    {
        MacierzKw<double, 5> Macierz;
        Wektor<double, 5> Wek;
        plik >> Macierz >> Wek;
        plik.close();

        UkladRownanLiniowych<double, 5> Ukl;
        Ukl.set_A(Macierz);
        Ukl.set_b(Wek);
        cout << endl << "Macierz wspolczynnikow - A" << endl;
        cout << Ukl.get_A() << endl;

        cout << "Wektor wyrazow wolnych - b" << endl;
        cout << Ukl.get_b() << endl;

        Wektor<double, 5> Wynik = Ukl.Oblicz();

        cout << "Rozwiazanie x = (x1, x2, x3, x4, x5):" << endl;
        cout << fixed << setprecision(2);
        cout << Wynik << endl;

        cout << scientific << setprecision(1);
        cout << "Wektor bledu: Ax-b = " << Ukl.WektorBledu() << endl;
        cout << "Dlugosc wektora bledu: ||Ax-b|| = " << Ukl.DlugoscWektoraBledu() << endl;
    }

}

