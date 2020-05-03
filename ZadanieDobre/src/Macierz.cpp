#include "Wektor.hh"
#include "Macierz.hh"
#include "cassert"
#include "LZespolona.hh"

using namespace std;

template <class TYP, int ROZMIAR>
MacierzKw<TYP, ROZMIAR>::MacierzKw()
{
    for(int i=0; i<ROZMIAR; ++i)
    {
        this->tab[i]= Wektor<TYP, ROZMIAR>();
    }
}

template <class TYP, int ROZMIAR>
MacierzKw<TYP, ROZMIAR>::MacierzKw(const Wektor<TYP, ROZMIAR> tablica[])
  {
    for(int i=0; i<ROZMIAR; ++i)
    {
        this->tab[i]=tablica[i];
    }
}
/*
MacierzKw::MacierzKw(Wektor A, Wektor B, Wektor C)
  {
   int i=0;
   this->tab[i]= A;
   this->tab[++i]= B;
   this->tab[++i]= C;
  }*/

template<class TYP, int ROZMIAR>
const Wektor<TYP, ROZMIAR> & MacierzKw<TYP, ROZMIAR>::operator[] (int index) const
{
  return this->tab[index];
}

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> & MacierzKw<TYP, ROZMIAR>::operator[] (int index)
{
    assert(index < ROZMIAR && index >= 0);
    return this->tab[index];
}

template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const MacierzKw<TYP, ROZMIAR> &Mac)
{
    for(int i=0; i<ROZMIAR; ++i)
    {
        for(int j=0; j<ROZMIAR; ++j)
        {
            Strm << Mac[j][i] << "  ";
        }
        Strm << endl;
    }
    return Strm;
}

template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, MacierzKw<TYP, ROZMIAR> &Mac)
{
    for(int i=0; i<ROZMIAR; ++i)
    {
        Strm >> Mac[i];
    }
    return Strm;
}

