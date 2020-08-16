/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* Image.cpp     																				�@ */
/* �摜�N���X 																					�@ */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "Global.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

//########## �}�N����`�F�摜�̃t�@�C���p�X�Ɩ��O ##########
#define IMG_DIR_BACK		R"(.\Image\Back)"			//�w�i�摜�̃t�@�C���̏ꏊ
#define CHAR_IMG_DIR		R"(.\Image\Charactor)"		//�L�����̉摜�t�@�C���̃f�B���N�g��

#define PLAYER_IMG_NAME		R"(\player.png)"			//�v���C���[�̉摜�t�@�C���̖��O
#define ENEMY1_IMG_NAME		R"(\enemy1.png)"			//�G�L����1�̉摜�t�@�C���̖��O


#define IMG_NAME_TITLE		R"(\title.jpg)"				//�^�C�g����ʂ̔w�i�摜�̖��O
#define IMG_NAME_PLAY		R"(\play.jpg)"				//�v���C��ʂ̔w�i�摜�̖��O
#define IMG_NAME_RANKING	R"(\ranking.jpg)"			//�����L���O��ʂ̔w�i�摜�̖��O

#define FADE_MAX_CNT	60	//�t�F�[�h�����̃J�E���g�ő�l
#define TOUKA_MAX_VALUE	255	//���߂̍ő�l

//########## �}�N����`�F�G���[���b�Z�[�W##########
#define IMAGE_ERROR_TITLE "IMAGE_ERROR"					//�G���[�^�C�g��
#define IMAGE_ERROR_MSG	"�摜���ǂݍ��߂܂���ł���"	//�G���[���b�Z�[�W

//########## �񋓌^ ################
enum BACK_IMAGE
{
	TITLE_BACK,		//�^�C�g����ʂ̔w�i�摜
	PLAY_BACK,		//�v���C��ʂ̔w�i�摜
	RANKING_BACK	//�����L���O���
};

using std::string;

//########## �N���X�̒�` ##########
class Image
{
private:
	string FilePath;	//�p�X
	string FileName;	//���O

	int Handle;			//�n���h��

	int X;				//X
	int Y;				//Y
	int CenterX;		//����X
	int CenterY;		//����Y
	int Width;			//��
	int Height;			//����

	bool IsLoad;		//�ǂݍ��߂����H
	bool IsDraw;		//�`�悵�Ă悢��
	bool IsFade;		//�t�F�[�h�A�E�g���邩
	bool FadeEnd;		//�t�F�[�h�G�t�F�N�g���I�������

public:
	Image(const char *,const char *);	//�R���X�g���N�^
	Image();							//�R���X�g���N�^
	virtual ~Image();					//�f�X�g���N�^

	bool Load(const char*, const char*);//�ǂݍ���

	string GetFileName(void);	//���O���擾

	void SetInit(void);				//�����ݒ�
	void SetPos(int, int);			//�`��ʒu�ݒ�

	int GetCenterX();				//����X�擾
	int GetCenterY();				//����Y�擾
	int GetWidth();					//�����擾
	int GetHeight();				//�������擾

	bool GetIsLoad(void);			//�ǂݍ��߂��H
	bool GetIsDraw();				//�`�悵�Ă悢���擾
	void SetIsDraw(bool);			//�`�悵�Ă悢���ݒ�

	void Draw();					//�摜��`��
	void Draw(int, int);			//�摜��`��i�w�肳�ꂽ�ʒu�j
	void DrawCenter();				//�摜��`��i�����j
	void DrawCenterY(int);			//�摜��`��i�㉺�����j
	void DrawCenterX(int);			//�摜��`��i���E�����j

	void SetIsFade(bool);			//�t�F�[�h�A�E�g���邩�ݒ�
	bool GetFadeEnd();				//�t�F�[�h�G�t�F�N�g���I�����Ă��邩�擾

};

