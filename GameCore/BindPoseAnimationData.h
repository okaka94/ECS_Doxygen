#pragma once
#include "Define.h"

/**
 * @class BindPoseAnimationData
 * @brief [상수버퍼 데이터] Bone, Bind, Animation 행렬의 배열로 구성된 구조체이다.
*/
struct BindPoseAnimationData
{
	Matrix Bone[255];
	Matrix Bind[255];
	Matrix Animation[255];
};