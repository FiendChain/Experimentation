#include <iostream>

template <typename T>
inline Vector2<T>::Vector2() 
: x(0), y(0)
{}

template <typename T>
inline Vector2<T>::Vector2(T X, T Y)
: x(X), y(Y)
{}

template <typename T>
inline std::ostream& operator <<(std::ostream& os, const Vector2<T>& v)
{
    os << "{x: " << v.x << ", y: " << v.y << "}\n";
    return os;  // Cascade assignment
}

template <typename T>
inline std::istream& operator >>(std::istream& is, Vector2<T>& v)
{
    std::cout << "Enter x: ";
    is >> v.x;
    std::cout << "Enter y: ";
    is >> v.y;
    return is;
}

// Unary operator s
template <typename T>
inline Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right) 
{
    Vector2<T> v();
    v.x = left.x + right.x;
    v.y = left.y + right.y;
    return v;
}

template <typename T>
inline Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}

template <typename T>
inline Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right)
{
    Vector2<T> v();
    v.x = left.x - right.x;
    v.y = left.y - right.y;
    return v;
}

template <typename T>
inline Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}

template <typename T>
inline Vector2<T> operator *(float scalar, const Vector2<T>& right)
{
    Vector2<T> v();
    v.x = scalar * right.x;
    v.y = scalar * right.y;
    return v;
}

template <typename T>
inline Vector2<T> operator *(const Vector2<T>& left, float scalar)
{
    return scalar * left;
}

template <typename T>
inline Vector2<T>& operator *=(float scalar, Vector2<T>& right)
{
    right.x *= scalar;
    right.y *= scalar;
    return right;
}

template <typename T>
inline Vector2<T> operator /(const Vector2<T>& left, float scalar)
{
    Vector2<T> v();
    v.x = left.x / scalar;
    v.y = left.y / scalar;
    return v;
}

template <typename T>
inline Vector2<T> operator /(float scalar, const Vector2<T>& right)
{
    return right / scalar;
}

template <typename T>
inline Vector2<T>& operator /=(Vector2<T>&left, float scalar)
{
    left.x /= scalar;
    left.y /= scalar;
    return left;
}

// Boolean
template <typename T>
inline bool operator ==(const Vector2<T>& left, const Vector2<T>& right)
{
    return (left.x == right.x && left.y == right.y);
}

template <typename T>
inline bool operator !=(const Vector2<T>& left, const Vector2<T>& right)
{
    return !(left == right);
}


