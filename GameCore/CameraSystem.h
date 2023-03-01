#pragma once
#include "Define.h"
#include "System.hpp"
#include "World.hpp"
#include "DebugCamera.h"

/**
 * @class CameraSystem
 * @brief 카메라 시스템
*/
class CameraSystem : public ECS::System
{
public:
	/**
	 * @brief <Camera>를 들고있는 엔티티의 카메라를 메인카메라로 설정한다.
	 * @param[in] world 월드
	 * @param[in] time 시간
	*/
	virtual void Tick(ECS::World* world, float time) override
	{
		for (auto& entity : world->GetEntities<Camera>())
		{
			auto comp = entity.get()->GetComponent<Camera>();
			world->SetMainCamera(comp);
			break;
		}


	}
};