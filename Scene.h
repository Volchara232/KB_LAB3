#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Sphere.h"
#include "Plane.h"

class Scene {
private:
    std::vector<Sphere> spheres;
    Plane plane;
    Vector3 lightDir;
    Vector3 lightColor;
    Vector3 ambientColor;

public:
    Scene();

    const std::vector<Sphere>& getSpheres() const;
    const Plane& getPlane() const;
    Vector3 getLightDir() const;
    Vector3 getLightColor() const;
    Vector3 getAmbientColor() const;
};

#endif