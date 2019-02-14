#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using std::ostream;
using std::istream;

class Vector {
    public:
        float x;
        float y;

        Vector(float xSet=0, float ySet=0);
        void set(float xSet, float ySet);
};

ostream& operator<<(ostream& os, const Vector& v);
istream& operator>>(istream& is, Vector& v);
Vector operator+(const Vector& left, const Vector& right);
Vector& operator+=(Vector& left, const Vector& right);
Vector operator-(const Vector& left, const Vector& right);
Vector& operator-=(Vector& left, const Vector& right);
Vector operator*(float scalar, const Vector&right);
Vector operator*(const Vector&left, float scalar);
Vector& operator*=(float scalar, Vector&right);
Vector operator/(const Vector&left, float scalar);
Vector operator/(float scalar, const Vector&right);
Vector& operator/=(Vector&left, float scalar);
bool operator==(const Vector& left, const Vector& right);

#endif