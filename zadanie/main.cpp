#include <iostream>
#include "Wektor.hh"
#include "LZespolona.hh"



using namespace std;

int main()
{
    double tablica[] = {1,2,3,2,1};
    double ttablica[] = {4,3,2,1,0};
    Wektor<double, 5> Wek1(tablica);
    Wektor<double, 5> Wek(ttablica);

    LZespolona L, L1, L2, L3, L4(2,1);
    L=1; L1=2; L3=3;


    Wektor<LZespolona, 5> Wek2(L1,L,L2,L3,L4);
    cout << Wek2 << endl;
    Wektor<LZespolona, 5> Wek3(L,L4,L2,L3,L);
    cout << Wek3 << endl;

    LZespolona LL;
    LL = Wek2 * Wek3;
    cout << LL << endl;

    //double W = Wek1 * Wek;
    //cout << W;







}

