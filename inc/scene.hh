#pragma once

#include "size.hh"
#include "cuboid.hh"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>

class Scene {

    std::vector <Cuboid> cube;

    std::vector <Matrix3D> Rotation;

    std::vector <Matrix3D> OneRotation;

    std::vector <Vector3D> Translation;

    public:

        void RotationMatrix(const Matrix3D, const int);

        void TranslationVector(const Vector3D, const int);

        void Move(int);

        Cuboid GetCuboid(int);

        void PrintRotation(int);

        Matrix3D GetOneRotationMatrix(int);

        void OneRotationMatrix(const Matrix3D, int);

        void NewCuboid();

        void ClearOneRotationMatrix(int);
};