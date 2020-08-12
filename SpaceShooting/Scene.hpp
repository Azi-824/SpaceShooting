//Scene.hpp
//�e�V�[���̊�ɂȂ�N���X

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ######################
#include "Global.hpp"
#include "Mouse.hpp"
#include "Image.hpp"
#include "Music.hpp"

//################### �}�N����` #########################
//�e�L�X�g�֌W
#define LOAD_TEXT	"NowLoading�c"		//���[�h��ʂ̃e�L�X�g
#define PUSH_TEXT	"PushEnter"			//�G���^�[�L�[�������A�̃e�L�X�g
#define TITLE_TEXT	"NowTitle"			//�^�C�g����ʂ̃e�L�X�g
#define PLAY_TEXT	"NowPlay"			//�v���C��ʂ̃e�L�X�g
#define END_TEXT	"NowEnd"			//�G���h��ʂ̃e�L�X�g

//���W�֌W
#define TEST_TEXT_X	30					//�e�X�g�p�̃e�L�X�g�`��X�ʒu
#define TEST_TEXT_Y	30					//�e�X�g�p�̃e�L�X�g�`��Y�ʒu

//################### �񋓌^ #####################
enum GAME_SCENE
{
	SCENE_LOAD,			//���[�h�V�[��
	SCENE_TITLE,		//�^�C�g���V�[��
	SCENE_PLAY,			//�v���C�V�[��
	SCENE_END			//�G���h�V�[��
};

//################### �N���X��` #########################
class Scene
{
protected:

	static int NowScene;		//���݂̃V�[��
	static Mouse* mouse;		//�}�E�X
	static bool IsGameStart;	//�Q�[���X�^�[�g�ł��邩
	Image* back;				//�w�i�摜
	Music* bgm;					//BGM

public:

	Scene();		//�R���X�g���N�^
	~Scene();		//�f�X�g���N�^

	static int GetNowScene();	//���݂̃V�[�����擾

	virtual void SetInit() = 0;		//�����ݒ�
	virtual bool DataLoad() = 0;	//�V�[�����Ƃ̓ǂݍ���
	virtual void PlayScene() = 0;	//�V�[�����̏���

};
