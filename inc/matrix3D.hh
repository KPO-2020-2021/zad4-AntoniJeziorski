#pragma once

#include "matrix.hh"

typedef Matrix<3> Matrix3D;

Matrix3D RotationMatrix_X(const double);  // Metoda tworzaca macierz obrotu dla osi X

Matrix3D RotationMatrix_Y(const double);  // Metoda tworzaca macierz obrotu dla osi Y

Matrix3D RotationMatrix_Z(const double);  // Metoda tworzaca macierz obrotu dla osi Z