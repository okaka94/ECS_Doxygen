#pragma once
#include "Define.h"

/**
	* @class InputLayoutType
	* @brief ����ƽ �޽ÿ� ���̷�Ż �޽÷� ���еǴ� ������ Ŭ�����̴�. 
	*/
enum class InputLayoutType
{
	StaticMesh,
	SkeletalMesh
};

/**
 * @class DXShaderManager
 * @brief [�̱���]���̴��� �����ϴ� �Ŵ��� Ŭ�����̴�.
*/
class DXShaderManager : public Singleton<DXShaderManager>
{
private:
	friend class Singleton<DXShaderManager>;

private:
	ID3D11Device*									m_pd3dDevice = nullptr;
	ID3D11DeviceContext*							m_pImmediateContext = nullptr;

	std::map<InputLayoutType, ID3D11InputLayout*>	InputLayoutMap;

	std::map<std::wstring, ID3DBlob*>				VertexShaderCodeMap;
	std::map<std::wstring, ID3DBlob*>				HullShaderCodeMap;
	std::map<std::wstring, ID3DBlob*>				DomainShaderCodeMap;
	std::map<std::wstring, ID3DBlob*>				GeometryShaderCodeMap;
	std::map<std::wstring, ID3DBlob*>				PixelShaderCodeMap;

	std::map<std::wstring, ID3D11VertexShader*>		VertexShaderMap;
	std::map<std::wstring, ID3D11HullShader*>		HullShaderMap;
	std::map<std::wstring, ID3D11DomainShader*>		DomainShaderMap;
	std::map<std::wstring, ID3D11GeometryShader*>	GeometryShaderMap;
	std::map<std::wstring, ID3D11PixelShader*>		PixelShaderMap;

	std::vector<ID3D11Buffer*>						BufferList;

private:
	DXShaderManager() {};
	virtual ~DXShaderManager() { Release(); };

public:
	/**
		* @brief ������ ������ ���� ���̴� �ڵ尡 ���ٸ� ���Ӱ� ���� �� �ڵ� �ʿ� �����Ѵ�.
		* @param filename ���ϸ�
		* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool LoadVSCode(std::wstring filename);

	/**
	* @brief ������ ������ �� ���̴� �ڵ尡 ���ٸ� ���Ӱ� ���� �� �ڵ� �ʿ� �����Ѵ�.
	* @param filename ���ϸ�
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool LoadHSCode(std::wstring filename);

	/**
	* @brief ������ ������ ������ ���̴� �ڵ尡 ���ٸ� ���Ӱ� ���� �� �ڵ� �ʿ� �����Ѵ�.
	* @param filename ���ϸ�
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool LoadDSCode(std::wstring filename);

	/**
	* @brief ������ ������ ���� ���̴� �ڵ尡 ���ٸ� ���Ӱ� ���� �� �ڵ� �ʿ� �����Ѵ�.
	* @param filename ���ϸ�
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool LoadGSCode(std::wstring filename);

	/**
	* @brief ������ ������ �ȼ� ���̴� �ڵ尡 ���ٸ� ���Ӱ� ���� �� �ڵ� �ʿ� �����Ѵ�.
	* @param filename ���ϸ�
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool LoadPSCode(std::wstring filename);

	/**
	* @brief �ڵ� �ʿ� �ִ� ��� ���̴� �ڵ带 �ҷ��� ���̴��� ���� �� ���̴� �ʿ� �����Ѵ�.
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool CreateVertexShader();

	/**
	* @brief �ڵ� �ʿ� �ִ� ��� ���̴� �ڵ带 �ҷ��� ���̴��� ���� �� ���̴� �ʿ� �����Ѵ�.
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool CreatePixelShader();

	/**
	* @brief �ڵ� �ʿ� �ִ� ��� ���̴� �ڵ带 �ҷ��� ���̴��� ���� �� ���̴� �ʿ� �����Ѵ�.
	* @param decl ????
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool CreateGeometryShader(D3D11_SO_DECLARATION_ENTRY* decl);

	/**
	* @brief ����ƽ �޽� ��ǲ ���̾ƿ� ���� �Լ� ȣ�� �� ���̷�Ż �޽� ��ǲ ���̾ƿ� ���� �Լ��� ȣ���Ѵ�.
	* @return ����ƽ �޽ÿ� ���̷�Ż �޽� ���̾ƿ��� ��� �����Ǹ� true ���� �����Ѵ�.
	*/
	bool CreateInputLayout();

