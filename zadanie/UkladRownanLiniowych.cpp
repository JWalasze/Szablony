#include "UkladRownanLiniowych.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

 template<class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP, ROZMIAR>::set_A(const MacierzKw<TYP, ROZMIAR> & AA)
{
    this->A = AA;
}

template<class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP, ROZMIAR>::set_b(const Wektor<TYP, ROZMIAR> & bb)
{
    this->b = bb;
}

template<class TYP, int ROZMIAR>
MacierzKw<TYP, ROZMIAR> UkladRownanLiniowych<TYP, ROZMIAR>::get_A() const
{
    return this->A;
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> UkladRownanLiniowych<TYP, ROZMIAR>::get_b() const
{
    return this->b;
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> UkladRownanLiniowych<TYP, ROZMIAR>::Oblicz() const
{
    MacierzKw<TYP, ROZMIAR> OdwrA = this->A;
    Wektor<TYP, ROZMIAR> Wek = this->b;
    OdwrA.odwroc();
    Wektor<TYP, ROZMIAR> Wynik;

    Wynik = OdwrA * Wek;

    return Wynik;
}

template<class TYP, int ROZMIAR>
std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych<TYP, ROZMIAR> &UklRown )
{
    Strm << UklRown.get_A() << endl;
    Strm << UklRown.get_b() << endl;
    return Strm;
}

template <class TYP, int ROZMIAR>
std::istream& operator >> ( std::istream &Strm, UkladRownanLiniowych<TYP, ROZMIAR> &UklRown )
{
    MacierzKw<TYP, ROZMIAR> M;
    Wektor<TYP, ROZMIAR> W;
    Strm >> M >> W;
    UklRown.set_A(M);
    UklRown.set_b(W);
    return Strm;
}

template <class TYP, int ROZMIAR>
double UkladRownanLiniowych<TYP, ROZMIAR>::DlugoscWektoraBledu() const
{
    Wektor<TYP, ROZMIAR> Wynik = (*this).WektorBledu();
    return Wynik.dlugosc();
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> UkladRownanLiniowych<TYP, ROZMIAR>::WektorBledu() const
{
    Wektor<TYP, ROZMIAR> Wynik = (*this).Oblicz();
    Wektor<TYP, ROZMIAR> BladUkl = (*this).get_A() * Wynik - (*this).get_b();
    return BladUkl;
}

template class UkladRownanLiniowych<double,5>;
template class UkladRownanLiniowych<double,3>;
template class UkladRownanLiniowych<LZespolona,5>;
template class UkladRownanLiniowych<LZespolona,3>;

template std::ostream & operator << (std::ostream &Strm, const UkladRownanLiniowych<double,5> & Wek);
template std::ostream & operator << (std::ostream &Strm, const UkladRownanLiniowych<double,3> & Wek);
template std::ostream & operator << (std::ostream &Strm, const UkladRownanLiniowych<LZespolona,5> & Wek);
template std::ostream & operator << (std::ostream &Strm, const UkladRownanLiniowych<LZespolona,3> & Wek);


template std::istream & operator >> (std::istream &Strm, UkladRownanLiniowych<double,3> & Wek);
template std::istream & operator >> (std::istream &Strm, UkladRownanLiniowych<double,5> & Wek);
template std::istream & operator >> (std::istream &Strm, UkladRownanLiniowych<LZespolona,5> & Wek);
template std::istream & operator >> (std::istream &Strm, UkladRownanLiniowych<LZespolona,3> & Wek);


