#include "Vector.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::ostream;
using std::istream;

Vector::Vector(float xSet, float ySet) {
    x = xSet;
    y = ySet;
}

void Vector::set(float xSet, float ySet) {
    x = xSet;
    y = ySet;
}

// Input and output streams
ostream& operator<<(ostream& os, const Vector& v) {
    os << "{x: " << v.x << ", y: " << v.y << "}\n";
    return os;  // Cascade assignment
}

istream& operator>>(istream& is, Vector& v) {
    cout << "Enter x: ";
    is >> v.x;
    cout << "Enter y: ";
    is >> v.y;
    return is;
}

// Unary operators
Vector operator+(const Vector& left, const Vector& right) {
    Vector result(left.x + right.x, left.y + right.y);
    return result;
}

Vector& operator+=(Vector& left, const Vector& right) {
    left.x += right.x;
    left.y += right.y;
    return left;
}

Vector operator-(const Vector& left, const Vector& right) {
    Vector result(left.x - right.x, left.y - right.y);
    return result;
}

Vector& operator-=(Vector& left, const Vector& right) {
    left.x -= right.x;
    left.y -= right.y;
    return left;
}

Vector operator*(float scalar, const Vector&right) {
    Vector result(right.x*scalar, right.y*scalar);
    return result;
}

Vector operator*(const Vector&left, float scalar) {
    Vector result(left.x*scalar, left.y*scalar);
    return result;
}

Vector& operator*=(float scalar, Vector&right) {
    right.x *= scalar;
    right.y *= scalar;
    return right;
}

Vector operator/(const Vector&left, float scalar) {
    Vector result(left.x/scalar, left.y/scalar);
    return result;
}

Vector operator/(float scalar, const Vector&right) {
    Vector result(scalar/right.x, scalar/right.y);
    return result;
}

Vector& operator/=(Vector&left, float scalar) {
    left.x /= scalar;
    left.y /= scalar;
    return left;
}

// Boolean
bool operator==(const Vector& left, const Vector& right) {
    return (left.x == right.x && left.y == right.y);
}

bool operator!=(const Vector& left, const Vector& right) {
    return !(left == right);
}