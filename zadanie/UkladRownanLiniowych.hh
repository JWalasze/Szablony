#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <fstream>
#include "Macierz.hh"
#include "Wektor.hh"
#include "LZespolona.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */

template<class TYP, int ROZMIAR>
class UkladRownanLiniowych {

    MacierzKw<TYP, ROZMIAR> A;
    Wektor<TYP, ROZMIAR> b;

  public:

    UkladRownanLiniowych()
    {
        b = Wektor<TYP, ROZMIAR>();
        A = MacierzKw<TYP, ROZMIAR>();
    }
    UkladRownanLiniowych(MacierzKw<TYP, ROZMIAR> AA, Wektor<TYP, ROZMIAR> bb)
    {
        A = AA;
        b = bb;
    }

    MacierzKw<TYP, ROZMIAR> get_A() const;
    Wektor<TYP, ROZMIAR> get_b() const;

    void set_A(const MacierzKw<TYP, ROZMIAR> & AA);
    void set_b(const Wektor<TYP, ROZMIAR> & bb);

    Wektor<TYP, ROZMIAR> Oblicz() const;

    double DlugoscWektoraBledu() const;
    Wektor<TYP, ROZMIAR> WektorBledu() const;
};

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP, ROZMIAR> &UklRown);

template<class TYP, int ROZMIAR>
std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych<TYP, ROZMIAR> &UklRown );

#endif
