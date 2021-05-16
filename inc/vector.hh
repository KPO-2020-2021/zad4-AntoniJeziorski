#pragma once

#include "size.hh"
#include <iostream>
#include <iomanip>


template <unsigned int Size>
class Vector {

    double size[Size];     //Tablica  wektora

    public:

        Vector<Size>(); // Konstruktor bezparametryczny

        Vector<Size>(double [Size]); // Konstruktor parametryczny

        Vector<Size> operator + (const Vector<Size> &v); // Operator dodawania wektorow

        Vector<Size> operator - (const Vector<Size> &v); // Operator odejmowania wektorow

        Vector<Size> operator * (const double &tmp); // Operator mnozenia wektora razy double

        Vector<Size> operator / (const double &tmp); // Operator dzielenia wektora przez double

        const double &operator [] (unsigned int index) const; // Operator indeksujacy dla odczytu

        double &operator [] (unsigned int index); // Operator indeksujacy dla zapisu
};

template <unsigned int Size>
std::ostream &operator << (std::ostream &out, Vector<Size> const &tmp); // Operator bitowy <<

template <unsigned int Size>
std::istream &operator >> (std::istream &in, Vector<Size> &tmp); // Operator bitowy >>

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template <unsigned int Size>
Vector<Size>::Vector() {
    for (unsigned int i = 0; i < Size; ++i) {
        size[i] = 0;
    }
}


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template <unsigned int Size>
Vector<Size>::Vector(double tmp[Size]) {
    if(Size < 0) {
        throw std::runtime_error("Niepoprawny rozmiar wektora ");
    }
    else {
        for (unsigned int i = 0; i < Size; ++i) {
            size[i] = tmp[i];
        }
    }
}


/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */

template <unsigned int Size>
Vector<Size> Vector<Size>::operator + (const Vector<Size> &v) {
    Vector<Size> result;
    for (unsigned int i = 0; i < Size; ++i) {
        result[i] = size[i] += v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */

template <unsigned int Size>
Vector<Size> Vector<Size>::operator - (const Vector<Size> &v) {
    Vector<Size> result;
    for (unsigned int i = 0; i < Size; ++i) {
        result[i] = size[i] -= v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */

template <unsigned int Size>
Vector<Size> Vector<Size>::operator * (const double &tmp) {
    Vector result;
    for (unsigned int i = 0; i < Size; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
}


/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template <unsigned int Size>
Vector<Size> Vector<Size>::operator / (const double &tmp) {
    Vector result;
    if (tmp == 0) {
        throw("Dzielnie przez 0");
    }
    for (unsigned int i = 0; i < Size; ++i) {
        result[i] = size[i] / tmp;
    }

    return result;
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template <unsigned int Size>
const double &Vector<Size>::operator [] (unsigned int index) const {
    if (index < 0 || index >= Size) {
        throw std::runtime_error("Error: Wektor jest poza zasiegiem!");
    }
    return size[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template <unsigned int Size>
double &Vector<Size>::operator[](unsigned int index) {
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template <unsigned int Size>
std::ostream &operator << (std::ostream &out, Vector<Size> const &tmp) {
    for (unsigned int i = 0; i < Size; ++i) {
        out << std::fixed << std::setprecision(10)  << tmp[i] << " ";
    }
    return out;
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template <unsigned int Size>
std::istream &operator >> (std::istream &in, Vector<Size> &tmp) {
    for (unsigned int i = 0; i < Size; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    if(in.fail())
        throw std::runtime_error("Niepoprawny typ zmiennych w wektorze");
    return in;
}


