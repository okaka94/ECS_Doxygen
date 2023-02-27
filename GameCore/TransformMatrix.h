#pragma once
#include "Define.h"

/**
 * @class TransformMatrix
 * @brief [������� ������] ������Ʈ�� ��ġ ��ǥ�� ������� ����ü�̴�.
 * @detail ���� ������ ��Ʈ���� ����ü�� World , View , Projection ��ĵ��� �ϳ��� �����־�
 * �������� ���Ǵ� ī�޶��� View, Projection�� �ߺ� �����Ǵ� ��ȿ���� �ؼ��ϱ� ���� 
 * ������ World ��� �κ��� ���� �и��� ���̴�.
*/
struct TransformMatrix
{
	Matrix Mat;
};