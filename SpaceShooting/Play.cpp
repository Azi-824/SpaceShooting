//Play.cpp
//�v���C��ʂ̏���

//################# �w�b�_�t�@�C���ǂݍ��� #################
#include "Play.hpp"

//################ �N���X��` ################

//�R���X�g���N�^
Play::Play()
{

	if (!back->Load(IMG_DIR_BACK, IMG_NAME_PLAY)) { IsLoad = false; return; }	//�w�i�摜�ǂݍ���
	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_PLAY)) { IsLoad = false; return; }	//BGM�ǂݍ���

	IsLoad = true;	//�ǂݍ��ݐ���

}

//�f�X�g���N�^
Play::~Play()
{

}

//�����ݒ�
void Play::SetInit()
{
	back->SetInit();	//�摜�����ݒ�
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM�����ݒ�
}

//�v���C��ʂ̏���
void Play::PlayScene()
{

	bgm->Play();	//BGM�𗬂�

	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��

	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		bgm->Stop();			//BGM���~�߂�
		NowScene = SCENE_END;	//�G���h��ʂ�
	}

}