#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>


/*!
 *
 * \file matrix.hh
 * \brief Plik zawierający definicję szablonu macierzy.
 */

/*!
 *
 * \brief Szablon klasy Vector.
 * 
 * Szablon umożliwiający utworzenie klasy Matrix o dowolnym rozmiarze
 */ 

template <unsigned int Size>
class Matrix {

    /*!
     *
     * \brief Dwuwymiarowa tablica typu double przetrzymująca wartości współrzędnych wektora
     * 
     */

double value[Size][Size];               

public:

    /*!
     * 
     * \brief Konstruktor bezparametryczny klasy Matrix.
     * 
     * Tworzy macierz jedynkową
     */

    Matrix(); 

    /*!
     * 
     * \brief Konstruktor parametryczny klasy Matrix.
     *                                                 
     * Tworzy macierz, której wpółrzędne mają wartości takie jak w tablicy podanej jako parametr.
     * \param tmp - Dwuwymiarowa tablica typu double.                                                              
     */

    Matrix(double [Size][Size]);          
    
    /*!
     *
     * \brief Przeciążenie operatora mnożenia macierzyrazy wektor
     * 
     * \param this - pierwszy czynnik -  macierz
     * 
     * \param tmp - drugi czynnik - wektor
     * 
     * \return Wektor będący wynikiem mnożenia macierzy razy wektor podanych jako wskaźnik na parametr
     */

    Vector<Size> operator * (const Vector<Size> tmp);           // Operator mnożenia przez wektor

    /*!
     * 
     *
     * \brief Przeciążenie operatora dodawania macierzy
     * 
     * \param this - pierwszy skladnik,
     *      
     * \param tmp - drugi skladnik.
     * 
     * \return Sumę dwóch macierzy przekazanych jako wskaźnik na parametr.
     */

    Matrix operator + (const Matrix tmp);           // Operator dodawania macierzy

    Matrix operator * (const Matrix tmp);           // Operator mnozenia macierzy

    double  &operator () (unsigned int row, unsigned int column);     // Operator funkcyjny dla odczytu

    const double &operator () (unsigned int row, unsigned int column) const; // operator funkcyjny dla zapisu

    double Determinant() const;

    bool operator == (const Matrix tmp);
};

template <unsigned int Size>
std::istream &operator>>(std::istream &in, Matrix<Size> &mat);  // Operator bitowy >>

template <unsigned int Size>
std::ostream &operator<<(std::ostream &out, Matrix<Size> const &mat); // Operator bitowy <<

template <unsigned int Size>
Matrix<Size>::Matrix() {
    for (unsigned int i = 0; i < Size; ++i) {
        for (unsigned int j = 0; j < Size; ++j) {
            if(i==j){
                value[i][j] = 1;
            }
            else{
                value[i][j] = 0;
            }
        }
    }
}

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

template <unsigned int Size>
bool Matrix<Size>::operator == (const Matrix<Size> tmp) {
    for(unsigned int i = 0; i < Size; ++i) {
        for(unsigned int j = 0; j < Size; ++j) {
            if(!(value[i][j] >= tmp(i, j) - MAX_DIFF && value[i][j] <= tmp(i, j) + MAX_DIFF))
                return false;
        }
    }
    return true;
}