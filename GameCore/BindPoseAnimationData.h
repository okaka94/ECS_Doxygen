#pragma once
#include "Define.h"

/**
 * @class BindPoseAnimationData
 * @brief [������� ������] Bone, Bind, Animation ����� �迭�� ������ ����ü�̴�.
*/
struct BindPoseAnimationData
{
	Matrix Bone[255];
	Matrix Bind[255];
	Matrix Animation[255];
};