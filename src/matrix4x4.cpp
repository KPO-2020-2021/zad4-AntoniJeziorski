#include "matrix4x4.hh"

/*!
 *
 * \file matrix4x4.cpp
 * 
 * \brief Plik zawierajacy definicje metody dla macierzy 4x4
 */

Matrix4x4 RotationMatrix(double alpha, double beta, double gamma, Vector3D translation) {
    Matrix4x4 result;

    result(0,0) = cos(alpha*M_PI/180) * cos(beta*M_PI/180);
    result(0,1) = cos(alpha*M_PI/180) * sin(beta*M_PI/180) * sin(gamma*M_PI/180) - sin(alpha*M_PI/180) * cos(gamma*M_PI/180);
    result(0,2) = cos(alpha*M_PI/180) * sin(beta*M_PI/180) * cos(gamma*M_PI/180) + sin(alpha*M_PI/180) * sin(gamma*M_PI/180);
    result(0,3) = translation[0];
    result(1,0) = sin(alpha*M_PI/180) * cos(beta*M_PI/180);
    result(1,1) = sin(alpha*M_PI/180) * sin(beta*M_PI/180) * sin(gamma*M_PI/180) + cos(alpha*M_PI/180) * cos(gamma*M_PI/180);
    result(1,2) = sin(alpha*M_PI/180) * sin(beta*M_PI/180) * cos(gamma*M_PI/180) - cos(alpha*M_PI/180) * sin(gamma)*M_PI/180;
    result(1,3) = translation[1];
    result(2,0) = -sin(beta*M_PI/180);
    result(2,1) = cos(beta*M_PI/180) * sin(gamma*M_PI/180);
    result(2,2) = cos(beta*M_PI/180) * cos(gamma*M_PI/180);
    result(2,3) = translation[2];
    result(3,0) = 0;
    result(3,1) = 0;
    result(3,2) = 0;
    result(3,3) = 1;

    return result;
}