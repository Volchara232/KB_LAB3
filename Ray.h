#ifndef RAY_H
#define RAY_H

#include "Vector3.h"

class Ray {
private:
    Vector3 origin;
    Vector3 direction;

public:
    Ray(const Vector3& origin, const Vector3& direction);

    Vector3 getOrigin() const;
    Vector3 getDirection() const;

    Vector3 pointAt(double t) const;
};

#endif