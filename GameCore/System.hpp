#pragma once
#include "ECSCommon.hpp"

/**
* @namespace ECS
* @brief Entity Component System
*/
namespace ECS
{
	/**
	* @class System
	* @brief ������Ʈ���� ���۽�Ű�� �����̴�.
	*/
	class System
	{
	public:
		/**
		 * @brief [���������Լ�]Ư�� ������ �ý����� ������ �ð���ŭ �����Ų��.
		 * @param[in] world ����
		 * @param[in] time �ð�
		*/
		virtual void Tick(World* world, float time) = 0;
	};
}