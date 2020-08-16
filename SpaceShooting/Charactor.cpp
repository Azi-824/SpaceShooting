//Charactor.cpp

//############ �w�b�_�t�@�C���ǂݍ��� ###############
#include "Charactor.hpp"

//############ �N���X��` ############

//�R���X�g���N�^
Charactor::Charactor()
{
	//�����o�[������
	img = new Image();	//�C���X�^���X����
	collision = { 0 };	//�����蔻��
	Hp = 0;				//HP
}

//�f�X�g���N�^
Charactor::~Charactor()
{
	for (auto b : bullet) { delete b; }
	vector<Bullet*> v;
	bullet.swap(v);

	delete img;	//img�j��
}

//����s������
void Charactor::UpDate(Charactor* chara)
{
	Draw();
}

//�����ݒ�
void Charactor::SetInit()
{
	img->SetInit();		//�摜�����ݒ�

	//�����蔻��ݒ�
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//����X
	collision.top = GAME_HEIGHT - img->GetHeight();					//����Y
	collision.right = collision.left + img->GetWidth();				//�E��X
	collision.bottom = collision.top + img->GetHeight();			//�E��Y

}

//�`��
void Charactor::Draw()
{
	img->Draw(collision.left, collision.top);	//�`��
}

//�����蔻��擾
RECT Charactor::GetCol()
{
	return collision;
}

//�e�̓����蔻��擾
RECT Charactor::GetBulletCol(int element)
{
	return bullet.at(element)->GetCol();
}

//���݂̒e�̐����擾
int Charactor::GetBulleMax()
{
	return Bullet::GetElementMax();
}
