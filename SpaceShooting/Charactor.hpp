//Charactor.hpp
//�G�A�����̊�ɂȂ�N���X

#pragma once

//##################### �w�b�_�t�@�C���ǂݍ��� #####################
#include "Global.hpp"
#include "Image.hpp"

//##################### �}�N����` ##################
#define CHAR_IMG_DIR	R"(.\Image\Charactor)"		//�L�����̉摜�t�@�C���̃f�B���N�g��

#define PLAYER_IMG_NAME	R"(\player.png)"			//�v���C���[�̉摜�t�@�C���̖��O

//##################### �񋓌^ ##################
enum CHARA_KIND
{
	CHARA_KIND_PLAYER	//�v���C���[
};

//##################### �N���X��` ##################
class Charactor
{

protected:

	Image* img;		//�摜
	RECT collision;	//�����蔻��

	int Hp;			//HP

public:

	Charactor();	//�R���X�g���N�^
	~Charactor();	//�f�X�g���N�^

	void Draw();	//�`��
	virtual void SetInit() = 0;	//�����ݒ�

};
