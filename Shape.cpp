#include "Shape.h"

Shape::Shape(const Vector3& color) : color(color) {}

Vector3 Shape::getColor(const Vector3& point) const {
    return color;
}