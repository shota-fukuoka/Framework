//=============================================================================
//
// texture_manager.h
// Author : SHOTA FUKUOKA
//
//=============================================================================
#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

//*****************************************************************************
// �w�b�_�t�@�C��
//*****************************************************************************
#include "texture.h"
#include <list>

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class TextureManager
{
	std::list<Texture*>  m_list;
public:

	//�e�N�X�`���ǉ�
	void AddTexture(Texture* tex);

	//�e�N�X�`���폜
	void DeleteTexture(Texture* tex);

	//�e�N�X�`�����
	void ReleaseAll(void);

	//�e�N�X�`���擾
	Texture *GetTexture(Texture* tex);
};

#endif
