#pragma once
#include "Define.h"

/**
 * @struct MovementComponent
 * @brief [C] Location 벡터, Forward 벡터, Speed로 구성되어있다.
*/
struct MovementComponent
{
	Vector3 Location;
	Vector3 Forword;
	float	Speed;

	MovementComponent() : Location(Vector3(0.0f, 0.0f, 0.0f)), Forword(Vector3(0.0f, 0.0f, 0.0f)), Speed(0.0f) {};
	MovementComponent(Vector3 location, Vector3 forword, float speed) : Location(location), Forword(forword), Speed(speed) {};
};