//Title.hpp
//�^�C�g����ʂ̏���

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ################
#include "Scene.hpp"

//################### �}�N����` #####################

//################### �N���X��` #####################
class Title : public Scene	//Scene�N���X���p��
{
private:

public:

	Title();		//�R���X�g���N�^ 
	~Title();		//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	bool DataLoad() override;	//�f�[�^�Ǎ�
	void PlayScene() override;	//�^�C�g����ʂ̏���

};
