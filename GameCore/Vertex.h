#pragma once
#include "DXTK/SimpleMath.h"

using namespace DirectX::SimpleMath;

/**
 * @class Vertex
 * @brief [인풋 데이터]정점의 PNCT 정보를 저장한다.
 * @details 생성자를 통해 구조체 내의 PNCT 멤버 값을 초기화한다. DirectX::SimpleMath 라이브러리의 자료형을 사용하며
 * member initializer 방식으로 초기화한다.
*/
struct Vertex
{
	Vector3 Pos;
	Vector3 Normal;
	Vector4 Color;
	Vector2 Texture;

	Vertex() : Pos(Vector3(0.0, 0.0, 0.0)), Normal(Vector3(0.0, 0.0, 0.0)), Color(Vector4(0.0, 0.0, 0.0, 0.0)), Texture(Vector2(0.0, 0.0)) {};
	
	Vertex(const Vector3& pos, const Vector4& color, const Vector2& texture)
		: Pos(pos), Normal(Vector3(0.0, 0.0, 0.0)), Color(color), Texture(texture) {};

	Vertex(const Vector3& pos, const Vector3& normal, const Vector4& color, const Vector2& texture)
		: Pos(pos), Normal(normal), Color(color), Texture(texture) {};
};