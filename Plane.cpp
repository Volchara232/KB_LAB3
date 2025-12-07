#include "Plane.h"
#include <cmath>

Plane::Plane(const Vector3& point, const Vector3& normal, const Vector3& color)
    : Shape(color), point(point), normal(normal.normalize()) {
}

double Plane::intersect(const Ray& ray) const {
    double denom = normal.dot(ray.getDirection());
    if (std::abs(denom) > 0.001) {
        Vector3 p0l0 = point - ray.getOrigin();
        double t = p0l0.dot(normal) / denom;
        if (t > 0.001) return t;
    }
    return -1.0;
}

Vector3 Plane::getNormal(const Vector3& point) const {
    return normal;
}