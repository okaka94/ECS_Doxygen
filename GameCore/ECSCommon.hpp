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
	* @brief Entity를 생성하고 관리하는 클래스이다.
	*/
	class World;

	/**
	* @class Entity
	* @brief 컴포넌트들의 배열에 접근하는 인덱스 개념으로 고유 ID를 지닌다.
	*/
	class Entity;

	/**
	* @class Component
	* @brief 기능적으로 연관된 데이터들의 집합이다.
	*/
	class Component;

	/**
	* @class System
	* @brief 컴포넌트들을 동작시키는 로직이다.
	*/
	class System;

	using ComponentID = std::type_index;

	template <typename T>
	ComponentID GetComponentID()
	{
		return ComponentID(typeid(T));
	}

}