#include "Ray.h"

Ray::Ray(const Vector3& origin, const Vector3& direction)
    : origin(origin), direction(direction.normalize()) {
}

Vector3 Ray::getOrigin() const { return origin; }
Vector3 Ray::getDirection() const { return direction; }

Vector3 Ray::pointAt(double t) const {
    return origin + direction * t;
}