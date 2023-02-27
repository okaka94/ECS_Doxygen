/**
* @file GameCore.h
* [���� �ھ� Ŭ����]
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
	* @brief ũ�� Initialize -> Frame -> Render -> Release�� 4�ܰ�� �����ȴ�.
	* @detail �����Լ��� �ھ� Ŭ������ ��� �޾� Ȱ���� �� �ֵ����Ѵ�. === 
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
	* @brief ����̽� -> ���̴� �Ŵ��� -> ��ǲ -> Ÿ�̸� -> �ؽ�ó �Ŵ��� -> ���÷� ������Ʈ
	* ���� �� Initialize()�� ȣ���Ѵ�.
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool CoreInitialize();

	/**
	* @brief ��ǲ , Ÿ�̸� , ���� �Ŵ����� ������ �Լ� ���� �� Frame()�� ȣ���Ѵ�.
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool CoreFrame();

	/**
	* @brief PreRender() -> Render() -> PoseRender()�� ���������� ȣ���Ѵ�.
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool CoreRender();

	/**
	* @brief Initialize()�� �������� Release()�� ȣ���Ѵ�.
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool CoreRelease();

	/**
	* @brief ���� Ÿ�ٰ� DX State ������ �̷�����.
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool PreRender();

	/**
	* @brief ������ ����� ȭ�鿡 �����Ѵ�. (Present �Լ� ȣ��)
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool PostRender();

public:
	/**
	* @brief ������ �ڵ� ����� NULL�� �ƴ϶�� ����̽��� Resize()�� ȣ���Ѵ�.
	* @param[in] x ����Ʈ�� TopLeftX
	* @param[in] y ����Ʈ�� TopLeftY
	* @param[in] width ����Ʈ�� ����
	* @param[in] height ����Ʈ�� ����
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool ResizeDevice(int x, int y, int width, int height);

public:
	/**
	* @brief ������ �����ϴ� ���� ������ �Լ���.
	* @detail CoreInitialize() ȣ�� �� bGameRun ������ true�� ���� CoreFrame()�� CoreRender()��
	* while ������ �ݺ��ؼ� ȣ���Ѵ�. 
	* while���� ������ CoreRelease()�� ȣ�� �� ����ȴ�.
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Run();

public:
	/**
	* @brief �����ھ� Ŭ������ ������ �ڵ� ����� �������ش�.
	* @param[in] hWnd ������ �ڵ�
	*/
	void SetWindowHandle(HWND hWnd);
};