#include "Vector.hpp" 
#include <iostream>

template <typename T>
Vector3<T>::Vector3(T x_, T y_, T z_)
    : x(x_), y(y_), z(z_) {}


// Unary operators
template <typename T>
Vector3<T> Vector3<T>::operator +(const Vector3<T>& vec) const
{
    Vector3<T> v;
    v.x = this->x + vec.x;
    v.y = this->y + vec.y;
    v.z = this->z + vec.z;
    return v;
}

template <typename T>
const Vector3<T>& Vector3<T>::operator +=(const Vector3<T>& vec)
{
    this->x += vec.x;
    this->y += vec.y;
    this->z += vec.z;
    return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator -(const Vector3<T>& vec) const
{
    Vector3<T> v;
    v.x = this->x - vec.x;
    v.y = this->y - vec.y;
    v.z = this->z - vec.z;
    return v;
}

template <typename T>
const Vector3<T>& Vector3<T>::operator -=(const Vector3<T>& vec)
{
    this->x -= vec.x;
    this->y -= vec.y;
    this->z -= vec.z;
    return *this;
}

// scalar
template <typename T>
Vector3<T> Vector3<T>::operator *(const T& scalar) const
{
    Vector3<T> v;
    v.x = this->x * scalar;
    v.y = this->y * scalar;
    v.z = this->z * scalar;
    return v;
}

template <typename T>
const Vector3<T>& Vector3<T>::operator *=(const T& scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    return *this;
}

template <typename T>
Vector3<T> Vector3<T>::operator /(const T& scalar) const
{
    Vector3<T> v;
    v.x = this->x / scalar;
    v.y = this->y / scalar;
    v.z = this->z / scalar;
    return v;
}

template <typename T>
const Vector3<T>& Vector3<T>::operator /=(const T& scalar)
{
    this->x /= scalar;
    this->y /= scalar;
    this->z /= scalar;
    return *this;
}

// Boolean
template <typename T>
bool Vector3<T>::operator ==(const Vector3<T>& vec) const
{
    return (this->x == vec.x && 
            this->y == vec.y &&
            this->z == vec.z);
}

template <typename T>
bool Vector3<T>::operator !=(const Vector3<T>& vec) const
{
    return (this->x != vec.x ||
            this->y != vec.y ||
            this->z != vec.z);
}