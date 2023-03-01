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
	* @brief 컴포넌트들을 동작시키는 로직이다.
	*/
	class System
	{
	public:
		/**
		 * @brief [순수가상함수]특정 월드의 시스템을 지정한 시간만큼 실행시킨다.
		 * @param[in] world 월드
		 * @param[in] time 시간
		*/
		virtual void Tick(World* world, float time) = 0;
	};
}