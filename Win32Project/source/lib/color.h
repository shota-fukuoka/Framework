//=============================================================================
//
// color.h
// Author : SHOTA FUKUOKA
//
//=============================================================================
#ifndef _COLOR_H_
#define _COLOR_H_

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class COLOR
{
public:
	float r;
	float g;
	float b;
	float a;

	COLOR() {}
	COLOR(const float nr, const float ng, const float nb, const float na);

	//���Z
	COLOR operator+(const COLOR &Color) const;
	COLOR &operator+=(const COLOR &Color);

	//���Z
	COLOR operator-(const COLOR &Color) const;
	COLOR &operator-=(const COLOR &Color);

	//��Z
	COLOR operator*(const float f) const;
	COLOR &operator*=(const float f);

	//���Z
	COLOR operator/(const float f) const;
	COLOR &operator/=(const float f);

	//�F�w��
	COLOR black() { return COLOR(0, 0, 0, 1); }
	COLOR blue() { return COLOR(0, 0, 1, 1); }
	COLOR clear() { return COLOR(0, 0, 0, 0); }
	COLOR cyan() { return COLOR(0, 1, 1, 1); }
	COLOR gray() { return COLOR(0.5f, 0.5f, 0.5f, 1); }
	COLOR green() { return COLOR(0, 1, 0, 1); }
	COLOR magenta() { return COLOR(1, 0, 1, 1); }
	COLOR red() { return COLOR(1, 0, 0, 1); }
	COLOR white() { return COLOR(1, 1, 1, 1); }
	COLOR yellow() { return COLOR(1, 0.92f, 0.016f, 1); }
};

#endif