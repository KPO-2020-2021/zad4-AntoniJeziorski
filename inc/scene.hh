#pragma once

#include "size.hh"
#include "cuboid.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>

class Scene {

    Cuboid cube;

    Matrix3D Rotation;

    Matrix3D OneRotation;

    Vector3D Translation;

    public:

        Scene(Cuboid);

        void RotationMatrix(const Matrix3D);

        void TranslationVector(const Vector3D);

        void Move();

        Cuboid GetCuboid();

        void PrintRotation();

        Matrix3D GetOneRotationMatrix();

        void OneRotationMatrix(const Matrix3D);
};