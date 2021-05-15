#include "scene.hh"


Scene::Scene(Cuboid c) {
    cube = c;
}

void Scene::RotationMatrix(const Matrix3D matrix) {
    Matrix3D tmp = matrix;
    Rotation = tmp * Rotation;
}

void Scene::TranslationVector(const Vector3D vector) {
    Vector3D tmp = vector;
    Translation = Translation + tmp;
}

void Scene::Move() {
    for(int i=0; i<CUBE; ++i) {
        cube[i] = Rotation * cube(i) + Translation;
    }
}

Cuboid Scene::GetCuboid() {
    return cube;
}

void Scene::PrintRotation() {
    std::cout << Rotation << std::endl;
}

Matrix3D Scene::GetOneRotationMatrix() {
    return OneRotation;
}

void Scene::OneRotationMatrix(const Matrix3D matrix) {
    Matrix3D tmp = matrix;
    OneRotation = tmp * OneRotation;
}