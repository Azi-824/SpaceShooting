//Load.cpp
//���[�h��ʂ̃N���X

//############## �w�b�_�t�@�C���ǂݍ��� #################
#include "Load.hpp"

//############## �N���X��` ################

//�R���X�g���N�^
Load::Load()
{
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);	//�t�H���g�^�C�v�ύX
	SetFontSize(DEFF_FONT_SIZE);	//�t�H���g�T�C�Y�ύX
	IsLoad = Animation::CreateList();	//�A�j���[�V�������X�g�쐬
}

//�f�X�g���N�^
Load::~Load()
{
	Animation::DeleteHandle();	//���X�g�ɓǂݍ��񂾃n���h�����폜
}

//�����ݒ�
void Load::SetInit()
{

}

//�ǂݍ��݉�ʂ̏���
void Load::PlayScene()
{

	if (GetASyncLoadNum() == 0)	//�񓯊��œǂݍ���ł��鏈�����I�������
	{

		SetUseASyncLoadFlag(FALSE);	//�����ǂݍ��݂ɐݒ�

		IsGameStart = true;		//�Q�[���X�^�[�g�ł���
	}

	DrawString(DISCRIPTION_X, DISCRIPTION_Y, DISCRIPTION_TEXT, COLOR_WHITE);	//�����̃e�L�X�g��`��

	if (IsGameStart)	//�Q�[���X�^�[�g�ł���Ȃ�
	{
		if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
		{
			SetFontSize(PLAY_FONT_SIZE);	//�t�H���g�T�C�Y�ύX
			NowScene = SCENE_TITLE;	//�^�C�g����ʂ�
		}

		DrawString(GAME_LEFT, GAME_TOP, PUSH_TEXT, COLOR_WHITE);	//�v�b�V���A�̃e�L�X�g��`��
	}
	else		//�ł��Ȃ��Ȃ�
	{
		DrawString(GAME_LEFT, GAME_TOP, LOAD_TEXT, COLOR_WHITE);	//�ǂݍ��ݒ��̃e�L�X�g��`��
	}


}
