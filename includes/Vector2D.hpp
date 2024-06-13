#ifndef VECTOR_2D_H
#define VECTOR_2D_H
#include <cmath>
class Vector2D {
  public:
    Vector2D(float x, float y) : x(x), y(y) {}
    float getX() const { return this->x; }
    float getY() const { return this->y; }
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    float length() { return sqrt(this->x * this->x + this->y * this->y); }

    Vector2D operator+(const Vector2D &v2) const {
        return Vector2D(this->x + v2.x, this->y + v2.y);
    }

    friend Vector2D &operator+=(Vector2D &v1, Vector2D &v2) {
        v1.x += v2.x;
        v1.y += v2.y;
        return v1;
    }
    Vector2D operator-(const Vector2D &v2) const {
        return Vector2D(this->x - v2.x, this->y - v2.y);
    }

    friend Vector2D &operator-=(Vector2D &v1, Vector2D &v2) {
        v1.x -= v2.x;
        v1.y -= v2.y;
        return v1;
    }
    Vector2D operator*(float scalar) {
        return Vector2D(this->x * scalar, this->y * scalar);
    }
    Vector2D &operator*=(float scalar) {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }
    Vector2D operator/(float scalar) {
        return Vector2D(this->x / scalar, this->y / scalar);
    }
    Vector2D &operator/=(float scalar) {
        this->x /= scalar;
        this->y /= scalar;
        return *this;
    }
    void normalize() {
        float len = this->length();
        if (len > 0)
            (*this) *= 1 / len;
    }

  private:
    float x;
    float y;
};
#endif
