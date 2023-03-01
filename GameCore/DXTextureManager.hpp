#pragma once
#include "DXTexture.hpp"

/**
 * @class DXTextureManager
 * @brief [싱글톤]텍스처를 관리하는 매니저 클래스이다.
*/
class DXTextureManager : public Singleton<DXTextureManager>
{
private:
	friend class Singleton<DXTextureManager>;

	ID3D11Device* m_pd3dDevice = nullptr;
	ID3D11DeviceContext* m_pImmediateContext = nullptr;

	std::map<std::wstring, DXTexture*> m_TextureList;

private:
	DXTextureManager() {};
	~DXTextureManager() { release(); };

public:
	
	/**
	 * @brief 디바이스와 컨텍스트를 멤버에 할당해준다.
	 * @param[in] device 디바이스
	 * @param[in] context 디바이스 컨텍스트
	*/
	void setDevice(ID3D11Device* _device, ID3D11DeviceContext* _context);

	/**
	 * @brief 이미 추가된 텍스처인지 확인 후 아니라면 새롭게 생성 후 텍스처 리스트에 추가한다.
	 * @param[in] _filename 파일명
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Load(std::wstring _filename);

	/**
	 * @brief 이미 추가된 텍스처인지 확인 후 아니라면 새롭게 생성 후 텍스처 리스트에 추가한다.
	 * @param[in] _filename 파일명
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Load(std::string _filename);

	/**
	 * @brief 이미 추가된 텍스처인지 확인 후 아니라면 새롭게 생성 후 텍스처 리스트에 추가한다.
	 * @param[in] _filename 파일명
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool Load(const char* _filename);

	/**
	 * @brief 텍스처 리스트를 검색해 텍스처를 리턴한다.
	 * @param[in] _filename 파일명
	 * @return 검색 실패시 nullptr , 성공시 텍스처 리턴
	*/
	DXTexture* getTexture(std::wstring _filename);

	/**
	 * @brief 텍스처 리스트를 검색해 텍스처를 리턴한다.
	 * @param[in] _filename 파일명
	 * @return 검색 실패시 nullptr , 성공시 텍스처 리턴
	*/
	DXTexture* getTexture(std::string _filename);

	/**
	 * @brief 텍스처 리스트를 검색해 텍스처를 리턴한다.
	 * @param[in] _filename 파일명
	 * @return 검색 실패시 nullptr , 성공시 텍스처 리턴
	*/
	DXTexture* getTexture(const char* _filename);

	/**
	 * @brief 현재 미사용
	*/
	ID3D11Texture2D* CreateAlphaTexture(int width, int height);
	
public:
	/**
	 * @brief return true;
	*/
	bool initialize();

	/**
	 * @brief return true;
	*/
	bool frame();

	/**
	 * @brief return true;
	*/
	bool render();

	/**
	 * @brief 텍스처 리스트에 등록된 텍스처의 메모리 할당 해제 후 리스트를 Clear() 한다.
	 * @return 오류가 없었다면 true를 리턴한다.
	*/
	bool release();
};
