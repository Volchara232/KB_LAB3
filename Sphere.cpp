#include "Sphere.h"
#include <cmath>

Sphere::Sphere(const Vector3& center, double radius, const Vector3& color)
    : Shape(color), center(center), radius(radius) {
}

double Sphere::intersect(const Ray& ray) const {
    Vector3 oc = ray.getOrigin() - center;
    double a = ray.getDirection().dot(ray.getDirection());
    double b = 2.0 * oc.dot(ray.getDirection());
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return -1.0;
    }

    double sqrtDisc = std::sqrt(discriminant);
    double t1 = (-b - sqrtDisc) / (2.0 * a);
    double t2 = (-b + sqrtDisc) / (2.0 * a);

    if (t1 > 0.001) return t1;
    if (t2 > 0.001) return t2;
    return -1.0;
}

Vector3 Sphere::getNormal(const Vector3& point) const {
    return (point - center).normalize();
}

Vector3 Sphere::getCenter() const { return center; }
double Sphere::getRadius() const { return radius; }