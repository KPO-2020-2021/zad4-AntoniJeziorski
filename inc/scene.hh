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

        Scene(Cuboid);

        void RotationMatrix(const Matrix3D, const int CubeNumber);

        void TranslationVector(const Vector3D, const int CubeNumber);

        void Move(int CubeNumber);

        Cuboid GetCuboid(int CubeNumber);

        void PrintRotation(int CubeNumber);

        Matrix3D GetOneRotationMatrix(int CubeNumber);

        void OneRotationMatrix(const Matrix3D, int CubeNumber);

        void NewCuboid();
};