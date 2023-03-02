#pragma once
#include "Define.h"

/**
 * @class Camera
 * @brief [C] ī�޶�� �������� �����ͷ� �����Ǿ��ִ�.
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
	 * @brief �� ����� �����Ѵ�.
	 * @param[in] eye ī�޶��� ��ġ
	 * @param[in] target ��ǥ ��ġ
	 * @param[in] up �� ����
	*/
	void CreateViewMatrix(const Vector3& eye, const Vector3& target, const Vector3& up);

	/**
	 * @brief ���� ��İ� ���������� �����Ѵ�.
	 * @param[in] nearDist �ٴܸ�
	 * @param[in] farDist ���ܸ�
	 * @param[in] fov �þ߰�
	 * @param[in] aspectRatio ��Ⱦ��
	*/
	void CreateProjectionMatrix(float nearDist, float farDist, float fov, float aspectRatio);

	/**
	 * @brief CameraMatrixData�� ������Ʈ�Ѵ�.
	*/
	void Update();

public:

	/**
	 * @brief ���ؽ�Ʈ�� �Ҵ��Ѵ�.
	 * @param[in] context ����̽� ���ؽ�Ʈ
	*/
	void SetContext(ID3D11DeviceContext* context);
};