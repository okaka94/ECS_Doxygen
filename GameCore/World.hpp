#pragma once
#include "ECSCommon.hpp"
#include "System.hpp"
#include "Entity.hpp"
#include "DebugCamera.h"

/**
* @namespace ECS
* @brief Entity Component System
*/
namespace ECS
{
	/**
	* @class World
	* @brief Entity�� �����ϰ� �����ϴ� Ŭ�����̴�.
	*/
	class World
	{
	public:
		friend class System;
		friend class Entity;

	private:
		std::vector<std::shared_ptr<ECS::Entity>> Entities;
		std::vector<std::shared_ptr<ECS::System>> Systems;
		std::vector<std::shared_ptr<ECS::System>> DisableSystems;

	private:
		std::shared_ptr<DebugCamera>	DebuggingCamera;
		std::shared_ptr<Camera>			MainCamera;

	public:
		//---------------------------------------------
		// Common
		//---------------------------------------------

		/**
		 * @brief ���忡 ��ϵ� �ý��۵��� ������ �ð���ŭ �����Ų��.
		 * @param[in] time �ð�
		*/
		void			Tick(float time);

		/**
		 * @brief ���� ī�޶� �����Ѵ�.
		 * @param[in] camera ī�޶�
		*/
		void			SetMainCamera(Camera* camera);

		/**
		 * @brief ����� ī�޶� �����Ѵ�.
		 * @param[in] camera ī�޶�
		*/
		void			SetDebugCamera(DebugCamera* camera);

		/**
		 * @brief ���� ī�޶� �����Ѵ�.
		 * @return MainCamera�� �����͸� �����Ѵ�.
		*/
		Camera*			GetMainCamera();

		/**
		 * @brief ����� ī�޶� �����Ѵ�.
		 * @return DebuggingCamera�� �����͸� �����Ѵ�.
		*/
		DebugCamera*	GetDebugCamera();

		//---------------------------------------------
		// Entity
		//---------------------------------------------

		/**
		 * @brief ��ƼƼ�� �����ϰ� ������ ��ƼƼ ����Ʈ�� �߰��Ѵ�.
		 * @param[in] entity ��ƼƼ
		*/
		void AddEntity(Entity* entity);
		/**
		 * @brief ���忡 ��ϵ� ��ƼƼ�� ����Ʈ�� ��ȯ�Ѵ�.
		 * @return Entities
		*/
		std::vector<std::shared_ptr<ECS::Entity>>& GetAllEntities();

		/**
		 * @brief Ư�� ������Ʈ�� ���� ��ƼƼ�� ����Ʈ�� ��ȯ�Ѵ�.
		 * @return ���Ӱ� ������ ��ƼƼ ����Ʈ
		*/
		template <typename T>
		std::vector<ECS::Entity*> GetEntities();

		/**
		 * @brief Ư�� ������Ʈ�� ���� ��ƼƼ�� ����Ʈ�� ��ȯ�Ѵ�.
		 * @return ���Ӱ� ������ ��ƼƼ ����Ʈ
		*/
		template <typename T, typename U, typename... Types>
		std::vector<ECS::Entity*> GetEntities();

		/**
		 * @brief Ư�� ������Ʈ�� ���� ��ƼƼ�� ������ ��ȯ�Ѵ�.
		 * @return ��ƼƼ�� ����
		*/
		template <typename T>
		const int GetCount();

		/**
		 * @brief Ư�� ������Ʈ�� ���� ��ƼƼ�� ������ ��ȯ�Ѵ�.
		 * @return ��ƼƼ�� ����
		*/
		template <typename T, typename U, typename... Types>
		const int GetCount();

		//---------------------------------------------
		// System
		//---------------------------------------------

		/**
		 * @brief �ý����� �����ϰ� ������ �ý��� ����Ʈ�� �߰��Ѵ�.
		 * @param[in] system �ý���
		*/
		System* AddSystem(System* system);

		/**
		 * @brief ��Ȱ��ȭ �� �ý����� Ȱ��ȭ�ϰ� �ý��� ����Ʈ�� �߰��Ѵ�.
		 * @detail ��Ȱ�� �ý��� ����Ʈ���� �˻��� �ý����� ����� �ش� �ý����� ������ �ý��� ����Ʈ�� �߰��Ѵ�.
		 * @param[in] system �ý���
		*/
		void EnableSystem(System* system);

		/**
		 * @brief Ȱ��ȭ �� �ý����� ��Ȱ��ȭ�ϰ� ��Ȱ�� �ý��� ����Ʈ�� �߰��Ѵ�.
		 * @detail Ȱ�� �ý��� ����Ʈ���� �˻��� �ý����� ����� �ش� �ý����� ������ ��Ȱ�� �ý��� ����Ʈ�� �߰��Ѵ�.
		 * @param[in] system �ý���
		*/
		void DisableSystem(System* system);
	};

	template <typename T>
	std::vector<ECS::Entity*> World::GetEntities()
	{
		std::vector<ECS::Entity*> entities;
		for (auto& ent : Entities)
		{
			if (ent.get()->has<T>())
			{
				entities.push_back(ent.get());
			}
		}

		return entities;
	}

	template <typename T, typename U, typename... Types>
	std::vector<ECS::Entity*> World::GetEntities()
	{
		std::vector<ECS::Entity*> entities;
		for (auto& ent : Entities)
		{
			if (ent.get()->has<T, U, Types...>())
			{
				entities.push_back(ent.get());
			}
		}

		return entities;
	}

	template<typename T>
	inline const int World::GetCount()
	{
		int cnt = 0;
		for (auto& ent : Entities)
		{
			if (ent.get()->has<T>())
			{
				cnt++;
			}
		}
		return cnt;
	}

	template <typename T, typename U, typename... Types>
	inline const int World::GetCount()
	{
		int cnt = 0;
		for (auto& ent : Entities)
		{
			if (ent.get()->has<T, U, Types...>())
			{
				cnt++;
			}
		}
		return cnt;
	}
}