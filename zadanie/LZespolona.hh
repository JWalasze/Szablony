#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <cmath>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
    double   re;
    double   im;
    explicit LZespolona();
    explicit LZespolona(float r, float i);
    LZespolona & operator = (double  Liczba);
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,  double Skl2);

LZespolona  operator * (LZespolona  Skl1,  double l);

//LZespolona operator  += (LZespolona  Skl1,  LZespolona  Skl2);

bool operator == (LZespolona L1, LZespolona L2);

bool operator != (LZespolona L1, LZespolona L2);

LZespolona sprzezenie(LZespolona  Skl1);

double modul(LZespolona Skl1);

std::istream & operator >> (std::istream & strm, LZespolona & Skl);

std::ostream & operator << (std::ostream & strm, const LZespolona &Skl);

#endif
