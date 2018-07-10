//=============================================================================
//
// rendere.h
// Author : SHOTA FUKUOKA
//
//=============================================================================
#ifndef _RENDERER_H_
#define _RENDERER_H_

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "app_renderer.h"

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class Renderer
{
public:
	//�R���X�g���N�^
	Renderer();

	//�f�X�g���N�^
	virtual ~Renderer();

	//�I��
	void Release(void);

	//�`��
	virtual void Draw(void) = 0;

protected:
	//�萔�o�b�t�@�ݒ�
	void ConfigConstantBuffer(UINT ByteWidth);

	//�T���v���[�X�e�[�g�ݒ�
	void ConfigSamplerState(void);

	//�V���h�E�T���v���[�X�e�[�g�ݒ�
	void ConfigShadowSamplerState(void);

	//�u�����h�X�e�[�g�ݒ�
	void ConfigBlendState(BOOL bBlend);

	ID3D11BlendState*					m_pBlendState;

	ID3D11SamplerState*					m_pSampleLinear;

	ID3D11SamplerState*					m_pShadowSampleLinear;

	ID3D11ShaderResourceView*			m_pTexture;

	ID3D11Buffer*						m_pVertexBuffer;

	ID3D11Buffer*						m_pConstantBuffer;

	ID3D11Buffer*						m_pIndexBuffer;
};

#endif