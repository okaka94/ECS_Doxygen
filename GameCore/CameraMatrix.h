#pragma once
#include "Define.h"

/**
 * @class CameraMatrix
 * @brief [상수버퍼 데이터] 뷰 행렬과 투영 행렬로 구성된 구조체이다.
*/
struct CameraMatrix
{
	Matrix View;
	Matrix Projection;
};