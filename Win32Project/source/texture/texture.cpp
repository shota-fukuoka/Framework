//=============================================================================
//
// texture.cpp
// Author : SHOTA FUKUOKA
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "texture.h"
#include "texture_manager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

///////////////////////////////////////////////////////////////////////////////
// �R���X�g���N�^
///////////////////////////////////////////////////////////////////////////////
Texture::Texture(const char* name, TextureManager* m_pTextureManager)
	: m_Pixels(NULL)
{
	m_name = name;
	Texture* pTexture = m_pTextureManager->GetTexture(this);
	if (pTexture == NULL)
	{
		LoadTexture(m_name.data());
		CreateTextureResource();
		m_pTextureManager->AddTexture(this);
	}
	else
	{
		m_Width = pTexture->m_Width;
		m_Height = pTexture->m_Height;
		m_Pixels = pTexture->m_Pixels;
		m_pTexture = pTexture->m_pTexture;
	}
}

///////////////////////////////////////////////////////////////////////////////
// �f�X�g���N�^
///////////////////////////////////////////////////////////////////////////////
Texture::~Texture()
{
	Release();
}


///////////////////////////////////////////////////////////////////////////////
// �e�N�X�`�����擾
///////////////////////////////////////////////////////////////////////////////
const char *Texture::GetName(void)
{
	return m_name.data();
}

///////////////////////////////////////////////////////////////////////////////
// �e�N�X�`���s�N�Z���擾
///////////////////////////////////////////////////////////////////////////////
unsigned char *Texture::GetPixels(void)
{
	return m_Pixels;
}

///////////////////////////////////////////////////////////////////////////////
// �e�N�X�`���擾
///////////////////////////////////////////////////////////////////////////////
ID3D11ShaderResourceView *Texture::GetTexture(void)
{
	return m_pTexture;
}

///////////////////////////////////////////////////////////////////////////////
// �e�N�X�`���쐬
///////////////////////////////////////////////////////////////////////////////
void Texture::CreateTextureResource(void)
{

	AppRenderer* pAppRenderer = AppRenderer::GetInstance();
	ID3D11Device* pDevice = pAppRenderer->GetDevice();

	ID3D11DeviceContext* pDeviceContext = pAppRenderer->GetDeviceContex();

	ID3D11Texture2D* pTex2D = NULL;

	D3D11_TEXTURE2D_DESC tex2D;
	memset(&tex2D, 0, sizeof(tex2D));
	tex2D.Width = m_Width;
	tex2D.Height = m_Height;
	tex2D.MipLevels = 1;
	tex2D.ArraySize = 1;
	tex2D.Format = DXGI_FORMAT_R8G8B8A8_TYPELESS;
	tex2D.SampleDesc.Count = 1;
	tex2D.SampleDesc.Quality = 0;
	tex2D.Usage = D3D11_USAGE_IMMUTABLE;
	tex2D.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	tex2D.CPUAccessFlags = 0;
	tex2D.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData;
	initData.pSysMem = m_Pixels;
	initData.SysMemPitch = m_Width * 4;
	initData.SysMemSlicePitch = 0;

	auto hr = pDevice->CreateTexture2D(&tex2D, &initData, &pTex2D);
	if (FAILED(hr)) {
		return;
	}

	D3D11_SHADER_RESOURCE_VIEW_DESC SRVDesc = {};
	SRVDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	SRVDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	SRVDesc.Texture2D.MipLevels = -1;

	hr = pDevice->CreateShaderResourceView(pTex2D, &SRVDesc, &m_pTexture);
	if (FAILED(hr))
	{
		return;
	}

	pDeviceContext->GenerateMips(m_pTexture);
}

///////////////////////////////////////////////////////////////////////////////
// �e�N�X�`���ǂݍ���
///////////////////////////////////////////////////////////////////////////////
void Texture::LoadTexture(const char* name)
{
	m_Pixels = stbi_load(name, &m_Width, &m_Height, 0, STBI_rgb_alpha);
}

///////////////////////////////////////////////////////////////////////////////
// �I��
///////////////////////////////////////////////////////////////////////////////
void Texture::Release(void)
{
	if (m_Pixels != NULL)
	{
		stbi_image_free(m_Pixels);
		m_Pixels = NULL;
	}

	ES_SAFE_RELEASE(m_pTexture);
}