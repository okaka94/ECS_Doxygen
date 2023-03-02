#pragma once
#include "Define.h"

/**
 * @class Camera
 * @brief [C] 카메라와 프러스텀 데이터로 구성되어있다.
*/
class Camera
{
protected:
	ID3D11DeviceContext* Context;

public:
	DirectX::BoundingFrustum Frustum;

public:
	Vector3 Pos;
	Vector3 Look;
	Vector3 Right;
	Vector3 Up;

public:
	Matrix View;
	Matrix Projection;

public:
	float FarDistance;
	float NearDistance;
	float AspectRatio;
	float FovX;
	float FovY;

public:
	CameraMatrix CameraMatrixData;
	ID3D11Buffer* CameraMatrixBuffer = nullptr;

public:
	Camera();
	virtual ~Camera();

public:
	/**
	 * @brief 뷰 행렬을 생성한다.
	 * @param[in] eye 카메라의 위치
	 * @param[in] target 목표 위치
	 * @param[in] up 업 벡터
	*/
	void CreateViewMatrix(const Vector3& eye, const Vector3& target, const Vector3& up);

	/**
	 * @brief 투영 행렬과 프러스텀을 생성한다.
	 * @param[in] nearDist 근단면
	 * @param[in] farDist 원단면
	 * @param[in] fov 시야각
	 * @param[in] aspectRatio 종횡비
	*/
	void CreateProjectionMatrix(float nearDist, float farDist, float fov, float aspectRatio);

	/**
	 * @brief CameraMatrixData를 업데이트한다.
	*/
	void Update();

public:

	/**
	 * @brief 컨텍스트를 할당한다.
	 * @param[in] context 디바이스 컨텍스트
	*/
	void SetContext(ID3D11DeviceContext* context);
};