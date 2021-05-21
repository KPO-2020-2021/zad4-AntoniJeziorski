#pragma once

#include "size.hh"
#include <iostream>
#include <iomanip>

/*!
 *
 * \file vector.hh
 * \brief Plik zawierający definicję szablonu wektora.
 */

/*!
 *
 * \brief Szablon klasy Vector.
 * 
 * Szablon umożliwiający utworzenie klasy Vector o dowolnym rozmiarze
 */ 

template <unsigned int Size>
class Vector {

    /*!
     *
     * \brief Jednowymiarowa tablica typu double przetrzymująca wartości współrzędnych wektora
     */

    double size[Size];

    public:

        /*!
         * 
         * \brief Konstruktor bezparametryczny klasy Vector.
         * 
         * Tworzy wektor wypelniony zerami
         */

        Vector<Size>();

        /*!
         * 
         * \brief Konstruktor parametryczny klasy Vector.
         *                                                 
         * Tworzy wektor, którego wpółrzędne mają wartości takie jak w tablicy podanej jako parametr.
         * \param tmp - Jednowymiarowa tablica typu double.                                                              
         */

        Vector<Size>(double [Size]); 
       
        /*!
         * 
         *
         * \brief Przeciążenie operatora dodawania wektorów
         * 
         * \param this - pierwszy składnik dodawania,
         *      
         * \param v - drugi składnik dodawania.
         * 
         * \return Sume dwóch składników przekazanych jako wskaźnik na parametr.
         */

        Vector<Size> operator + (const Vector<Size> &v); 

        /*!
         * 
         *
         * \brief Przeciążenie operatora odejmowania wektorów
         * 
         * \param this - odjemna,
         *      
         * \param v - odjemnik.
         * 
         * \return Różnicę dwóch wektorów przekazanych jako wskaźnik na parametr.
         */

        Vector<Size> operator - (const Vector<Size> &v); 

        /*!
         * 
         *
         * \brief Przeciążenie operatora mnozenia wektora razy double
         * 
         * \param this - pierwszy czynnik mnozenia,
         *      
         * \param tmp - drugi czynnik mnozenia.
         * 
         * \return Iloczyn wektora pomnożonego razy double.
         */

        Vector<Size> operator * (const double &tmp);

        /*!
         *
         * \brief Przeciążenie operatora dzielenia wektora przez double
         * 
         * \param this - dzielna
         * 
         * \param tmp - dzielnik
         * 
         * \return Iloraz wektora dzielonego przez double
         */

        Vector<Size> operator / (const double &tmp); 

        /*!
         *
         * \brief Przeciązenie operatora indeksującego dla odczytu
         * 
         * \param index - indeks wektora
         * 
         * \return Wartosc wektora w danym miejscu tablicy jako stala.
         */

        const double &operator [] (unsigned int index) const; 

        /*!
         *
         * \brief Przeciążenie operatora indeksującego dla zapisu
         * 
         * \param index - indeks wektora
         * 
         * \return Wartosc wektora w danym miejscu tablicy.
         */ 

        double &operator [] (unsigned int index); // Operator indeksujacy dla zapisu

        bool operator == (const Vector& tmp);
};

/*!
 *
 * \brief Przeciążenie operatora bitowego <<
 * 
 * Przeciążenie operatora bitowego << służące do wyświetlania wektora
 * 
 * \param out - referencja do strumienia ostream, do którego zostaną podane współrzędne wektora
 * 
 * \param tmp - Vector podany jako wskaźnik na parametr
 * 
 * \return Wypisuje wektor na podane wyjscie.
 */

template <unsigned int Size>
std::ostream &operator << (std::ostream &out, Vector<Size> const &tmp);

/*!
 *
 * \brief Przeciążenie operatora bitowego >>
 * 
 * Przeciążenie operatora bitowego >> służące do wpisywania wektora
 * 
 * \param in - referencja do strumienia istream, do którego zostaną podane współrzędne wektora
 * 
 * \param tmp - Vector podany jako wskaźnik na parametr
 * 
 * \return Podaje wektor na zadane wejście
 */

template <unsigned int Size>
std::istream &operator >> (std::istream &in, Vector<Size> &tmp); // Operator bitowy >>

template <unsigned int Size>
Vector<Size>::Vector() {
    for (unsigned int i = 0; i < Size; ++i) {
        size[i] = 0;
    }
}

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

template <unsigned int Size>
Vector<Size> Vector<Size>::operator + (const Vector<Size> &v) {
    Vector<Size> result;
    for (unsigned int i = 0; i < Size; ++i) {
        result[i] = size[i] + v[i];
    }
    return result;
}

template <unsigned int Size>
Vector<Size> Vector<Size>::operator - (const Vector<Size> &v) {
    Vector<Size> result;
    for (unsigned int i = 0; i < Size; ++i) {
        result[i] = size[i] - v[i];
    }
    return result;
}

template <unsigned int Size>
Vector<Size> Vector<Size>::operator * (const double &tmp) {
    Vector result;
    for (unsigned int i = 0; i < Size; ++i) {
        result[i] = size[i] * tmp;
    }
    return result;
}

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

template <unsigned int Size>
const double &Vector<Size>::operator [] (unsigned int index) const {
    if (index < 0 || index >= Size) {
        throw std::runtime_error("Error: Wektor jest poza zasiegiem!");
    }
    return size[index];
}

template <unsigned int Size>
double &Vector<Size>::operator[](unsigned int index) {
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}

template <unsigned int Size>
std::ostream &operator << (std::ostream &out, Vector<Size> const &tmp) {
    for (unsigned int i = 0; i < Size; ++i) {
        out << std::fixed << std::setprecision(10)  << tmp[i] << " ";
    }
    return out;
}

template <unsigned int Size>
std::istream &operator >> (std::istream &in, Vector<Size> &tmp) {
    for (unsigned int i = 0; i < Size; ++i) {
        in >> tmp[i];
    }
    if(in.fail()) {
        in.clear();
        throw std::invalid_argument("NIEPOPRAWNA WARTOSC WEKTORA\n");
        in.ignore(100000, '\n');
    }
    
    return in;
}

template <unsigned int Size>
bool Vector<Size>::operator == (const Vector<Size>& tmp) {
    for(unsigned int i = 0; i < Size; ++i) {
            if(!(size[i] >= tmp[i] - MAX_DIFF && size[i] <= tmp[i] + MAX_DIFF))
                return false;
        }
    return true;
}