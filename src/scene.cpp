#include "scene.hh"

/* Scene::Scene() {
    double X[3]={2,3,3}, Y[3]={22,3,3}, Z[3]={2,18,3}, T[3]={22,18,3}, A[3]={2,18,28}, B[3]={22,18,28}, C[3]={2,3,28}, D[3]={22,3,28}, V[3] = {-2,-3,-3}; //angle, amount; // tablice typu double z wartosciami wierzcholkow bazowego prostokata, kat do obrotu, ilosc obrotow
    Vector<SIZE> x(X), y(Y), z(Z), t(T),a(A),b(B), c(C), d(D), v(V); // Wektory reprezentujace wierzcholki prostokata i wektor do translacji
    Cuboid Cub(x, y, z, t,a,b,c,d);   // Prostokat
    cube = Cub;
} */

void Scene::kon(Cuboid c) {
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