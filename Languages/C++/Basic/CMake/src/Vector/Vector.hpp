#pragma once

#include <iostream>

template <typename T>
class Vector3
{
    public:
        union 
        {
            struct { T x, y, z; };
            T components[3];
        };
    public:
        Vector3() = default;
        Vector3(T x_, T y_, T z_);
        // unary
        Vector3<T> operator +(const Vector3<T>&) const;
        const Vector3<T>& operator +=(const Vector3<T>&);
        Vector3<T> operator -(const Vector3<T>&) const;
        const Vector3<T>& operator -=(const Vector3<T>&);
        // scalar
        Vector3<T> operator *(const T&) const;
        const Vector3<T>& operator *=(const T&);
        Vector3<T> operator /(const T&) const;
        const Vector3<T>& operator /=(const T&);
        // boolean
        bool operator ==(const Vector3<T>&) const;
        bool operator !=(const Vector3<T>&) const;
};

template <typename T>
std::ostream& operator <<(std::ostream& os, const Vector3<T>& vec)
{
    os << "{x:" << vec.x << 
          ",y:" << vec.y << 
          ",z:" << vec.z << 
          "}"   << std::endl;
    return os;  // Cascade assignment
}

template <typename T>
std::istream& operator >>(std::istream& is, Vector3<T>& vec)
{
    std::cout << "Enter x: ";
    is >> vec.x;
    std::cout << "Enter y: "; 
    is >> vec.y;
    std::cout << "Enter z: ";
    is >> vec.z;
    return is;
}


template class Vector3<char>;
template class Vector3<double>;
template class Vector3<float>;
template class Vector3<int>;
template class Vector3<unsigned char>;
template class Vector3<unsigned int>;