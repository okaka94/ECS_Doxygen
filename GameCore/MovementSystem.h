#pragma once
#include "System.hpp"
#include "World.hpp"
#include "MovementComponent.h"

/**
 * @class MovementSystem
 * @brief 이동 시스템
*/
class MovementSystem : public ECS::System
{
public:
	/**
	 * @brief <MovementComponent>를 가진 각 엔티티들을 동작시킨다.
	 * @detail 현재 Location에서  Forward 벡터 , Speed , 시간 값으로 새로운 Location 값을 구한다.
	 * Location = Location + (Forward * Speed) * time;
	 * @param[in] world 월드
	 * @param[in] time 시간
	*/
	virtual void Tick(ECS::World* world, float time) override
	{
		for (auto& entity : world->GetAllEntities())
		{
			auto it = entity.get()->GetComponent<MovementComponent>();
			if (!it)
			{
				continue;
			}

			it->Location = it->Location + (it->Forword * it->Speed) * time;
		}
	}
};