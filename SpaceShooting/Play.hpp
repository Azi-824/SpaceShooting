//Play.hpp
//�v���C��ʂ̏���

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"
#include "Player.hpp"

//############### �}�N����` #################

//############### �N���X��` #################
class Play : public Scene	//Scene�N���X���p��
{
private:

	vector<Image*> chara_img;	//�L�����̉摜
	vector<Charactor*> chara;	//�L����

public:

	Play();		//�R���X�g���N�^
	~Play();	//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	void PlayScene() override;	//�v���C��ʂ̏���

};