template <class TYP, int ROZMIAR>
MacierzKw<TYP, ROZMIAR> MacierzKw<TYP, ROZMIAR>::operator + (const MacierzKw<TYP, ROZMIAR> & M2) const
{
    MacierzKw<TYP, ROZMIAR> Wynik;
    for(int i=0; i<ROZMIAR; ++i)
    {
        Wynik[i] = this->tab[i] + M2[i];
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
MacierzKw<TYP, ROZMIAR> MacierzKw<TYP, ROZMIAR>::operator - (const MacierzKw<TYP, ROZMIAR> & M2) const
{
    MacierzKw<TYP, ROZMIAR> Wynik;
    for(int i=0; i<ROZMIAR; ++i)
    {
        Wynik[i] = this->tab[i] - M2[i];
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
MacierzKw<TYP, ROZMIAR> MacierzKw<TYP, ROZMIAR>::operator * (TYP l) const
{
    MacierzKw<TYP, ROZMIAR> Wynik;
    for(int i=0; i<ROZMIAR; ++i)
    {
        Wynik[i] = this->tab[i] * l;
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
const MacierzKw<TYP, ROZMIAR> & MacierzKw<TYP, ROZMIAR>::transponuj() const
{
    return *this;
}

template <class TYP, int ROZMIAR>
void MacierzKw<TYP, ROZMIAR>::transponuj()
{
    for(int j=0; j<ROZMIAR; ++j)
    {
        for( int i=j; i<ROZMIAR; ++i)
        {
            swap( this->tab[i][j], this->tab[j][i] );
        }
    }
}

template <class TYP, int ROZMIAR>
MacierzKw<TYP, ROZMIAR> MacierzKw<TYP, ROZMIAR>::operator * (const MacierzKw<TYP, ROZMIAR> & M2) const
{
    MacierzKw<TYP, ROZMIAR> Wynik;
    for(int i=0; i<ROZMIAR; ++i)
    {
        for(int j=0; j<ROZMIAR; ++j)
        {
            Wynik[j][i]= this->tab[i] * M2[j];
        }
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> MacierzKw<TYP, ROZMIAR>::operator * (const Wektor<TYP, ROZMIAR> & W2) const
{
    Wektor<TYP, ROZMIAR> Wynik;
    for(int i=0; i<ROZMIAR; ++i)
    {
        Wynik[i]= this->tab[i] * W2;
    }
    return Wynik;
}

template <class TYP, int ROZMIAR>
TYP MacierzKw<TYP, ROZMIAR>::wyznacznik() const
{
    TYP Wyzn;
    Wyzn = 1;
    MacierzKw<TYP, ROZMIAR> M = *this;
    M.zamien_kolumny();
    for(int i = 1; i<ROZMIAR; ++i)
    {
        if( M[0][ROZMIAR-1]==0 )
        {
            M[0] = M[0] + M[i];
        }
        M[i] = M[i] - ( ( M[0] * M[i][ROZMIAR-1] ) / M[0][ROZMIAR-1] );
        if( i>1 )
        {
            for( int x = ROZMIAR - 2; x>=ROZMIAR-i; --x)
            {
                if( M[ROZMIAR-1-x][x]==0 )
                {
                    cout << "Wyznacznik jest rowny zero" << endl << "Macierz osobliwa" << endl;
                    TYP out;
                    out =0;
                    return out;
                }

                M[i] = M[i] - ( ( M[ROZMIAR-1-x] * M[i][x] ) / M[ROZMIAR-1-x][x] );
            }
        }
    }
    for(int i=0; i<ROZMIAR; ++i)
    {
        Wyzn *= M[i][ROZMIAR -1 -i];
    }
    return Wyzn;
}

template <class TYP, int ROZMIAR>
const MacierzKw<TYP, ROZMIAR> & MacierzKw<TYP, ROZMIAR>::odwroc() const
{
    return *this;
}

template <class TYP, int ROZMIAR>
void MacierzKw<TYP, ROZMIAR>::odwroc()
{
    if((*this).wyznacznik()==0)
    {
        cerr << "Nie mozna policzyc macierzy odwrotnej" << endl;
        cout << "Wyznacznik jest rowny 0!" << endl;
        exit(0);
    }
    MacierzKw Odwr;
    (*this).zamien_kolumny();
    for(int i=0; i<ROZMIAR; ++i)
    {
        Odwr[i][ROZMIAR-1-i] = 1;
    }
    for(int i = 1; i<ROZMIAR; i++)
    {
        if( this->tab[0][ROZMIAR-1]==0 )
        {
            this->tab[0] = this->tab[0] + this->tab[i];
            Odwr[0] = Odwr[0] + Odwr[i];
        }
        Odwr[i] = Odwr[i] - ( ( Odwr[0] * this->tab[i][ROZMIAR-1] ) / this->tab[0][ROZMIAR-1] );
        this->tab[i] = this->tab[i] - ( ( this->tab[0] * this->tab[i][ROZMIAR-1] ) / this->tab[0][ROZMIAR-1] );
        if( i>1 )
        {
            for( int x = ROZMIAR - 2; x>=ROZMIAR-i; x--)
            {
                Odwr[i] = Odwr[i] - ( ( Odwr[ROZMIAR-1-x] * this->tab[i][x] ) / this->tab[ROZMIAR-1-x][x] );
                this->tab[i] = this->tab[i] - ( ( this->tab[ROZMIAR-1-x] * this->tab[i][x] ) / this->tab[ROZMIAR-1-x][x] );
            }
        }
    }

    for(int i=0; i<ROZMIAR; i++)
    {
        Odwr[i] = Odwr[i] / this->tab[i][ROZMIAR-1-i];
        this->tab[i] = this->tab[i] / this->tab[i][ROZMIAR-1-i];
    }

    //drugi trojkat

    for(int i=ROZMIAR-2; i>=0; i--)
    {
        Odwr[i] = Odwr[i] - ( ( Odwr[ROZMIAR-1] * this->tab[i][0] ) / this->tab[ROZMIAR-1][0] );
        this->tab[i] = this->tab[i] - ( ( this->tab[ROZMIAR-1] * this->tab[i][0] ) / this->tab[ROZMIAR-1][0] );
        if( i<ROZMIAR-2 )
        {
            for( int x = 1; x<ROZMIAR-1-i; x++)
            {
                Odwr[i] = Odwr[i] - ( ( Odwr[ROZMIAR-1-x] * this->tab[i][x] ) / this->tab[ROZMIAR-1-x][x] );
                this->tab[i] = this->tab[i] - ( ( this->tab[ROZMIAR-1-x] * this->tab[i][x] ) / this->tab[ROZMIAR-1-x][x] );
            }
        }
    }
    Odwr.zamien_kolumny();
    *this=Odwr;
}

template <class TYP, int ROZMIAR>
void MacierzKw<TYP, ROZMIAR>::zamien_kolumny()
{
    for(int i=0; i<ROZMIAR/2; ++i)
    {
        swap( this->tab[i], this->tab[ROZMIAR-1-i] );
    }
}

template <class TYP, int ROZMIAR>
const MacierzKw<TYP, ROZMIAR> & MacierzKw<TYP, ROZMIAR>::zamien_kolumny() const
{
    return *this;
}


template class MacierzKw<double,5>;
template class MacierzKw<double,3>;
template class MacierzKw<LZespolona,5>;
template class MacierzKw<LZespolona,3>;

template std::ostream & operator << (std::ostream &Strm, const MacierzKw<double,5> & Wek);
template std::ostream & operator << (std::ostream &Strm, const MacierzKw<double,3> & Wek);
template std::ostream & operator << (std::ostream &Strm, const MacierzKw<LZespolona,5> & Wek);
template std::ostream & operator << (std::ostream &Strm, const MacierzKw<LZespolona,3> & Wek);


template std::istream & operator >> (std::istream &Strm, MacierzKw<double,3> & Wek);
template std::istream & operator >> (std::istream &Strm, MacierzKw<double,5> & Wek);
template std::istream & operator >> (std::istream &Strm, MacierzKw<LZespolona,5> & Wek);
template std::istream & operator >> (std::istream &Strm, MacierzKw<LZespolona,3> & Wek);





