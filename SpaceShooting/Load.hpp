//Load.hpp
//�ǂݍ��݉�ʂ̃N���X�iScene�N���X����h���j

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� #################
#include "Scene.hpp"

//################### �}�N����` ###################

//################### �N���X��` ###################
class Load : public Scene	//Scene�N���X���p��
{
private:

public:

	Load();		//�R���X�g���N�^ 
	~Load();	//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	void PlayScene() override;	//���[�h��ʂ̏���

};
