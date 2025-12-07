#include "Vector3.h"
#include <cmath>

Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector3::getX() const { return x; }
double Vector3::getY() const { return y; }
double Vector3::getZ() const { return z; }

void Vector3::setX(double val) { x = val; }
void Vector3::setY(double val) { y = val; }
void Vector3::setZ(double val) { z = val; }

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(double scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator/(double scalar) const {
    return Vector3(x / scalar, y / scalar, z / scalar);
}

double Vector3::dot(const Vector3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::normalize() const {
    double len = length();
    if (len > 0) {
        return Vector3(x / len, y / len, z / len);
    }
    return *this;
}

double Vector3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

double Vector3::lengthSquared() const {
    return x * x + y * y + z * z;
}

Vector3 Vector3::multiply(const Vector3& other) const {
    return Vector3(x * other.x, y * other.y, z * other.z);
}

// Внешний оператор
Vector3 operator*(double scalar, const Vector3& vec) {
    return vec * scalar;
}