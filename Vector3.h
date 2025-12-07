#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
private:
    double x, y, z;

public:
    Vector3();
    Vector3(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double val);
    void setY(double val);
    void setZ(double val);

    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(double scalar) const;
    Vector3 operator/(double scalar) const;

    double dot(const Vector3& other) const;
    Vector3 normalize() const;
    double length() const;
    double lengthSquared() const;

    // Компонентное умножение
    Vector3 multiply(const Vector3& other) const;
};

// Внешний оператор для умножения скаляра на вектор
Vector3 operator*(double scalar, const Vector3& vec);

#endif