#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

template <typename T>
class Vector2
{
    public:
        T x;
        T y;

        Vector2();
        Vector2(T X, T Y);
};

// Input and output streams
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector2<T>& v);

template <typename T>
std::istream& operator>>(std::istream& is, Vector2<T>& v);

// Unary operators
template <typename T>
Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T>& operator+=(Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T>& operator-=(Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T> operator*(float scalar, const Vector2<T>& right);

template <typename T>
Vector2<T> operator*(const Vector2<T>& left, float scalar);

template <typename T>
Vector2<T>& operator*=(float scalar, Vector2<T>& right);

template <typename T>
Vector2<T> operator/(const Vector2<T>& left, float scalar);

template <typename T>
Vector2<T> operator/(float scalar, const Vector2<T>& right);

template <typename T>
Vector2<T>& operator/=(Vector2<T>&left, float scalar);

// Boolean
template <typename T>
bool operator==(const Vector2<T>& left, const Vector2<T>& right);

template <typename T>
bool operator!=(const Vector2<T>& left, const Vector2<T>& right);

// typedef vector types
#include "vector.inl"
typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;

#endif