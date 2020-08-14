//Charactor.hpp
//�G�A�����̊�ɂȂ�N���X

#pragma once

//##################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "Global.hpp"
#include "Image.hpp"
#include "Bullet.hpp"

//##################### �}�N����` ##################
#define CHAR_IMG_DIR	R"(.\Image\Charactor)"		//�L�����̉摜�t�@�C���̃f�B���N�g��

#define PLAYER_IMG_NAME	R"(\player.png)"			//�v���C���[�̉摜�t�@�C���̖��O
#define ENEMY1_IMG_NAME	R"(\enemy1.png)"			//�G�L����1�̉摜�t�@�C���̖��O

//##################### �񋓌^ ##################
enum CHARA_KIND
{
	CHARA_KIND_PLAYER,	//�v���C���[
	CHARA_KIND_ENEMY1	//�G1
};

//##################### �N���X��` ##################
class Charactor
{

protected:

	Image* img;		//�摜
	RECT collision;	//�����蔻��
	Animation* b_anim;	//�e�̃A�j���[�V����
	Bullet* bullet;	//�e

	int Hp;			//HP

public:

	Charactor();	//�R���X�g���N�^
	~Charactor();	//�f�X�g���N�^

	virtual void Draw();	//�`��
	virtual void SetInit() = 0;	//�����ݒ�
	virtual void Shot() = 0;	//�e������

};
