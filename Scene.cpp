#include "Scene.h"

Scene::Scene() : plane(Vector3(0, -2, 0), Vector3(0, 1, 0), Vector3(0.8, 0.8, 0.8)) {
    lightDir = Vector3(-1, -1, -1).normalize();
    lightColor = Vector3(1, 1, 1);
    ambientColor = Vector3(0.1, 0.1, 0.1);

    spheres.push_back(Sphere(Vector3(-2, 0, -5), 1.0, Vector3(1, 0, 0)));
    spheres.push_back(Sphere(Vector3(0, 0, -7), 1.5, Vector3(0, 1, 0)));
    spheres.push_back(Sphere(Vector3(2, 0, -5), 1.0, Vector3(0, 0, 1)));
}

const std::vector<Sphere>& Scene::getSpheres() const { return spheres; }
const Plane& Scene::getPlane() const { return plane; }
Vector3 Scene::getLightDir() const { return lightDir; }
Vector3 Scene::getLightColor() const { return lightColor; }
Vector3 Scene::getAmbientColor() const { return ambientColor; }