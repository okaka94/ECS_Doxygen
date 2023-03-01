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
	* @brief Entity를 생성하고 관리하는 클래스이다.
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
		 * @brief 월드에 등록된 시스템들을 지정한 시간만큼 실행시킨다.
		 * @param[in] time 시간
		*/
		void			Tick(float time);

		/**
		 * @brief 메인 카메라를 설정한다.
		 * @param[in] camera 카메라
		*/
		void			SetMainCamera(Camera* camera);

		/**
		 * @brief 디버깅 카메라를 설정한다.
		 * @param[in] camera 카메라
		*/
		void			SetDebugCamera(DebugCamera* camera);

		/**
		 * @brief 메인 카메라를 리턴한다.
		 * @return MainCamera의 포인터를 리턴한다.
		*/
		Camera*			GetMainCamera();

		/**
		 * @brief 디버깅 카메라를 리턴한다.
		 * @return DebuggingCamera의 포인터를 리턴한다.
		*/
		DebugCamera*	GetDebugCamera();

		//---------------------------------------------
		// Entity
		//---------------------------------------------

		/**
		 * @brief 엔티티를 생성하고 월드의 엔티티 리스트에 추가한다.
		 * @param[in] entity 엔티티
		*/
		void AddEntity(Entity* entity);
		/**
		 * @brief 월드에 등록된 엔티티의 리스트를 반환한다.
		 * @return Entities
		*/
		std::vector<std::shared_ptr<ECS::Entity>>& GetAllEntities();

		/**
		 * @brief 특정 컴포넌트를 가진 엔티티의 리스트를 반환한다.
		 * @return 새롭게 생성된 엔티티 리스트
		*/
		template <typename T>
		std::vector<ECS::Entity*> GetEntities();

		/**
		 * @brief 특정 컴포넌트를 가진 엔티티의 리스트를 반환한다.
		 * @return 새롭게 생성된 엔티티 리스트
		*/
		template <typename T, typename U, typename... Types>
		std::vector<ECS::Entity*> GetEntities();

		/**
		 * @brief 특정 컴포넌트를 가진 엔티티의 개수를 반환한다.
		 * @return 엔티티의 개수
		*/
		template <typename T>
		const int GetCount();

		/**
		 * @brief 특정 컴포넌트를 가진 엔티티의 개수를 반환한다.
		 * @return 엔티티의 개수
		*/
		template <typename T, typename U, typename... Types>
		const int GetCount();

		//---------------------------------------------
		// System
		//---------------------------------------------

		/**
		 * @brief 시스템을 생성하고 월드의 시스템 리스트에 추가한다.
		 * @param[in] system 시스템
		*/
		System* AddSystem(System* system);

		/**
		 * @brief 비활성화 된 시스템을 활성화하고 시스템 리스트에 추가한다.
		 * @detail 비활성 시스템 리스트에서 검색된 시스템을 지우고 해당 시스템을 월드의 시스템 리스트에 추가한다.
		 * @param[in] system 시스템
		*/
		void EnableSystem(System* system);

		/**
		 * @brief 활성화 된 시스템을 비활성화하고 비활성 시스템 리스트에 추가한다.
		 * @detail 활성 시스템 리스트에서 검색된 시스템을 지우고 해당 시스템을 월드의 비활성 시스템 리스트에 추가한다.
		 * @param[in] system 시스템
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