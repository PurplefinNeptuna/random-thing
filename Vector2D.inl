#include<cmath>
#include"Utility.hpp"

Vector2D::Vector2D():X(0),Y(0) {
}

Vector2D::Vector2D(float x, float y):X(x),Y(y) {
}

Vector2D::Vector2D(const Vector2D& source):X(source.X),Y(source.Y) {
}

Vector2D operator-(const Vector2D& right) {
	return Vector2D(-right.X, -right.Y);
}

Vector2D& operator+=(Vector2D& left, const Vector2D& right) {
	left.X += right.X;
	left.Y += right.Y;

	return left;
}

Vector2D& operator-=(Vector2D& left, const Vector2D& right) {
	left.X -= right.X;
	left.Y -= right.Y;

	return left;
}

Vector2D operator+(const Vector2D& left, const Vector2D& right) {
	return Vector2D(left.X + right.X, left.Y + right.Y);
}

Vector2D operator-(const Vector2D& left, const Vector2D& right) {
	return Vector2D(left.X - right.X, left.Y - right.Y);
}

Vector2D operator*(const Vector2D& left, float right) {
	return Vector2D(left.X * right, left.Y * right);
}

Vector2D operator*(float left, const Vector2D& right) {
	return Vector2D(right.X * left, right.Y * left);
}

Vector2D& operator*=(Vector2D& left, float right) {
	left.X *= right;
	left.Y *= right;

	return left;
}

Vector2D operator/(const Vector2D& left, float right) {
	return Vector2D(left.X / right, left.Y / right);
}

Vector2D& operator/=(Vector2D& left, float right) {
	left.X /= right;
	left.Y /= right;

	return left;
}

bool operator==(const Vector2D& left, const Vector2D& right) {
	return FEqual(left.X, right.X) && FEqual(left.Y, right.Y);
}

bool operator!=(const Vector2D& left, const Vector2D& right) {
	return (!FEqual(left.X, right.X)) || (!FEqual(left.Y, right.Y));
}

float Vector2D::Magnitude(const Vector2D& source) {
	return sqrt(source.X * source.X + source.Y * source.Y);
}

float Vector2D::DotProduct(const Vector2D& left, const Vector2D& right) {
	return left.X * right.X + left.Y * right.Y;
}

float Vector2D::Angle(const Vector2D& origin, const Vector2D& target) {
	return ToDegree(acos(std::min(std::max((DotProduct(origin, target)) / (Magnitude(origin) * Magnitude(target)), (float) -1.0), (float) 1.0))
	                * (std::signbit(origin.X * target.Y - origin.Y * target.X)?-1.0:1.0));
}

float Vector2D::Angle(const Vector2D& target, bool cartesian) {
	if(cartesian) {
		return Angle(Vector2D(0, 1), target);
	} else {
		return Angle(Vector2D(0, -1), target);
	}
}

sf::Vector2f SFMLVector2f(const Vector2D& source) {
	return sf::Vector2f(source.X, source.Y);
}

const Vector2D Vector2D::Zero(0,0);
