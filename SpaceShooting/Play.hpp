//Play.hpp
//�v���C��ʂ̏���

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"

//############### �}�N����` #################

//############### �N���X��` #################
class Play : public Scene	//Scene�N���X���p��
{
private:

public:

	Play();		//�R���X�g���N�^
	~Play();	//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	void PlayScene() override;	//�v���C��ʂ̏���

};
