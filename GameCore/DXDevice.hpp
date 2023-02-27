#pragma once
#include "Define.h"

/**
* @class DXDevice
* @brief DX ����̽�, ���丮, ����ü��, RTV, ����Ʈ�� ����&�����Ѵ�.
*/
class DXDevice 
{
private:
	//friend class Singleton<DXDevice>;

public:
	// �������̽� -> �ϵ���� ���� ���� -> ȹ��

	
	ID3D11Device*				m_pd3dDevice = nullptr;				///< ���ҽ��� ������ ���õ� �۾��� ���. ����̽� ��ġ Ȥ�� ����̽� ��ü�� �θ�
	ID3D11DeviceContext*		m_pImmediateContext = nullptr;		///< ������ ���ҽ����� ����Ͽ� ������ ó�� �� ����, ��� ������
	IDXGIFactory*				m_pGIFactory = nullptr;				///< Swap Chain�� ������ ���õ� �۾��� ���.
	IDXGISwapChain*				m_pSwapChain = nullptr;				///< ���� ���� �� �ĸ� ���۵��� ���� �� ����. ���� ���۸�
	ID3D11RenderTargetView*		m_pRTV = nullptr;					///< Render Target View: ������ �ĸ� ���۵� �߿��� ������(���) �� ��� ���۸� ����. 
	

	// Depth Stencil View
	ID3D11Texture2D*			m_pDSTexture = nullptr;
	ID3D11DepthStencilView*		m_pDepthStencilView = nullptr;

	D3D11_VIEWPORT				m_ViewPort;

private:
	HWND						m_hWnd;

public:
	/**
	 * @brief ����̽� -> ���丮 -> ����ü�� -> RTV -> ����Ʈ ������ �����Ѵ�.
	 * @param[in] hWnd ������ �ڵ�
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Create(HWND hWnd);

	/**
	 * @brief ����̽� ����� NULL�� �ƴ϶�� ����̽� ���� �ʱ�ȭ �� �� ������ ũ��� ������Ѵ�.
	 * @detail ���ؽ�Ʈ�� OMRenderTargets�� RTV �ʱ�ȭ, DSV �ʱ�ȭ -> ����� �������� ũ�⸦ ���� ��
	 * �� ������ ũ�⸦ �������Ѵ�. ����� ������� ũ�⸦ ���� �� RTV, DSV, ����Ʈ�� �缳���Ѵ�.
	 * @param[in] x ����Ʈ�� TopLeftX
	 * @param[in] y ����Ʈ�� TopLeftY
	 * @param[in] width ����Ʈ�� ����
	 * @param[in] height ����Ʈ�� ����
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Resize(int x, int y, int width, int height);

	/**
	 * @brief ����̽� Ŭ������ ������� Release() �Ѵ�.
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Release();
	
	ID3D11Device*			GetDevice();
	ID3D11DeviceContext*	GetContext();
	IDXGISwapChain*			GetSwapChain();

protected:
	// 1) ����̽� ����
	HRESULT CreateDevice();
	// 2) ���丮 ����
	HRESULT CreateFactory();
	// 3) ����ü�� ����
	HRESULT CreateSwapChain(int width, int height);
	// 4) ���� Ÿ�ٺ� ����
	HRESULT CreateRenderTargetView();
	// 5) �� ��Ʈ ����
	void CreateViewPort(int x, int y, int width, int height);

	// Depth Stencil View
	HRESULT CreateDepthStencilView();
};

//#define DEVICE DXDevice::getInstance()
//#define CONTEXT DXDevice::getInstance()->GetContext()