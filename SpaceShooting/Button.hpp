//Button.hpp
//�{�^���̃N���X

#pragma once

//################# �w�b�_�t�@�C���ǂݍ��� ####################
#include "Global.hpp"
#include "Image.hpp"
#include "Music.hpp"

//################# �}�N����` ################
#define BT_IMG_DIR			R"(.\Image\Button)"	//�{�^���̉摜�̃f�B���N�g��

#define BT_START_IMG_NAME	R"(\start.png)"		//�{�^���̉摜(start)
#define BT_END_IMG_NAME		R"(\end.png)"		//�{�^���̉摜(end)

#define BT_START_X	150		//�X�^�[�g�{�^��X�ʒu
#define BT_START_Y	500		//�X�^�[�g�{�^��Y�ʒu
#define BT_END_X	500		//�X�^�[�g�{�^��X�ʒu
#define BT_END_Y	500		//�X�^�[�g�{�^��Y�ʒu

#define RECT_TOUKA_VALUE		0.8	//�̈�̓��ߗ�

//################# �񋓌^ #################
enum BT_TYPE
{
	BT_START,		//�X�^�[�g
	BT_END			//�G���h
};

using std::string;
//################# �N���X��` ################
class Button
{
private:

	string text;//����
	Image* img;	//�摜
	RECT rect;	//�̈�
	static Music* se;	//���ʉ�

public:

	Button(const char*);//�R���X�g���N�^
	Button(Image*);		//�R���X�g���N�^
	~Button();			//�f�X�g���N�^

	void SetInit(int,int);	//�����ݒ�

	void UpDate();	//�X�V����

	bool OnClick();	//�N���b�N���ꂽ��
	void Draw();	//�`��
	
	template <typename F>
	void Event(F func)	//�N���b�N���ꂽ���̃C�x���g
	{
		func();
	}

};
