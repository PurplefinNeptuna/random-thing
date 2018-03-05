#ifndef MY_VECTOR2D
#define MY_VECTOR2D
#include<SFML/System/Vector2.hpp>

class Vector2D {
  public:
	float X;
	float Y;

	//Vector Zero
	static const Vector2D Zero;

	//Standard Init (0,0)
	Vector2D();

	//Init w/Assigment
	Vector2D(float x, float y);

	//Init by copy
	Vector2D(const Vector2D& source);

	//Vector Magnitude
	static float Magnitude(const Vector2D& source);

	//Vector DotProduct
	static float DotProduct(const Vector2D& left, const Vector2D& right);

	//Angle between Vectors in Degree
	static float Angle(const Vector2D& origin, const Vector2D& target);

	//Vector Angle (by cartesian or screen position) in Degree
	static float Angle(const Vector2D& target, bool cartesian);
};

//overload unary negative
Vector2D operator-(const Vector2D& right);

//overload +=
Vector2D& operator+=(Vector2D& left, const Vector2D& right);

//overload -=
Vector2D& operator-=(Vector2D& left, const Vector2D& right);

//overload +
Vector2D operator+(const Vector2D& left, const Vector2D& right);

//overload -
Vector2D operator-(const Vector2D& left, const Vector2D& right);

//overload *
Vector2D operator*(const Vector2D& left, float right);

//overload *
Vector2D operator*(float left, const Vector2D& right);

//overload *=
Vector2D& operator*=(Vector2D& left, float right);

//overload /
Vector2D operator/(const Vector2D& left, float right);

//overload /=
Vector2D& operator/=(Vector2D& left, float right);

//overload ==
bool operator==(const Vector2D& left, const Vector2D& right);

//overload !=
bool operator!=(const Vector2D& left, const Vector2D& right);

//SFML Vector2f conversion
sf::Vector2f SFMLVector2f(const Vector2D& source);

#include "Vector2D.inl"

#endif
