//End.hpp
//�G���h��ʂ̏���

#pragma once

//############# �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"
#include "Enemy.hpp"

//############# �}�N����` ##############

//############# �N���X��` ##############
class End : public Scene	//Scene���p��
{
private:

public:

	End();			//�R���X�g���N�^
	~End();			//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	void PlayScene() override;	//�G���h��ʂ̏���

};
