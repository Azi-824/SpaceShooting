//End.hpp
//�G���h��ʂ̏���

#pragma once

//############# �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"

//############# �}�N����` ##############

//############# �N���X��` ##############
class End : public Scene	//Scene���p��
{
private:

public:

	End();			//�R���X�g���N�^
	~End();			//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	bool DataLoad() override;	//�f�[�^�Ǎ�
	void PlayScene() override;	//�G���h��ʂ̏���

};
