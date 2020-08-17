//End.cpp
//�G���h��ʂ̏���

//############# �w�b�_�t�@�C���ǂݍ��� ###############
#include "End.hpp"

//############# �N���X��` ################

//�R���X�g���N�^
End::End()
{

	if (!back->Load(IMG_DIR_BACK, IMG_NAME_RANKING)) { IsLoad = false; }	//�w�i�摜�ǂݍ���
	if (!bgm->Load(MUSIC_DIR_BGM, BGM_NAME_RANKING)) { IsLoad = false; }	//BGM�ǂݍ���

	IsLoad = true;	//�ǂݍ��ݐ���

}

//�f�X�g���N�^
End::~End()
{

}

//�����ݒ�
void End::SetInit()
{
	back->SetInit();	//�w�i�摜�����ݒ�
	bgm->SetInit(DX_PLAYTYPE_LOOP, 30);		//BGM�����ݒ�
}

//�G���h��ʂ̏���
void End::PlayScene()
{

	bgm->Play();	//BGM�𗬂�

	back->Draw(GAME_LEFT, GAME_TOP);//�w�i�`��

	//�`��ʒu�ݒ�
	int width = GetDrawFormatStringWidth(RESULT_TEXT, Enemy::GetDestroyNum());	//����
	int height = GetFontSize();	//����
	int x = (GAME_WIDTH / 2) - (width / 2);		//X
	int y = (GAME_HEIGHT / 2) - (height / 2);	//Y

	DrawFormatString(x, y, COLOR_RED, RESULT_TEXT, Enemy::GetDestroyNum());		//���ʕ\��

	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		bgm->Stop();			//BGM���~�߂�
		NowScene = SCENE_TITLE;	//�^�C�g����ʂ�
	}

}