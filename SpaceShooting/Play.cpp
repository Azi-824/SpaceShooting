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

	//�L�����֌W
	//�摜
	chara_img.push_back(new Image(CHAR_IMG_DIR, PLAYER_IMG_NAME));	//�v���C���[�̉摜
	chara_img.push_back(new Image(CHAR_IMG_DIR, ENEMY1_IMG_NAME));	//�G1�̉摜

	for (auto c : chara_img)
	{
		if (!c->GetIsLoad()) { IsLoad = false; return; }	//�ǂݍ��ݎ��s
	}
	//�L����
	chara.push_back(new Player(chara_img.at(CHARA_KIND_PLAYER)));	//�v���C���[
	chara.push_back(new Enemy(chara_img.at(CHARA_KIND_ENEMY1)));	//�G1

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

	//�L����
	for (auto c : chara) { c->SetInit(); }
}

//�v���C��ʂ̏���
void Play::PlayScene()
{

	bgm->Play();	//BGM�𗬂�

	back->Draw(GAME_LEFT, GAME_TOP);	//�w�i�`��

	for (auto c : chara) 
	{ 
		c->UpDate();//����s������
		//c->Draw();	//�L�����`��
	}	

	DrawString(TEST_TEXT_X, TEST_TEXT_Y, PLAY_TEXT, COLOR_WHITE);	//�e�X�g�p�̃e�L�X�g��`��

	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		//bgm->Stop();			//BGM���~�߂�
		//NowScene = SCENE_END;	//�G���h��ʂ�
	}

}
