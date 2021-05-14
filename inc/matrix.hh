#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>

template <unsigned int Size>
class Matrix {

double value[Size][Size];               // Wartosci macierzy

public:
    Matrix(double [Size][Size]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Vector<Size> operator * (const Vector<Size> tmp);           // Operator mnożenia przez wektor

    Matrix operator + (const Matrix tmp);           // Operator dodawania macierzy

    Matrix operator * (const Matrix tmp);           // Operator mnozenia macierzy

    double  &operator () (unsigned int row, unsigned int column);     // Operator funkcyjny dla odczytu
    
    const double &operator () (unsigned int row, unsigned int column) const; // operator funkcyjny dla zapisu

    double Determinant() const;
};

template <unsigned int Size>
std::istream &operator>>(std::istream &in, Matrix<Size> &mat);  // Operator bitowy >>

template <unsigned int Size>
std::ostream &operator<<(std::ostream &out, Matrix<Size> const &mat); // Operator bitowy <<


/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */

template <unsigned int Size>
Matrix<Size>::Matrix() {
    for (unsigned int i = 0; i < Size; ++i) {
        for (unsigned int j = 0; j < Size; ++j) {
            if(i==j){
                value[i][j] = 0;
            }
            else{
                value[i][j] = 1;
            }
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */

template <unsigned int Size>
Matrix<Size>::Matrix(double tmp[Size][Size]) {
    if((SIZE < 0) || (SIZE > 3)) {
        throw std::runtime_error("Niepoprawny rozmiar macierzy");
    }
    else {
        for (unsigned int i = 0; i < Size; ++i) {
            for (unsigned int j = 0; j < Size; ++j) {
                value[i][j] = tmp[i][j];
            }
        }
    }
    
}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - Matrix, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

template <unsigned int Size>
Vector<Size> Matrix<Size>::operator * (const Vector<Size> tmp) {
    Vector<Size> result;
    for (unsigned int i = 0; i < Size; ++i) {
        for (unsigned int j = 0; j < Size; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor macierzy                                                         |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */

template <unsigned int Size>
double &Matrix<Size>::operator()(unsigned int row, unsigned int column) {

    if (row >= Size) {
        throw std::runtime_error("Error: Macierz jest poza zasiegiem"); 
    }

    if (column >= Size) {
        throw std::runtime_error("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor Matrixy                                                           |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */

template <unsigned int Size>
const double &Matrix<Size>::operator () (unsigned int row, unsigned int column) const {

    if (row >= Size) {
        throw std::runtime_error("Error: Macierz jest poza zasiegiem");
    }

    if (column >= Size) {
        throw std::runtime_error("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}


/******************************************************************************
 |  Przeciążenie dodawania macierzy                                           |
 |  Argumenty:                                                                |
 |      this - Matrix, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                           |
 |  Zwraca:                                                                   |
 |      Matrix - iloczyn dwóch podanych macierzy.                             |
 */

template <unsigned int Size>
Matrix<Size> Matrix<Size>::operator + (const Matrix<Size> tmp) {
    Matrix result;
    for (unsigned int i = 0; i < Size; ++i) {
        for (unsigned int j = 0; j < Size; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - Matrix.                                                         |
 */

template <unsigned int Size>
std::istream &operator>>(std::istream &in, Matrix<Size> &mat) {
    for (unsigned int i = 0; i < Size; ++i) {
        for (unsigned int j = 0; j < Size; ++j) {
            in >> mat(i, j);
        }
    }
    if(in.fail())
        throw std::runtime_error("Niepoprawny typ zmiennej w macierzy");
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - Matrix.                                                         |
 */

template <unsigned int Size>
std::ostream &operator<<(std::ostream &out, const Matrix<Size> &mat) {
    for (unsigned int i = 0; i < Size; ++i) {
        for (unsigned int j = 0; j < Size; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}


/*!
 * Metoda tworzaca macierz obrotu
 * Argumenty:
 *      this - macierz, ktora zostanie wypelniona odpowiednimi wartosciami
 *      angle - kat o jaki chcemy obrocic prostokat
 */



template <unsigned int Size>
double Matrix<Size>::Determinant() const {
    double det, ratio;
    Matrix<Size> tmp = *this;
    for(unsigned int i=0; i < Size; i++) {
        if(tmp(i,i) == 0) {
            throw std::runtime_error("Blad macierzy");
        }
        for(int j = i + 1; j < Size; j++) {
            ratio = tmp(j,i)/tmp(i,i);
            for(int k = 0; k < Size; k++) {
                tmp(j,k) = tmp(j,k) - ratio*tmp(i,k);
            }
        }
    }
    det = tmp(0,0) * tmp(1,1);
    return det;   
}


template <unsigned int Size>
Matrix<Size> Matrix<Size>::operator * (const Matrix<Size> tmp) {
    Matrix<Size> result;
    for (unsigned int i = 0; i < Size; ++i) {
        for (unsigned int j = 0; j < Size; ++j) {
            result(i, j) = 0;
            for (unsigned int k = 0; k < Size; ++k)
                result(i, j) += value[i][k] * tmp(k, j);
        }
    }
    return result;
}