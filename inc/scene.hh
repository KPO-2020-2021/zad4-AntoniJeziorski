#pragma once

#include "size.hh"
#include "cuboid.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>

class Scene {

    Cuboid cube;

    Matrix3D Rotation;

    Vector3D Translation;

    public:

        Scene(Cuboid);

        void RotationMatrix(const Matrix3D);

        void TranslationVector(const Vector3D);

        void Move();

        Cuboid GetCuboid();
        
        Matrix3D GetMatrix();

        void PrintRotation();
};