#include "Wektor.hh"
#include "cassert"
#include "LZespolona.hh"

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR>::Wektor()
{
   for(int i=0; i<ROZMIAR; ++i)
    {
        this->tab[i]=0;
    }
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR>::Wektor(TYP tablica[])
{
    for(int i=0; i<ROZMIAR; ++i)
    {
        this->tab[i]=tablica[i];
    }
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR>::Wektor(TYP x, TYP y, TYP z, TYP a, TYP b)
   {
   int i=0;
   this->tab[i]=x;
   this->tab[++i]=y;
   this->tab[++i]=z;
   this->tab[++i]=a;
   this->tab[++i]=b;
   }

template <class TYP, int ROZMIAR>
const TYP & Wektor<TYP, ROZMIAR>::operator[](int index) const
{
  return this->tab[index];
}

template <class TYP, int ROZMIAR>
TYP & Wektor<TYP, ROZMIAR>::operator [] (int index)
{
    assert(index < ROZMIAR && index >= 0);
    return this->tab[index];
}

/*template <class TYP, int ROZMIAR>
double Wektor<TYP, ROZMIAR>::dlugosc() const
{
   double Wynik = 0;

   for(int i=0; i<ROZMIAR; ++i)
   {
   Wynik = Wynik + this->tab[i] * this->tab[i];
   }
   return sqrt(Wynik);
}*/

template <class TYP, int ROZMIAR>
TYP Wektor<TYP, ROZMIAR>::operator * (const Wektor<TYP, ROZMIAR> & W2) const //SKALARNIE
{
   TYP Wynik;
   Wynik = 0;

   for(int i=0; i<ROZMIAR; ++i)
   {
   Wynik = Wynik + this->tab[i] * W2[i];
   }
   return Wynik;
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator + (const Wektor<TYP, ROZMIAR> & W2) const
{
    Wektor<TYP, ROZMIAR> Wynik;
    for(int i=0; i<ROZMIAR; ++i)
    {
        Wynik[i]=this->tab[i] + W2[i];
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator - (const Wektor<TYP, ROZMIAR> & W2) const
{
    Wektor<TYP, ROZMIAR> Wynik;
    for(int i=0; i<ROZMIAR; ++i)
    {
        Wynik[i]=this->tab[i] - W2[i];
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator * (double l) const
{
    Wektor<TYP, ROZMIAR> Wynik;
    for(int i=0; i<ROZMIAR; ++i)
    {
        Wynik[i]=this->tab[i] * l;
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator / (double l) const
{
    Wektor<TYP, ROZMIAR> Wynik;
    for(int i=0; i<ROZMIAR; i++)
    {
        assert(l!=0);
        Wynik[i]=this->tab[i] / l;
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
bool Wektor<TYP, ROZMIAR>::operator == (const Wektor<TYP, ROZMIAR> & W2) const
{
    for(int i=0; i<ROZMIAR; ++i)
    {
        if( this->tab[i]!= W2[i])
        {
            return false;
        }
    }
    return true;
}

template <class TYP, int ROZMIAR>
bool Wektor<TYP, ROZMIAR>::operator != (const Wektor<TYP, ROZMIAR> & W2) const
{
   if(*this==W2)
   {
   return false;
   }
   else
   {
   return true;
   }
}

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP, ROZMIAR> &Wek)
{
   for(int i=0; i<ROZMIAR; ++i)
   {
   Strm << Wek[i] << " ";
   }
   Strm << endl;
   return Strm;
}

template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP, ROZMIAR> &Wek)
{
   for(int i=0; i<ROZMIAR; ++i)
   {
   Strm >> Wek[i];
   }
   return Strm;
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> operator * (double l, Wektor<TYP, ROZMIAR> W2)
{
   return W2*l;
}

template <class TYP, int ROZMIAR>
void Wektor<TYP, ROZMIAR>::zamien_kolumny()
{
    for(int i=0; i<ROZMIAR/2; ++i)
    {
        swap( this->tab[i], this->tab[ROZMIAR-1-i] );
    }
}

template <class TYP, int ROZMIAR>
const Wektor<TYP, ROZMIAR> & Wektor<TYP, ROZMIAR>::zamien_kolumny() const
{
    return *this;
}

template class Wektor<double,5>;
template class Wektor<double,3>;
template class Wektor<LZespolona,5>;


template Wektor<double, 5> operator * (double l, Wektor<double, 5> W2);

template std::ostream & operator << (std::ostream &Strm, const Wektor<double,5> & Wek);
template std::ostream & operator << (std::ostream &Strm, const Wektor<double,3> & Wek);
template std::ostream & operator << (std::ostream &Strm, const Wektor<LZespolona,5> & Wek);

template std::istream & operator >> (std::istream &Strm, Wektor<double,3> & Wek);
template std::istream & operator >> (std::istream &Strm, Wektor<double,5> & Wek);
template std::istream & operator >> (std::istream &Strm, Wektor<LZespolona,5> & Wek);





