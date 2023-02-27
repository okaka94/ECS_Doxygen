#pragma once
#include "Define.h"

/**
* @class DXDevice
* @brief DX 디바이스, 팩토리, 스왑체인, RTV, 뷰포트를 생성&관리한다.
*/
class DXDevice 
{
private:
	//friend class Singleton<DXDevice>;

public:
	// 인터페이스 -> 하드웨어 직접 제어 -> 획득

	
	ID3D11Device*				m_pd3dDevice = nullptr;				///< 리소스의 생성과 관련된 작업에 사용. 디바이스 장치 혹은 디바이스 객체라 부름
	ID3D11DeviceContext*		m_pImmediateContext = nullptr;		///< 생성된 리소스들을 사용하여 랜더링 처리 및 제어, 즉시 랜더링
	IDXGIFactory*				m_pGIFactory = nullptr;				///< Swap Chain의 생성과 관련된 작업에 사용.
	IDXGISwapChain*				m_pSwapChain = nullptr;				///< 전면 버퍼 및 후면 버퍼들을 생성 및 제어. 더블 버퍼링
	ID3D11RenderTargetView*		m_pRTV = nullptr;					///< Render Target View: 생성된 후면 버퍼들 중에서 랜더링(출력) 될 대상 버퍼를 지정. 
	

	// Depth Stencil View
	ID3D11Texture2D*			m_pDSTexture = nullptr;
	ID3D11DepthStencilView*		m_pDepthStencilView = nullptr;

	D3D11_VIEWPORT				m_ViewPort;

private:
	HWND						m_hWnd;

public:
	/**
	 * @brief 디바이스 -> 팩토리 -> 스왑체인 -> RTV -> 뷰포트 순서로 생성한다.
	 * @param[in] hWnd 윈도우 핸들
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Create(HWND hWnd);

	/**
	 * @brief 디바이스 멤버가 NULL이 아니라면 디바이스 설정 초기화 후 새 윈도우 크기로 재생성한다.
	 * @detail 컨텍스트의 OMRenderTargets와 RTV 초기화, DSV 초기화 -> 변경된 윈도우의 크기를 얻은 후
	 * 백 버퍼의 크기를 재조정한다. 변경된 백버퍼의 크기를 얻은 후 RTV, DSV, 뷰포트를 재설정한다.
	 * @param[in] x 뷰포트의 TopLeftX
	 * @param[in] y 뷰포트의 TopLeftY
	 * @param[in] width 뷰포트의 넓이
	 * @param[in] height 뷰포트의 높이
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Resize(int x, int y, int width, int height);

	/**
	 * @brief 디바이스 클래스의 멤버들을 Release() 한다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Release();
	
	ID3D11Device*			GetDevice();
	ID3D11DeviceContext*	GetContext();
	IDXGISwapChain*			GetSwapChain();

protected:
	// 1) 디바이스 생성
	HRESULT CreateDevice();
	// 2) 팩토리 생성
	HRESULT CreateFactory();
	// 3) 스왑체인 생성
	HRESULT CreateSwapChain(int width, int height);
	// 4) 랜더 타겟뷰 생성
	HRESULT CreateRenderTargetView();
	// 5) 뷰 포트 설정
	void CreateViewPort(int x, int y, int width, int height);

	// Depth Stencil View
	HRESULT CreateDepthStencilView();
};

//#define DEVICE DXDevice::getInstance()
//#define CONTEXT DXDevice::getInstance()->GetContext()