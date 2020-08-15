//Scene.cpp

//############# �w�b�_�t�@�C���ǂݍ��� ###############
#include "Scene.hpp"

//############## �N���X��` ################

int Scene::NowScene = 0;			//���݂̃V�[��
bool Scene::IsGameStart = false;	//�Q�[���X�^�[�g�ł��邩
bool Scene::GameEnd = false;		//�Q�[���G���h�t���O

//�R���X�g���N�^
Scene::Scene()
{
	back = new Image();	//�C���X�^���X����
	bgm = new Music();	//�C���X�^���X����
	Animation::CreateList();	//�A�j���[�V�������X�g�쐬
	IsLoad = false;		//�ǂݍ��߂Ă��Ȃ�
}

//�f�X�g���N�^
Scene::~Scene()
{
	delete back;	//back�j��
	delete bgm;		//bgm�j��	
}

//���݂̃V�[�����擾
int Scene::GetNowScene()
{
	return NowScene;
}

//�Q�[���G���h�t���O���擾
bool Scene::IsGameEnd()
{
	return GameEnd;
}

//�Q�[���X�^�[�g�ł��邩�擾
bool Scene::GetIsGameStart()
{
	return IsGameStart;
}

//�ǂݍ��߂����擾
bool Scene::GetIsLoad()
{
	return IsLoad;
}
