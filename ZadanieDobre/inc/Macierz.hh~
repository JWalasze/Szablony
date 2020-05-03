#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>

template<class TYP, int ROZMIAR>
class MacierzKw {

    Wektor<TYP, ROZMIAR> tab[ROZMIAR];

public:

    MacierzKw();

    MacierzKw(const Wektor<TYP, ROZMIAR> tablica[]);

    MacierzKw(Wektor<TYP, ROZMIAR> A, Wektor<TYP, ROZMIAR> B, Wektor<TYP, ROZMIAR> C, Wektor<TYP, ROZMIAR> D, Wektor<TYP, ROZMIAR> E);

    TYP wyznacznik() const;

    const MacierzKw<TYP, ROZMIAR> & transponuj() const;
    void transponuj();

    const MacierzKw<TYP, ROZMIAR> & odwroc() const;
    void odwroc();

    MacierzKw<TYP, ROZMIAR> operator * (const MacierzKw<TYP, ROZMIAR> & M2) const;
    MacierzKw<TYP, ROZMIAR> operator + (const MacierzKw<TYP, ROZMIAR> & M2) const;
    MacierzKw<TYP, ROZMIAR> operator - (const MacierzKw<TYP, ROZMIAR> & M2) const;
    MacierzKw<TYP, ROZMIAR> operator * (TYP l) const;
    Wektor<TYP, ROZMIAR> operator * (const Wektor<TYP, ROZMIAR> & W2) const;

    const Wektor<TYP, ROZMIAR> & operator[] (int index) const;
    Wektor<TYP, ROZMIAR> & operator[] (int index);

    const MacierzKw<TYP, ROZMIAR> & zamien_kolumny() const;
    void zamien_kolumny();

};

template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, MacierzKw<TYP, ROZMIAR> &Mac);

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const MacierzKw<TYP, ROZMIAR> &Mac);

#endif
