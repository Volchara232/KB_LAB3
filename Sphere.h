#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
private:
    Vector3 center;
    double radius;

public:
    Sphere(const Vector3& center, double radius, const Vector3& color);

    double intersect(const Ray& ray) const override;
    Vector3 getNormal(const Vector3& point) const override;

    Vector3 getCenter() const;
    double getRadius() const;
};

#endif