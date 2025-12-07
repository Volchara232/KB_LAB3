#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <vector>
#include "Scene.h"

class RayTracer {
private:
    Scene scene;
    int width, height;

    Vector3 traceRay(const Ray& ray, int depth = 0);

public:
    RayTracer(int w, int h);
    std::vector<Vector3> render();
};

#endif