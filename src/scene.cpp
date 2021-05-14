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


void Scene::FillRotation(const Matrix3D matrix) {
    Matrix3D tmp = matrix;
    Rotation = tmp * Rotation;
}

void Scene::Move() {
    for(int i=0; i<CUBE; ++i) {
        cube[i] = Rotation * cube[i];
        cube[i] = cube[i] + Translation;
    }
}

Cuboid Scene::GetCuboid() {
    return cube;
}