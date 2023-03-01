#pragma once
#include <typeindex>
#include <unordered_map>
#include <memory>
#include <functional>
#include <bitset>
#include <array>

/**
* @namespace ECS
* @brief Entity Component System
*/
namespace ECS
{
	#define ECS_DEFINE_TYPE(name)

	/**
	* @class World
	* @brief Entity�� �����ϰ� �����ϴ� Ŭ�����̴�.
	*/
	class World;

	/**
	* @class Entity
	* @brief ������Ʈ���� �迭�� �����ϴ� �ε��� �������� ���� ID�� ���Ѵ�.
	*/
	class Entity;

	/**
	* @class Component
	* @brief ��������� ������ �����͵��� �����̴�.
	*/
	class Component;

	/**
	* @class System
	* @brief ������Ʈ���� ���۽�Ű�� �����̴�.
	*/
	class System;

	using ComponentID = std::type_index;

	template <typename T>
	ComponentID GetComponentID()
	{
		return ComponentID(typeid(T));
	}

}