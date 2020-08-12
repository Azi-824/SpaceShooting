//main.cpp

//#################### �w�b�_�t�@�C���ǂݍ��� #######################
#include "main.hpp"
#include "Global.hpp"
#include "Fps.hpp"
#include "Scene.hpp"
#include "Load.hpp"
#include "Title.hpp"
#include "Play.hpp"
#include "End.hpp"

using std::vector;
//########## �O���[�o���I�u�W�F�N�g ##########
Fps* fps = new Fps(GAME_FPS_SPEED);				//fps����
vector<Scene*> scene;	//�V�[��

//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);				//�^�C�g���o�[����

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//�^�C�g���̕���

	SetWindowIconID(GAME_ICON_ID);								//�A�C�R���ύX

	SetAlwaysRunFlag(TRUE);										//��A�N�e�B�u�ɐݒ�

	if (DxLib_Init() == -1) { return -1; }						//�c�w���C�u��������������

	SetDrawScreen(DX_SCREEN_BACK);								//Draw�n�֐��͗���ʂɕ`��

	AddScene();	//�V�[����ǉ�

	//�Q�[���f�[�^�̓ǂݍ��݊J�n
	for (auto s : scene)
	{
		if (!s->DataLoad()) { return -1; }	//�ǂݍ��ݎ��s
	}

	//�Q�[���̃��C�����[�v
	while (GameLoop())
	{
		/*
		���[�v���ňُ킪��������܂Ŗ������[�v
		�Q�[���I����G���[�������������烋�[�v�I��
		*/
	}


	Delete_Class();			//�g�p�����N���X��j��

	DxLib_End();			//�c�w���C�u�����g�p�̏I������

	return 0;
}

//�Q�[���̃��[�v
bool GameLoop()
{
	if (ProcessMessage() != 0) { return false; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

	if (ClearDrawScreen() != 0) { return false; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

	Mouse::ClickUpDate();	//�}�E�X�̏�Ԃ��X�V����

	fps->Update();		//FPS�̏���[�X�V]

	//�����������Q�[���̃V�[���������灥��������

	static bool IsInit = false;	//�����ݒ��������
	if (!IsInit)	//�����ݒ�����Ă��Ȃ�������
	{
		for (auto s : scene)
		{
			s->SetInit();	//�����ݒ�
		}
		IsInit = true;		//�����ݒ�I��
	}

	scene.at(Scene::GetNowScene())->PlayScene();	//�e�V�[���̏���

	//�����������Q�[���̃V�[�������܂Ł���������

	fps->Draw(0, 0);		//FPS�`��

	ScreenFlip();			//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

	fps->Wait();			//FPS�̏���[�҂�]

	return true;			//����

}

//�V�[���ǉ�
void AddScene()
{
	scene.push_back(new Load());	//���[�h��ʒǉ�
	scene.push_back(new Title());	//�^�C�g����ʒǉ�
	scene.push_back(new Play());	//�v���C��ʒǉ�
	scene.push_back(new End());		//�G���h��ʒǉ�
}

//�Q�[�����Ŏg�p�����N���X���폜���鏈��
void Delete_Class()
{

	delete fps;				//fps�j��

	//scene�֌W
	for (auto s : scene)
	{
		delete s;			//scene�j��
	}

	return;
}