	/**
	* @brief "VS_StaticMesh.hlsl" ������ ���� ���̴� �ڵ尡 �ִٸ� PNCT ������ ��ǲ ���̾ƿ� ���� �� �ʿ� �����Ѵ�.
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool CreateStaticMeshInputLayout();

	/**
	* @brief "VS_SkeletalMesh.hlsl" ������ ���� ���̴� �ڵ尡 �ִٸ� PNCT ������ ��ǲ ���̾ƿ� ���� �� �ʿ� �����Ѵ�.
	* @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool CreateSkeletalMeshInputLayout();

public:

	/**
	* @brief ���� ���۸� �����Ѵ�.
	* @param vertices ������ PNCT ������ ��� ���� �����̳�
	* @return ���� ���� ���н� nullptr�� ����, ������ ���� �����͸� BufferList�� �߰� �� �����Ѵ�.
	*/
	ID3D11Buffer* CreateVertexBuffer(const std::vector<Vertex>& vertices);

	/**
	* @brief indices�� ������� �ʴٸ� �ε��� ���۸� �����Ѵ�.
	* @param indices DWORD ���� ��� ���� �����̳�
	* @return ���� ���� ���н� nullptr�� ����, ������ ���� �����͸� BufferList�� �߰� �� �����Ѵ�.
	*/
	ID3D11Buffer* CreateIndexBuffer(const std::vector<DWORD>& indices);

	/**
	* @brief ��� ���۸� �����Ѵ�.
	* @param constantData [���ø� ����]
	* @return ���� ���� ���н� nullptr�� ����, ������ ���� �����͸� BufferList�� �߰� �� �����Ѵ�.
	*/
	template <typename T>
	ID3D11Buffer* CreateConstantBuffer(const T& constantData);

	/**
	* @brief �ƿ�ǲ ���۸� �����Ѵ�.
	* @param size ���� ������
	* @return ���� ���� ���н� nullptr�� ����, ������ ���� �����͸� BufferList�� �߰� �� �����Ѵ�.
	*/
	ID3D11Buffer* CreateStreamOutputBuffer(UINT size);

	/**
	* @brief ���� �̻��
	* @param size ���� ������
	* @return nullptr
	*/
	ID3D11Buffer* CreateMappedBuffer(UINT size);

public:
	/**
	 * @brief ����̽��� ���ؽ�Ʈ�� ����� �Ҵ����ش�.
	 * @param[in] device ����̽�
	 * @param[in] context ����̽� ���ؽ�Ʈ
	*/
	void SetDevice(ID3D11Device* device, ID3D11DeviceContext* context);

public:
	/**
	 * @brief ��ǲ ���̾ƿ� �ʿ��� ������ Ÿ���� ��ǲ ���̾ƿ��� �޾ƿ´�.
	 * @param[in] type ��ǲ ���̾ƿ� Ÿ��
	 * @return �ʿ� ã�� Ÿ���� ���ٸ� nullptr�� �����ϰ�, �����ϸ� ��ǲ ���̾ƿ� �����͸� �����Ѵ�.
	*/
	ID3D11InputLayout* GetInputLayout(InputLayoutType type);

	/**
	 * @brief ���̴� �ڵ� ���� �˻��� ���̴� �ڵ带 ������� ID3DBlob �����͸� �޾ƿ´�.
	 * @param[in] key ���ϸ�
	 * @return �˻� ����� �����ϸ� �����͸� �����Ѵ�.
	*/
	ID3DBlob* GetVSCode(std::wstring key);

	/**
	 * @brief ���̴� �ڵ� ���� �˻��� ���̴� �ڵ带 ������� ID3DBlob �����͸� �޾ƿ´�.
	 * @param[in] key ���ϸ�
	 * @return �˻� ����� �����ϸ� �����͸� �����Ѵ�.
	*/
	ID3DBlob* GetHSCode(std::wstring key);

	/**
	 * @brief ���̴� �ڵ� ���� �˻��� ���̴� �ڵ带 ������� ID3DBlob �����͸� �޾ƿ´�.
	 * @param[in] key ���ϸ�
	 * @return �˻� ����� �����ϸ� �����͸� �����Ѵ�.
	*/
	ID3DBlob* GetDSCode(std::wstring key);

	/**
	 * @brief ���̴� �ڵ� ���� �˻��� ���̴� �ڵ带 ������� ID3DBlob �����͸� �޾ƿ´�.
	 * @param[in] key ���ϸ�
	 * @return �˻� ����� �����ϸ� �����͸� �����Ѵ�.
	*/
	ID3DBlob* GetGSCode(std::wstring key);

