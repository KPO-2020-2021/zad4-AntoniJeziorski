#pragma once

#include "matrix.hh"

/*!
 *
 * \file matrix3D.hh
 * \brief Plik zawierający definicję klasy Matrix3D.
 */


/*!
 *
 * \brief Definicja klasy Matrix3D utworzona przy pomocy szablonu Matrix<Size>
 */

typedef Matrix<3> Matrix3D;

/*!
 *
 * \brief Funkcja wypełniająca macierz odpowiendimi wartościami, które tworzą macierz rotacji w osi OX
 * 
 * \param angle - kąt o jaki chcemy obrócić punk
 * 
 * \return Macierz obrotu dla osi OX
 */

Matrix3D RotationMatrix_X(const double angle);  

/*!
 *
 * \brief Funkcja wypełniająca macierz odpowiendimi wartościami, które tworzą macierz rotacji w osi OY
 * 
 * \param angle - kąt o jaki chcemy obrócić punk
 * 
 * \return Macierz obrotu dla osi OY
 */

Matrix3D RotationMatrix_Y(const double angle); 

/*!
 *
 * \brief Funkcja wypełniająca macierz odpowiendimi wartościami, które tworzą macierz rotacji w osi OZ
 * 
 * \param angle - kąt o jaki chcemy obrócić punk
 * 
 * \return Macierz obrotu dla osi OZ
 */

Matrix3D RotationMatrix_Z(const double angle);  