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

        void kon(Cuboid);

        void RotationMatrix(const Matrix3D);

        void TranslationVector(const Vector3D);

        void FillRotation(const Matrix3D);

        void Move();

        Cuboid GetCuboid();
};