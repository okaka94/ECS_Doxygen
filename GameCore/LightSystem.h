#pragma once
#include "Define.h"
#include "System.hpp"
#include "LightData.h"

/**
 * @class LightSystem
 * @brief 조명 시스템
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
	 * @brief <조명관련 컴포넌트>를 가진 각 엔티티들을 동작시키고 조명시스템의 Eye 정보를 업데이트한다.
	 * @detail [상세 설명 추가]
	 * @param[in] world 월드
	 * @param[in] time 시간
	*/
	virtual void Tick(ECS::World* world, float time) override;

	/**
	 * @brief Context 멤버에 디바이스 컨텍스트를 할당해준다.
	*/
	void SetContext(ID3D11DeviceContext* context);

	/**
	 * @brief 조명 시스템의 버퍼들을 초기화한다. (상수 버퍼 생성)
	*/
	void Initialize();
};