//Load.hpp
//�ǂݍ��݉�ʂ̃N���X�iScene�N���X����h���j

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� #################
#include "Scene.hpp"
#include "Animation.hpp"

//################### �}�N����` ###################
#define DEFF_FONT_SIZE		24		//�ʏ�̃t�H���g�T�C�Y
#define PLAY_FONT_SIZE		48		//�Q�[���v���C���̃t�H���g�T�C�Y

#define LOAD_TEXT			"NowLoading�c"		//���[�h��ʂ̃e�L�X�g
#define DISCRIPTION_TEXT	"�E�N���b�N�Œe�𔭎˂ł����I\n�G�@�����@�ɓ����邩�A��ʒ[�܂ŗ��Ă��܂���\n�Q�[���I�[�o�[���I\n�G�@���R�������Ƃ����I" //�����e�L�X�g
#define PUSH_TEXT			"���N���b�N��START!"		//�N���b�N�̃e�L�X�g
//���W�֌W
#define DISCRIPTION_X	50	//�����p�̃e�L�X�g�`��X�ʒu
#define DISCRIPTION_Y	50	//�����p�̃e�L�X�g�`��Y�ʒu

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
