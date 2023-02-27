#pragma once
#include "Define.h"
#define MAX_LIGHT_CNT (int)100

/**
 * @class DirectionalLightData
 * @brief [������� ������] Directional Light �����͸� ��� ����ü�� ����� ������ �����Ѵ�.
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
 * @brief [������� ������] Spot Light �����͸� ��� ����ü�� ����, ����� ��ġ, �ݰ��� �����Ѵ�.
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
 * @brief [������� ������] Point Light �����͸� ��� ����ü�� ����, ����� ��ġ, �ݰ��� �����Ѵ�.
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
 * @brief [������� ������] ī�޶��� ��ġ�� �ü� ���� �����Ѵ�.
*/
struct EyeData
{
	Vector4 Position;
	Vector4 Direction;
};