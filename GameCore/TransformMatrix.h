#pragma once
#include "Define.h"

/**
 * @class TransformMatrix
 * @brief [상수버퍼 데이터] 오브젝트의 위치 좌표를 담기위한 구조체이다.
 * @detail 수업 예제의 매트릭스 구조체는 World , View , Projection 행렬들이 하나로 뭉쳐있어
 * 공용으로 사용되는 카메라의 View, Projection이 중복 설정되는 비효율을 해소하기 위해 
 * 예제의 World 행렬 부분을 따로 분리한 것이다.
*/
struct TransformMatrix
{
	Matrix Mat;
};