#pragma once
#include "DXTK/SimpleMath.h"


using namespace DirectX::SimpleMath;

/**
 * @class IWData
 * @brief [인풋 데이터]인덱스, 가중치 정보를 저장한다.
 * @details 생성자를 통해 구조체 내의 Index, Weight 멤버 값을 초기화한다. DirectX::SimpleMath 라이브러리의 Vector4 자료형을 사용하며
 * member initializer 방식으로 초기화한다.
*/
struct IWData
{
	Vector4 Index;
	Vector4 Weight;

	IWData() : Index(Vector4()), Weight(Vector4()) {};
	IWData(Vector4 index, Vector4 weight) : Index(index), Weight(weight) {};
};