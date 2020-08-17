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
	SpawnX = 0;			//�e���˒n�_X
	SpawnY = 0;			//�e���˒n�_Y

	this->img = img;
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

	Move();		//�v���C���[�̈ړ�����

	if (Mouse::OnRightClick())	//�E�N���b�N���ꂽ��
	{
		bullet.push_back(new Bullet());	//�e�𐶐�
		bullet.back()->SetInit(SpawnX, SpawnY);	//�����ݒ�
		bullet.back()->Shot();	//����
	}

	//�e�̏���
	for (int i = 0; i < bullet.size(); ++i)
	{
		bullet.at(i)->Move();	//�e�̈ړ�����

		if (!bullet.at(i)->InScreen())	//��ʊO�ɏo����
		{
			delete bullet.at(i);	//�j��
			bullet.erase(bullet.begin() + i);
		}
	}

	Draw();	//�v���C���[�`��
}


//�����ݒ�
void Player::SetInit()
{
	img->SetInit();		//�摜�����ݒ�
	img->SetPos((GAME_WIDTH / 2) - (img->GetWidth() / 2), GAME_HEIGHT - img->GetHeight());	//�`��ʒu�ݒ�
}

//������
void Player::Init()
{
	//�����蔻��ݒ�
	collision.left = (GAME_WIDTH / 2) - (img->GetWidth() / 2);		//����X
	collision.top = GAME_HEIGHT - img->GetHeight();					//����Y
	collision.right = collision.left + img->GetWidth();				//�E��X
	collision.bottom = collision.top + img->GetHeight();			//�E��Y

	//�e���ˈʒu
	SpawnX = (collision.left + collision.right) / 2;
	SpawnY = collision.top;

	if (!bullet.empty())	//�e�����˂���Ă�����
	{
		//�e���폜
		for (auto b : bullet)
		{
			delete b;
		}
		bullet.erase(bullet.begin(), bullet.end());	
	}

}

//�`��
void Player::Draw()
{
	img->Draw(collision.left, collision.top);
	for (auto b : bullet) { b->Draw(); }		//�e�`��
}

//�ړ�����
void Player::Move()
{
	int x = 0, y = 0;		//�}�E�X�ʒu�擾�p
	Mouse::GetPos(&x, &y);	//�}�E�X�ʒu�擾

	if (x - img->GetWidth() / 2 < GAME_LEFT || x + img->GetWidth() / 2 > GAME_WIDTH)	//��ʊO�̏ꍇ
		return;			//�ړ����Ȃ�

	//�����蔻��ړ�
	collision.left = x - img->GetWidth() / 2;
	collision.right = collision.left + img->GetWidth();
	//�e���ˈʒu
	SpawnX = (collision.left + collision.right) / 2;

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

//�G�ɒe����������
void Player::HitBullet(int element)
{
	delete bullet.at(element);	//�j��
	bullet.erase(bullet.begin() + element);
}
