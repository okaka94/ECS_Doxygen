#pragma once
#include "Define.h"
#include "LightData.h"

/**
 * @struct DirectionalLightComponent
 * @brief Color + Direction
*/
struct DirectionalLightComponent
{
	Vector4 Color;
	Vector4 Direction;
};

/**
 * @struct PointLightComponent
 * @brief Color + Direction + Radius
*/
struct PointLightComponent
{
	Vector4 Color;
	Vector4 Direction;
	float Radius;
};

/**
 * @struct SpotLightComponent
 * @brief Color + Direction + Radius
*/
struct SpotLightComponent
{
	Vector4 Color;
	Vector4 Direction;
	float Radius;
};