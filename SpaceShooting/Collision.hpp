//Collision.hpp
//�����蔻��̃N���X(�l�p�`)

#pragma once

//################### �w�b�_�t�@�C���ǂݍ��� ##################
#include "Global.hpp"

//################### �}�N����` ####################

//################### �\���� #######################
struct Coordinate
{
	int X;	//X
	int Y;	//Y
};	//���W

//################### �񋓌^ #################
enum POS_POINT
{
	LEFT_TOP,		//����
	RIGHT_TOP,		//�E��
	RIGHT_BOTTOM,	//�E��
	LEFT_BOTTOM		//����
};

using std::vector;

//################### �N���X��` ####################
class Collision
{
private:

	vector<Coordinate> Pos;	//���W

	int CenterX;			//����X
	int CenterY;			//����Y

public:

	Collision(int, int, int, int);	//�R���X�g���N�^
	Collision(	);					//�R���X�g���N�^
	~Collision();					//�f�X�g���N�^

	void Set(int, int, int, int);	//�ݒ�
	void Draw();					//�`��
	void Rota(int);					//��]

};
