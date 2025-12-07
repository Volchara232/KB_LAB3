#ifndef PLANE_H
#define PLANE_H

#include "Shape.h"

class Plane : public Shape {
private:
    Vector3 point;
    Vector3 normal;

public:
    Plane(const Vector3& point, const Vector3& normal, const Vector3& color);

    double intersect(const Ray& ray) const override;
    Vector3 getNormal(const Vector3& point) const override;
};

#endif