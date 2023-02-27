/**
* @file GameCore.h
* [게임 코어 클래스]
*/


#pragma once
#include "DXDevice.hpp"
#include "Timer.hpp"
#include "Input.hpp"
#include "DXSamplerState.hpp"
#include "DXTextureManager.hpp"
#include "FMODSoundManager.hpp"
//#include "Object.hpp"
//#include "SpaceDivision.hpp"
//#include "QuadTree.hpp"
//#include "Octree.hpp"
#include "DXRenderTarget.hpp"


/**
	* @class GameCore
	* @brief 크게 Initialize -> Frame -> Render -> Release의 4단계로 구성된다.
	* @detail 가상함수로 코어 클래스를 상속 받아 활용할 수 있도록한다. === 
	*/
class GameCore
{
protected:
	HWND _hWnd;
	DXDevice Device;
	//DXRenderTarget RenderTarget;

public:
	GameCore() {};

public:
	virtual bool Initialize() { return true; };
	virtual bool Frame() { return true; };
	virtual bool Render() { return true; };
	virtual bool Release() { return true; };

public:
	/**
	* @brief 디바이스 -> 셰이더 매니저 -> 인풋 -> 타이머 -> 텍스처 매니저 -> 샘플러 스테이트
	* 설정 후 Initialize()를 호출한다.
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool CoreInitialize();

	/**
	* @brief 인풋 , 타이머 , 사운드 매니저의 프레임 함수 실행 후 Frame()을 호출한다.
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool CoreFrame();

	/**
	* @brief PreRender() -> Render() -> PoseRender()를 순차적으로 호출한다.
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool CoreRender();

	/**
	* @brief Initialize()의 역순으로 Release()를 호출한다.
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool CoreRelease();

	/**
	* @brief 렌터 타겟과 DX State 설정이 이뤄진다.
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool PreRender();

	/**
	* @brief 렌더링 결과를 화면에 투영한다. (Present 함수 호출)
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool PostRender();

public:
	/**
	* @brief 윈도우 핸들 멤버가 NULL이 아니라면 디바이스의 Resize()를 호출한다.
	* @param[in] x 뷰포트의 TopLeftX
	* @param[in] y 뷰포트의 TopLeftY
	* @param[in] width 뷰포트의 넓이
	* @param[in] height 뷰포트의 높이
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool ResizeDevice(int x, int y, int width, int height);

public:
	/**
	* @brief 게임을 실행하는 루프 구조의 함수다.
	* @detail CoreInitialize() 호출 후 bGameRun 변수가 true인 동안 CoreFrame()과 CoreRender()를
	* while 문으로 반복해서 호출한다. 
	* while문을 나오면 CoreRelease()를 호출 후 종료된다.
	* @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Run();

public:
	/**
	* @brief 게임코어 클래스의 윈도우 핸들 멤버를 지정해준다.
	* @param[in] hWnd 윈도우 핸들
	*/
	void SetWindowHandle(HWND hWnd);
};