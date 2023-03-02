#pragma once
#include "ECSCommon.hpp"

/**
* @namespace ECS
* @brief Entity Component System
*/
namespace ECS
{
	/**
	* @class Component
	* @brief 기능적으로 연관된 데이터들의 집합이다.
	*/
	class Component
	{
	private:
		int id;

	public:
		Component() {};
		virtual ~Component() {};

	public:
		virtual bool Save() { return true; };
		virtual bool Load() { return true; };
	};

	/**
	* @class ComponentContainer
	* @brief [C][템플릿] 컴포넌트 컨테이너
	*/
	template<typename T>
	class ComponentContainer : public Component
	{
	public:
		T Data;

	public:
		ComponentContainer() {};
		ComponentContainer(const T& data) : Data(data) {};
		virtual ~ComponentContainer() {};
	};
}