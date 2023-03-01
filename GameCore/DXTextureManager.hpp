#pragma once
#include "DXTexture.hpp"

/**
 * @class DXTextureManager
 * @brief [�̱���]�ؽ�ó�� �����ϴ� �Ŵ��� Ŭ�����̴�.
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
	 * @brief ����̽��� ���ؽ�Ʈ�� ����� �Ҵ����ش�.
	 * @param[in] device ����̽�
	 * @param[in] context ����̽� ���ؽ�Ʈ
	*/
	void setDevice(ID3D11Device* _device, ID3D11DeviceContext* _context);

	/**
	 * @brief �̹� �߰��� �ؽ�ó���� Ȯ�� �� �ƴ϶�� ���Ӱ� ���� �� �ؽ�ó ����Ʈ�� �߰��Ѵ�.
	 * @param[in] _filename ���ϸ�
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Load(std::wstring _filename);

	/**
	 * @brief �̹� �߰��� �ؽ�ó���� Ȯ�� �� �ƴ϶�� ���Ӱ� ���� �� �ؽ�ó ����Ʈ�� �߰��Ѵ�.
	 * @param[in] _filename ���ϸ�
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Load(std::string _filename);

	/**
	 * @brief �̹� �߰��� �ؽ�ó���� Ȯ�� �� �ƴ϶�� ���Ӱ� ���� �� �ؽ�ó ����Ʈ�� �߰��Ѵ�.
	 * @param[in] _filename ���ϸ�
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Load(const char* _filename);

	/**
	 * @brief �ؽ�ó ����Ʈ�� �˻��� �ؽ�ó�� �����Ѵ�.
	 * @param[in] _filename ���ϸ�
	 * @return �˻� ���н� nullptr , ������ �ؽ�ó ����
	*/
	DXTexture* getTexture(std::wstring _filename);

	/**
	 * @brief �ؽ�ó ����Ʈ�� �˻��� �ؽ�ó�� �����Ѵ�.
	 * @param[in] _filename ���ϸ�
	 * @return �˻� ���н� nullptr , ������ �ؽ�ó ����
	*/
	DXTexture* getTexture(std::string _filename);

	/**
	 * @brief �ؽ�ó ����Ʈ�� �˻��� �ؽ�ó�� �����Ѵ�.
	 * @param[in] _filename ���ϸ�
	 * @return �˻� ���н� nullptr , ������ �ؽ�ó ����
	*/
	DXTexture* getTexture(const char* _filename);

	/**
	 * @brief ���� �̻��
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
	 * @brief �ؽ�ó ����Ʈ�� ��ϵ� �ؽ�ó�� �޸� �Ҵ� ���� �� ����Ʈ�� Clear() �Ѵ�.
	 * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool release();
};
