//Music.hpp
//���y�p�N���X

#pragma once

//##################### �w�b�_�t�@�C���ǂݍ��� #######################
#include "Global.hpp"

//##################### �}�N����`�F�t�@�C���p�X�A���O ###################
#define MUSIC_DIR_SE				R"(.\Music\Se)"			//SE�̃t�@�C����
#define MUSIC_DIR_BGM				R"(.\Music\Bgm)"		//BGM�̃t�@�C����

//BGM
#define BGM_NAME_TITLE				R"(\title.mp3)"			//�^�C�g����BGM
#define BGM_NAME_PLAY				R"(\play.mp3)"			//�v���C��BGM
#define BGM_NAME_RANKING			R"(\ranking.mp3)"		//�����L���O��BGM

////SE
//#define SE_NAME_KETTEI				R"(\kettei.mp3)"		//����̌��ʉ�

//##################### �}�N����`�F�G���[���b�Z�[�W ######################
#define MUSIC_ERROR_TITLE "MUSIC_ERROR"					//�G���[�^�C�g��
#define MUSIC_ERROR_MSG	"�����ǂݍ��߂܂���ł���"		//�G���[���b�Z�[�W

//##################### �}�N����` ##########################
#define VOLUME_MAX		255	//���ʂ̍ő�l

//##################### �񋓌^ #########################

using std::string;

//##################### �N���X��` ############################
class Music
{
private:

	string FilePath;		//�t�@�C���p�X
	string FileName;		//���O

	int Handle;				//�n���h��
	int PlayType;			//���̍Đ����@

	bool IsLoad;			//�ǂݍ��߂���
	bool IsPlayed;			//�Đ��ς݂�


public:

	Music(const char *, const char *);		//�R���X�g���N�^
	Music();								//�R���X�g���N�^
	~Music();								//�f�X�g���N�^

	bool Load(const char*, const char*);	//�ǂݍ���

	bool GetIsLoad();						//�ǂݍ��߂������擾����
	bool GetIsPlay();						//�����Đ�����Ă��邩�擾����
	void SetInit(int, double);				//�����ݒ�

	void ChengePlayType(int);				//���̍Đ����@��ύX����
	void ChengeVolume(double);				//���ʂ�ύX����

	void Play(bool check = true);			//�����Đ�����
	void PlayOne(bool check = true);		//�����Đ�����(1�񂾂�)

	void Reset();							//�Đ��ς݂��ǂ��������Z�b�g����

	void Stop();							//�����~�߂�

};
