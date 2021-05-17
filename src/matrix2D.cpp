#include "matrix2D.hh"

Matrix2D RotationMatrix(const double angle) {
    Matrix2D tmp;
    tmp(0,0) = cos(angle*M_PI/180);
    tmp(0,1) = -sin(angle*M_PI/180);
    tmp(1,0) = sin(angle*M_PI/180);
    tmp(1,1) = cos(angle*M_PI/180);
    return tmp;
}