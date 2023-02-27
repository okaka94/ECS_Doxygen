#pragma once
#include "Define.h"
#define MAX_LIGHT_CNT (int)100

/**
 * @class DirectionalLightData
 * @brief [상수버퍼 데이터] Directional Light 데이터를 담는 구조체로 색상과 방향을 저장한다.
*/
struct DirectionalLightData
{
	Vector4 Color[MAX_LIGHT_CNT];
	Vector4 Direction[MAX_LIGHT_CNT];
	int Cnt;
	int dummy1;
	int dummy2;
	int dummy3;
};

/**
 * @class SpotLightData
 * @brief [상수버퍼 데이터] Spot Light 데이터를 담는 구조체로 색상, 방향과 위치, 반경을 저장한다.
*/
struct SpotLightData
{
	Vector4 Color[MAX_LIGHT_CNT];
	Vector4 Position[MAX_LIGHT_CNT];
	Vector4 Direction[MAX_LIGHT_CNT];
	float Radius[MAX_LIGHT_CNT];
	int Cnt = 0;
	int dummy1;
	int dummy2;
	int dummy3;
};

/**
 * @class PointLightData
 * @brief [상수버퍼 데이터] Point Light 데이터를 담는 구조체로 색상, 방향과 위치, 반경을 저장한다.
*/
struct PointLightData
{
	Vector4 Color[MAX_LIGHT_CNT];
	Vector4 Position[MAX_LIGHT_CNT];
	Vector4 Direction[MAX_LIGHT_CNT];
	float Radius[MAX_LIGHT_CNT];
	int Cnt = 0;
	int dummy1;
	int dummy2;
	int dummy3;
};

/**
 * @class EyeData
 * @brief [상수버퍼 데이터] 카메라의 위치와 시선 값을 저장한다.
*/
struct EyeData
{
	Vector4 Position;
	Vector4 Direction;
};