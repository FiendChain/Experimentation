#include <iostream>

using std::cin;
using std::cout;
using std::ostream;
using std::istream;

class Vector {
    public:
        Vector(float x=0, float y=0) {
            x_ = x;
            y_ = y;
        }

        float getX() const { 
            return x_;
        }

        float getY() const {
            return y_;
        }

        void setX(float x) {
            x_ = x;
        }

        void setY(float y) {
            y_ = y;
        }

        void set(float x, float y) {
            x_ = x;
            y_ = y;
        }

        // Create friends
        friend ostream& operator<<(ostream& os, const Vector& v);
        friend istream& operator>>(istream& is, Vector& v);
        friend Vector operator+(const Vector& left, const Vector& right);
        friend Vector& operator+=(Vector& left, const Vector& right);
        friend Vector operator-(const Vector& left, const Vector& right);
        friend Vector& operator-=(Vector& left, const Vector& right);
        friend Vector operator*(float scalar, const Vector&right);
        friend Vector operator*(const Vector&left, float scalar);
        friend Vector& operator*=(float scalar, Vector&right);
        friend Vector operator/(const Vector&left, float scalar);
        friend Vector operator/(float scalar, const Vector&right);
        friend Vector& operator/=(Vector&left, float scalar);
        friend bool operator==(const Vector& left, const Vector& right);

    private:
        float x_;
        float y_;
};

// Input and output streams
ostream& operator<<(ostream& os, const Vector& v) {
    os << "{x: " << v.x_ << ", y: " << v.y_ << "}\n";
    return os;  // Cascade assignment
}

istream& operator>>(istream& is, Vector& v) {
    cout << "Enter x: ";
    is >> v.x_;
    cout << "Enter y: ";
    is >> v.y_;
    return is;
}

// Unary operators
Vector operator+(const Vector& left, const Vector& right) {
    Vector result(left.x_ + right.x_, left.y_ + right.y_);
    return result;
}

Vector& operator+=(Vector& left, const Vector& right) {
    left.x_ += right.x_;
    left.y_ += right.y_;
    return left;
}

Vector operator-(const Vector& left, const Vector& right) {
    Vector result(left.x_ - right.x_, left.y_ - right.y_);
    return result;
}

Vector& operator-=(Vector& left, const Vector& right) {
    left.x_ -= right.x_;
    left.y_ -= right.y_;
    return left;
}

Vector operator*(float scalar, const Vector&right) {
    Vector result(right.x_*scalar, right.y_*scalar);
    return result;
}

Vector operator*(const Vector&left, float scalar) {
    Vector result(left.x_*scalar, left.y_*scalar);
    return result;
}

Vector& operator*=(float scalar, Vector&right) {
    right.x_ *= scalar;
    right.y_ *= scalar;
    return right;
}

Vector operator/(const Vector&left, float scalar) {
    Vector result(left.x_/scalar, left.y_/scalar);
    return result;
}

Vector operator/(float scalar, const Vector&right) {
    Vector result(scalar/right.x_, scalar/right.y_);
    return result;
}

Vector& operator/=(Vector&left, float scalar) {
    left.x_ /= scalar;
    left.y_ /= scalar;
    return left;
}

// Boolean
bool operator==(const Vector& left, const Vector& right) {
    return (left.x_ == right.x_ && left.y_ == right.y_);
}

bool operator!=(const Vector& left, const Vector& right) {
    return !(left == right);
}

Vector foo(float x, float y) {
    Vector v(x, y);
    return v;
}

int main(int argc, char *argv[]) {
    Vector a;
    Vector b;
    Vector c;
    cout << "Enter values for a:\n";
    cin >> a;
    cout << "Enter values for b:\n";
    cin >> b;
    if(a==b) {
        cout << "a is equal to b\n";
    } else {
        cout << "a is not equal to b\n";
    } 
    cout << "a = " << a << "b = " << b;
    c = 5*(5*a - b/10.0f)*5 - a/5.6 + 1/b;
    for(int i = 0; i < 10; i ++) {
        foo(i+1, i-1);
    }
    cout << "c = " << c; 

    return 0;
}
