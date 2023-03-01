#pragma once
#include "ECSCommon.hpp"
#include "Component.hpp"

static int EntityID = 0;

/**
* @namespace ECS
* @brief Entity Component System
*/
namespace ECS
{
	/**
	* @class Entity
	* @brief 컴포넌트들의 배열에 접근하는 인덱스 개념으로 고유 ID를 지닌다.
	*/
	class Entity
	{
	public:
		friend class World;

	protected:
		std::unordered_map<ComponentID, std::shared_ptr<ECS::Component>> Components;
		int ID;
		std::wstring Name;

	public:
		Entity() { ID = EntityID++; };
		virtual ~Entity() {};

	public:

		/**
		 * @brief 엔티티에 컴포넌트를 추가한다.
		 * @param[in] args 컴포넌트
		 * @return 
		*/
		template<typename ComponentType, typename... ComponentArgs>
		ComponentType* AddComponent(ComponentArgs&&... args)
		{
			ComponentID id = ECS::GetComponentID<ComponentType>();
			auto it = Components.find(id);
			if (it != Components.end())
			{
				ComponentContainer<ComponentType>* container = reinterpret_cast<ComponentContainer<ComponentType>*>(it->second.get());
				container->Data = ComponentType(args...);
				
				return &container->Data;
			}
			else
			{
				ComponentContainer<ComponentType>* container = new ComponentContainer<ComponentType>();
				container->Data = ComponentType(args...);
				std::shared_ptr<ComponentContainer<ComponentType>> newComp(container);
				Components.insert(std::make_pair(id, newComp));

				return &container->Data;
			}
			
		}

		/**
		 * @brief [템플릿함수] 특정 컴포넌트의 ComponentType을 받아온다.
		 * @return 엔티티에 존재하지 않는 컴포넌트일 경우 nullptr을 리턴한다.
		*/
		template<typename ComponentType>
		ComponentType* GetComponent()
		{
			ComponentID id = ECS::GetComponentID<ComponentType>();
			auto it = Components.find(id);
			if (it == Components.end())
			{
				return nullptr;
			}

			ComponentContainer<ComponentType>* container = reinterpret_cast<ComponentContainer<ComponentType>*>(it->second.get());
			return &container->Data;
		}

		/**
		 * @brief [템플릿함수] 특정 컴포넌트를 엔티티에서 제거한다.
		 * @return 엔티티에 존재하지 않는 컴포넌트일 경우 false를 리턴한다.
		*/
		template<typename ComponentType>
		bool RemoveComponent()
		{
			ComponentID id = ECS::GetComponentID<ComponentType>();
			auto it = Components.find(id);
			if (it != Components.end())
			{
				Components.erase(it);
				return true;
			}

			return false;
		}

		/**
		 * @brief [템플릿함수] 특정 컴포넌트가 존재하는지 확인한다.
		 * @return 엔티티에 존재하지 않는 컴포넌트일 경우 false를 리턴한다.
		*/
		template <typename T>
		bool has() const
		{
			ComponentID id = ECS::GetComponentID<T>();
			auto it = Components.find(id);
			if (it != Components.end())
			{
				return true;
			}
			
			return false;
		}

		/**
		 * @brief [템플릿함수] 특정 컴포넌트가 존재하는지 확인한다.
		 * @return 엔티티에 존재하지 않는 컴포넌트일 경우 false를 리턴한다.
		*/
		template <typename T, typename U, typename... Types>
		bool has() const
		{
			return has<T>() && has<U, Types...>();
		}

		/**
		 * @brief 엔티티의 ID를 반환한다.
		 * @return 정수형 ID
		*/
		int GetID() const
		{
			return ID;
		}

		/**
		* @brief 엔티티의 이름를 반환한다.
		* @return Name 멤버
		*/
		std::wstring GetName() const
		{
			return Name;
		}

	};

}