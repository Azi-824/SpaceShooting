//Title.hpp
//�^�C�g����ʂ̏���

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ################
#include "Scene.hpp"
#include "Button.hpp"

//################### �}�N����` #####################
#define TITLE_TEXT	"NowTitle"			//�^�C�g����ʂ̃e�L�X�g

//################### �N���X��` #####################
class Title : public Scene	//Scene�N���X���p��
{
private:

	vector<Image*> bt_img;	//�{�^���̉摜
	vector<Button*> button;	//�{�^��

	void ButtonFunc();	//�{�^�����̏���

public:

	Title();		//�R���X�g���N�^ 
	~Title();		//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	void PlayScene() override;	//�^�C�g����ʂ̏���

};