	/**
	 * @brief ���̴� �ڵ� ���� �˻��� ���̴� �ڵ带 ������� ID3DBlob �����͸� �޾ƿ´�.
	 * @param[in] key ���ϸ�
	 * @return �˻� ����� �����ϸ� �����͸� �����Ѵ�.
	*/
	ID3DBlob* GetPSCode(std::wstring key);


	/**
	 * @brief ���̴� ���� �˻��� ���̴� �����͸� �޾ƿ´�.
	 * @param[in] key ���ϸ�
	 * @return �˻� ����� �����ϸ� �����͸� �����Ѵ�.
	*/
	ID3D11VertexShader*		GetVertexShader(std::wstring key);

	/**
	  * @brief ���̴� ���� �˻��� ���̴� �����͸� �޾ƿ´�.
	  * @param[in] key ���ϸ�
	  * @return �˻� ����� �����ϸ� �����͸� �����Ѵ�.
	*/
	ID3D11HullShader*		GetHullShader(std::wstring key);

	/**
	  * @brief ���̴� ���� �˻��� ���̴� �����͸� �޾ƿ´�.
	  * @param[in] key ���ϸ�
	  * @return �˻� ����� �����ϸ� �����͸� �����Ѵ�.
	*/
	ID3D11DomainShader*		GetDomainShader(std::wstring key);

	/**
	  * @brief ���̴� ���� �˻��� ���̴� �����͸� �޾ƿ´�.
	  * @param[in] key ���ϸ�
	  * @return �˻� ����� �����ϸ� �����͸� �����Ѵ�.
	*/
	ID3D11GeometryShader*	GetGeometryShader(std::wstring key);

	/**
	  * @brief ���̴� ���� �˻��� ���̴� �����͸� �޾ƿ´�.
	  * @param[in] key ���ϸ�
	  * @return �˻� ����� �����ϸ� �����͸� �����Ѵ�.
	*/
	ID3D11PixelShader*		GetPixelShader(std::wstring key);
	
public:
	/**
	  * @brief ���̴� �Ŵ��� Ŭ������ �ʱ�ȭ �۾��� �����Ѵ�.
	  * @detail ���� ���̴� ����(VS_StaticMesh , VS_SkeletalMesh)�� �������ϰ�
	  * �ȼ� ���̴� ����(PS_Default , PS_Light)�� ������ �� �� ���� ���̴��� �ȼ� ���̴�, ��ǲ ���̾ƿ��� �����Ѵ�.
	  * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Initialize();

	/**
	  * @brief ���̴� �Ŵ��� Ŭ������ Release �۾��� �����Ѵ�.
	  * @return ������ �����ٸ� true�� �����Ѵ�.
	*/
	bool Release();
};

template<typename T>
inline ID3D11Buffer* DXShaderManager::CreateConstantBuffer(const T& constantData)
{
	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.ByteWidth = sizeof(T) * 1; // ����Ʈ �뷮
	desc.Usage = D3D11_USAGE_DEFAULT; // ������ �Ҵ� ��� ������ ���� �뵵, D3D11_USAGE_DEFAULT == GPU �޸𸮿� �Ҵ�. D3D11_USAGE_DYNAMIC; //
	desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER; // Constant ���۸� ����ϰڴٴ� �÷���
	//desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE; // Test
	//desc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initialData;
	ZeroMemory(&initialData, sizeof(initialData));
	initialData.pSysMem = &constantData; // �迭�� �ƴϸ� �ý��� �޸𸮿� ��� �� �� ����. �׷��� �׳� �迭���� ���� vector ���.

	//ID3D11Buffer* pConstantBuffer;
	//HRESULT result = m_pd3dDevice->CreateBuffer(
	//	&desc, // ���� �Ҵ� 
	//	&initialData, // �ʱ� �Ҵ�� ���۸� ü��� CPU �޸�, NULL�� ������ ������ �� ���� ��.
	//	&pConstantBuffer);

	ID3D11Buffer* pConstantBuffer;
	HRESULT result = m_pd3dDevice->CreateBuffer(
		&desc, // ���� �Ҵ� 
		&initialData, // �ʱ� �Ҵ�� ���۸� ü��� CPU �޸�, NULL�� ������ ������ �� ���� ��.
		&pConstantBuffer);

	if (FAILED(result))
	{
		return nullptr;
	}
	else
	{
		BufferList.push_back(pConstantBuffer);
		return pConstantBuffer;
	}
}
