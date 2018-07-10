//=============================================================================
//
// texture.h
// Author : SHOTA FUKUOKA
//
//=============================================================================
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//*********************************************************
//�C���N���[�h
//*********************************************************
#include "app_renderer.h"
#include <string>

//*********************************************************
//�O���錾
//*********************************************************
class TextureManager;

//*********************************************************
//�N���X
//*********************************************************
class Texture
{
public:

	//�R���X�g���N�^
	Texture(const char* name, TextureManager* m_pTextureManager);

	//�f�X�g���N�^
	~Texture();

	//�e�N�X�`���ǂݍ���
	void LoadTexture(const char* name);

	//�e�N�X�`���쐬
	void CreateTextureResource(void);

	//�e�N�X�`�����O�擾
	const char *GetName();

	//�e�N�X�`���s�N�Z���擾
	unsigned char *GetPixels();

	//�e�N�X�`���擾
	ID3D11ShaderResourceView *GetTexture(void);

	//�I��
	void Release(void);

private:

	ID3D11ShaderResourceView* m_pTexture;

	std::string	m_name;

	unsigned char* m_Pixels;

	int m_Width;

	int m_Height;
};

#endif