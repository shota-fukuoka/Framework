//=============================================================================
//
// vector.h
// Author : SHOTA FUKUOKA
//
//=============================================================================
#ifndef _VECTOR_H_
#define _VECTOR_H_

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class VECTOR2
{
public:
	float x;
	float y;

	VECTOR2() {}
	VECTOR2(const float nx, const float ny);

	//���Z
	VECTOR2 operator+(const VECTOR2 &Vector) const;
	VECTOR2 &operator+=(const VECTOR2 &Vector);

	//���Z
	VECTOR2 operator-(const VECTOR2 &Vector) const;
	VECTOR2 &operator-=(const VECTOR2 &Vector);

	//��Z
	template <typename T>
	VECTOR2 operator*(const T f) const;
	VECTOR2 &operator*=(const float f);

	//���Z
	VECTOR2 operator/(const float f) const;
	VECTOR2 &operator/=(const float f);

};

class VECTOR3
{
public:
	float x;
	float y;
	float z;

	VECTOR3(){}
	VECTOR3(const float nx, const float ny, const float nz);

	//���Z
	VECTOR3 operator+(const VECTOR3 &Vector) const;
	VECTOR3 &operator+=(const VECTOR3 &Vector);

	//���Z
	VECTOR3 operator-(const VECTOR3 &Vector) const;
	VECTOR3 &operator-=(const VECTOR3 &Vector);

	//��Z
	VECTOR3 operator*(const float f) const;
	VECTOR3 &operator*=(const float f);

	//���Z
	VECTOR3 operator/(const float f) const;
	VECTOR3 &operator/=(const float f);

	static void Cross(VECTOR3 *Vector, VECTOR3 *Vector1, VECTOR3 *Vector2);

	static void Normalize(VECTOR3 *Vector, VECTOR3 *Vector1);

	static float Length(VECTOR3 *Vector);

};

class VECTOR4
{
public:
	float x;
	float y;
	float z;
	float w;

	VECTOR4() {}
	VECTOR4(const float nx, const float ny, const float nz, const float nw);

	//���Z
	VECTOR4 operator+(const VECTOR4 &Vector) const;
	VECTOR4 &operator+=(const VECTOR4 &Vector);

	//���Z
	VECTOR4 operator-(const VECTOR4 &Vector) const;
	VECTOR4 &operator-=(const VECTOR4 &Vector);

	//��Z
	VECTOR4 operator*(const float f) const;
	VECTOR4 &operator*=(const float f);

	//���Z
	VECTOR4 operator/(const float f) const;
	VECTOR4 &operator/=(const float f);

};

#endif