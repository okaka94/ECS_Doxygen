#pragma once
#include "System.hpp"
#include "World.hpp"
#include "MovementComponent.h"

/**
 * @class MovementSystem
 * @brief �̵� �ý���
*/
class MovementSystem : public ECS::System
{
public:
	/**
	 * @brief <MovementComponent>�� ���� �� ��ƼƼ���� ���۽�Ų��.
	 * @detail ���� Location����  Forward ���� , Speed , �ð� ������ ���ο� Location ���� ���Ѵ�.
	 * Location = Location + (Forward * Speed) * time;
	 * @param[in] world ����
	 * @param[in] time �ð�
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