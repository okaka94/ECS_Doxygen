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
	* @brief ������Ʈ���� �迭�� �����ϴ� �ε��� �������� ���� ID�� ���Ѵ�.
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
		 * @brief ��ƼƼ�� ������Ʈ�� �߰��Ѵ�.
		 * @param[in] args ������Ʈ
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
		 * @brief [���ø��Լ�] Ư�� ������Ʈ�� ComponentType�� �޾ƿ´�.
		 * @return ��ƼƼ�� �������� �ʴ� ������Ʈ�� ��� nullptr�� �����Ѵ�.
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
		 * @brief [���ø��Լ�] Ư�� ������Ʈ�� ��ƼƼ���� �����Ѵ�.
		 * @return ��ƼƼ�� �������� �ʴ� ������Ʈ�� ��� false�� �����Ѵ�.
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
		 * @brief [���ø��Լ�] Ư�� ������Ʈ�� �����ϴ��� Ȯ���Ѵ�.
		 * @return ��ƼƼ�� �������� �ʴ� ������Ʈ�� ��� false�� �����Ѵ�.
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
		 * @brief [���ø��Լ�] Ư�� ������Ʈ�� �����ϴ��� Ȯ���Ѵ�.
		 * @return ��ƼƼ�� �������� �ʴ� ������Ʈ�� ��� false�� �����Ѵ�.
		*/
		template <typename T, typename U, typename... Types>
		bool has() const
		{
			return has<T>() && has<U, Types...>();
		}

		/**
		 * @brief ��ƼƼ�� ID�� ��ȯ�Ѵ�.
		 * @return ������ ID
		*/
		int GetID() const
		{
			return ID;
		}

		/**
		* @brief ��ƼƼ�� �̸��� ��ȯ�Ѵ�.
		* @return Name ���
		*/
		std::wstring GetName() const
		{
			return Name;
		}

	};

}