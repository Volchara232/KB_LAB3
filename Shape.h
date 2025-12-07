#ifndef SHAPE_H
#define SHAPE_H

#include "Ray.h"

class Shape {
protected:
    Vector3 color;

public:
    Shape(const Vector3& color);
    virtual ~Shape() {}

    virtual double intersect(const Ray& ray) const = 0;
    virtual Vector3 getNormal(const Vector3& point) const = 0;
    virtual Vector3 getColor(const Vector3& point) const;
};

#endif