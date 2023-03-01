#pragma once
#include "Define.h"
#include "System.hpp"
#include "LightData.h"

/**
 * @class LightSystem
 * @brief ���� �ý���
*/
class LightSystem : public ECS::System
{
private:
	ID3D11DeviceContext* Context;
	DirectionalLightData DirectionalLights;
	SpotLightData		SpotLights;
	PointLightData		PointLights;
	EyeData				Eye;

	ID3D11Buffer* DirectionalLightBuffer;
	ID3D11Buffer* PointLightBuffer;
	ID3D11Buffer* SpotLightBuffer;
	ID3D11Buffer* EyeBuffer;

public:

	/**
	 * @brief <������� ������Ʈ>�� ���� �� ��ƼƼ���� ���۽�Ű�� ����ý����� Eye ������ ������Ʈ�Ѵ�.
	 * @detail [�� ���� �߰�]
	 * @param[in] world ����
	 * @param[in] time �ð�
	*/
	virtual void Tick(ECS::World* world, float time) override;

	/**
	 * @brief Context ����� ����̽� ���ؽ�Ʈ�� �Ҵ����ش�.
	*/
	void SetContext(ID3D11DeviceContext* context);

	/**
	 * @brief ���� �ý����� ���۵��� �ʱ�ȭ�Ѵ�. (��� ���� ����)
	*/
	void Initialize();
};