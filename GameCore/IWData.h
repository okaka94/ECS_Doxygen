#pragma once
#include "DXTK/SimpleMath.h"


using namespace DirectX::SimpleMath;

/**
 * @class IWData
 * @brief [��ǲ ������]�ε���, ����ġ ������ �����Ѵ�.
 * @details �����ڸ� ���� ����ü ���� Index, Weight ��� ���� �ʱ�ȭ�Ѵ�. DirectX::SimpleMath ���̺귯���� Vector4 �ڷ����� ����ϸ�
 * member initializer ������� �ʱ�ȭ�Ѵ�.
*/
struct IWData
{
	Vector4 Index;
	Vector4 Weight;

	IWData() : Index(Vector4()), Weight(Vector4()) {};
	IWData(Vector4 index, Vector4 weight) : Index(index), Weight(weight) {};
};