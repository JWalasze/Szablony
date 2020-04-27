#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cmath>

using namespace std;

template <class TYP, int ROZMIAR>
class Wektor {

    TYP tab[ROZMIAR];

  public:

    Wektor();

    Wektor(TYP tablica[]);

    Wektor(TYP x, TYP y, TYP z, TYP a, TYP b);

    Wektor<TYP, ROZMIAR> operator + (const Wektor<TYP, ROZMIAR> & W2) const;
    Wektor<TYP, ROZMIAR> operator - (const Wektor<TYP, ROZMIAR> & W2) const;
    Wektor<TYP, ROZMIAR> operator * (double l) const;
    TYP operator * (const Wektor<TYP, ROZMIAR> & W2) const; //skalarnie
    Wektor<TYP, ROZMIAR> operator / (double l) const;

    double dlugosc() const;

    bool operator == (const Wektor<TYP, ROZMIAR> & W2) const;
    bool operator != (const Wektor<TYP, ROZMIAR> & W2) const;

    const TYP & operator [] (int index) const;
    TYP & operator [] (int index);

    const Wektor<TYP, ROZMIAR> & zamien_kolumny() const;
    void zamien_kolumny();
};

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> operator * (double l, Wektor<TYP,ROZMIAR> W2);

template <class TYP, int ROZMIAR>
std::istream & operator >> (std::istream &Strm, Wektor<TYP, ROZMIAR> &Wek);

template <class TYP, int ROZMIAR>
std::ostream & operator << (std::ostream &Strm, const Wektor<TYP, ROZMIAR> &Wek);

#endif
