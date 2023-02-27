#pragma once
#include "DXTK/SimpleMath.h"

using namespace DirectX::SimpleMath;

/**
 * @class Vertex
 * @brief [��ǲ ������]������ PNCT ������ �����Ѵ�.
 * @details �����ڸ� ���� ����ü ���� PNCT ��� ���� �ʱ�ȭ�Ѵ�. DirectX::SimpleMath ���̺귯���� �ڷ����� ����ϸ�
 * member initializer ������� �ʱ�ȭ�Ѵ�.
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