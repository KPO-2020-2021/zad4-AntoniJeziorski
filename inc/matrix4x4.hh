#pragma once

#include <matrix.hh>
#include <vector3D.hh>

/*!
 *
 * \file matrix4x4.hh
 * \brief Plik zawierający definicję klasy Matrix3D.
 */


/*!
 *
 * \brief Definicja klasy Matrix4x4 utworzona przy pomocy szablonu Matrix<Size>
 */


typedef Matrix<4> Matrix4x4;


/*!
 *
 * \brief metoda tworzaca polaczona macierz rotacji z translacja 
 * 
 * \param alpha - kat obrotu wokol osi OZ
 * 
 * \param beta - kat obrotu wokol osi OY
 * 
 * \param gamma - kat obrotu wokol osi OX
 * 
 * \param translation - wektor translacji
 * 
 * \return Macierz wypelniona odpowiednimi wartosciami
 */

Matrix4x4 RotationMatrix(double alpha, double beta, double gamma, Vector3D translation);