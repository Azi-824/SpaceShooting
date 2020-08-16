//Player.cpp

//########### �w�b�_�t�@�C���ǂݍ��� #############
#include "Player.hpp"

//########### �N���X��` ############

//�R���X�g���N�^
//�����FImage *�F�L�����N�^�[�̉摜
Player::Player(Image* img)
{
	//�����o�[������
	collision = { 0 };	//�����蔻��
	Hp = 0;				//HP
	rota = 0.0;			//�p�x
	col = new Collision();	//�����蔻��쐬

	this->img = img;
	bullet.push_back(new Bullet());
}

//�f�X�g���N�^
Player::~Player()
{
	for (auto b : bullet) { delete b; }
	vector<Bullet*> v;
	bullet.swap(v);

	delete img;	//img�j��
}

//����s������
void Player::UpDate()
{

	//�p�x�v�Z
	CalcRota();

	if (Mouse::OnLeftClick())	//���N���b�N���ꂽ��
	{
		Shot();	//�e������
		bullet.push_back(new Bullet());	//�e�𐶐�
		bullet.back()->SetInit(GAME_WIDTH / 2, collision.top);	//�����ݒ�
	}

	//��ʊO�ɏo���e���폜
	for (int i = 0; i < bullet.size(); ++i)
	{
		if (!bullet.at(i)->InScreen())
		{
			delete bullet.at(i);	//�j��
			bullet.erase(bullet.begin() + i);
		}
	}
	Draw();
}


//�����ݒ�
void Player::SetInit()
{
	img->SetInit();		//�摜�����ݒ�
	img->SetPos((GAME_WIDTH / 2) - (img->GetWidth() / 2), GAME_HEIGHT - img->GetHeight());	//�`��ʒu�ݒ�

	//�����蔻��ݒ�
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//����X
	collision.top = GAME_HEIGHT - img->GetHeight();					//����Y
	collision.right = collision.left + img->GetWidth();				//�E��X
	collision.bottom = collision.top + img->GetHeight();			//�E��Y
	
	col->Set((GAME_WIDTH / 2) - (img->GetWidth() / 2), GAME_HEIGHT - img->GetHeight(), collision.left + img->GetWidth(), collision.top + img->GetHeight());


	for (auto b : bullet) { b->SetInit(GAME_WIDTH / 2, collision.top); }	//�e�̏�����

}

//�`��
void Player::Draw()
{
	img->DrawRota(rota);	//�`��(�L����)
	//img->Draw(collision.left, collision.top);
	//DrawBox(collision.left, collision.top, collision.right, collision.bottom,COLOR_RED,FALSE);
	col->Draw();
	DrawFormatString(0, 150, COLOR_WHITE, "left:%d\ntop:%d\nright:%d\nbottom:%d", collision.left, collision.top, collision.right, collision.bottom);
	for (auto b : bullet) { b->Draw(); }		//�e�`��
}

//�e������
void Player::Shot()
{
	bullet.back()->SetIsDraw(true);
}

//�����蔻��擾
RECT Player::GetCol()
{
	return collision;
}

//�e�̓����蔻��擾
RECT Player::GetBulletCol(int element)
{
	return bullet.at(element)->GetCol();
}

//���݂̒e�̐����擾
int Player::GetBulleMax()
{
	return Bullet::GetElementMax();
}

//�p�x�v�Z
void Player::CalcRota()
{
	int x = 0, y = 0;		//�}�E�X�ʒu�擾�p
	Mouse::GetPos(&x, &y);	//�}�E�X�ʒu�擾

	if (x < GAME_LEFT || x > GAME_WIDTH)	//��ʊO�̏ꍇ
		return;			//�v�Z���Ȃ�

	x -= ROTA_BASE;			//��l����̋����𑪒�

	if (rota == (double)x / ROTA_BASE)
		return;

	//�p�x�v�Z����
	rota = (double)x / ROTA_BASE;

	int center_x = img->GetCenterX();
	int center_y = img->GetCenterY();

	int left = (collision.left - center_x) * cos(rota) - (collision.top - center_y) * sin(rota) + center_x;
	int top = (collision.left - center_x) * sin(rota) + (collision.top - center_y) * cos(rota) + center_y;
	int right = (collision.right - center_x) * cos(rota) - (collision.bottom - center_y) * sin(rota) + center_x;
	int bottom = (collision.right - center_x) * sin(rota) + (collision.bottom - center_y) * cos(rota) + center_y;

	collision.left = left;
	collision.top = top;
	collision.right = right;
	collision.bottom = bottom;

}