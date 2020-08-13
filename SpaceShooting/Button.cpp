//Button.cpp
//�{�^���̃N���X

//############### �w�b�_�t�@�C���ǂݍ��� ###################
#include "Button.hpp"

//############### �N���X��` ###############

int Button::ElementCnt = 0;	//�v�f��
Music* Button::se;			//���ʉ�

//�R���X�g���N�^
Button::Button(Image* img)
{
	this->img = img;
	rect = { 0 };	//�̈揉����
	Element = ElementCnt++;	//�v�f�ԍ��ݒ�
	if (se == NULL)	//���ʉ�����Ȃ�
	{
		se = new Music(MUSIC_DIR_SE, SE_NAME_KETTEI);	//���ʉ��ǉ�
	}
}

//�f�X�g���N�^
Button::~Button()
{
	delete img;	//img�j��
	delete se;	//se�j��
}

//�����ݒ�
void Button::SetInit(int x,int y)
{
	img->SetInit();	//�摜�����ݒ�
	//�̈�ݒ�
	rect.left = x;						//����X
	rect.top = y;						//����Y
	rect.right = x + img->GetWidth();	//�E��X
	rect.bottom = y + img->GetHeight();	//�E��Y
	se->SetInit(DX_PLAYTYPE_BACK, 60);	//���ʉ�

}

//�X�V����
void Button::UpDate()
{
	//�}�E�X���{�^���̗̈�̒��ɂ��邩
	if (Mouse::HoverRect(rect))	//�̈���̎�
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, RECT_TOUKA_VALUE * TOUKA_MAX_VALUE);	//���߂�����
		DrawBox(rect.left, rect.top, rect.right, rect.bottom, COLOR_GRAY, TRUE);	//�����l�p�`��`��
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);									//���߂���߂�
	}
}

//�{�^�����N���b�N���ꂽ��
bool Button::OnClick()
{
	se->Reset();	//�Đ���ԃ��Z�b�g
	bool click = Mouse::OnLeftClick(rect);
	if (click)	//�N���b�N���ꂽ��
		se->PlayOne();	//���ʉ��Đ�

	return click;
}

//�`��
void Button::Draw()
{
	img->Draw(rect.left, rect.top);
}

//�v�f�ԍ��擾
int Button::GetElement()
{
	return Element;
}
