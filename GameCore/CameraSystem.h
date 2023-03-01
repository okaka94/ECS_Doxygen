#pragma once
#include "Define.h"
#include "System.hpp"
#include "World.hpp"
#include "DebugCamera.h"

/**
 * @class CameraSystem
 * @brief ī�޶� �ý���
*/
class CameraSystem : public ECS::System
{
public:
	/**
	 * @brief <Camera>�� ����ִ� ��ƼƼ�� ī�޶� ����ī�޶�� �����Ѵ�.
	 * @param[in] world ����
	 * @param[in] time �ð�
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