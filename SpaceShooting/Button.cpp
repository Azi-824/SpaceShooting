//Button.cpp
//�{�^���̃N���X

//############### �w�b�_�t�@�C���ǂݍ��� ###################
#include "Button.hpp"

//############### �N���X��` ###############

Music* Button::se;			//���ʉ�

//�R���X�g���N�^
Button::Button(const char *text)
{
	this->text = text;	//�����ݒ�
	rect = { 0 };	//�̈揉����
	if (se == NULL)	//���ʉ�����Ȃ�
	{
		se = new Music(MUSIC_DIR_SE, SE_NAME_KETTEI);	//���ʉ��ǉ�
	}
}

//�R���X�g���N�^
Button::Button(Image* img)
{
	this->img = img;
	rect = { 0 };	//�̈揉����
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
	//�̈�ݒ�
	rect.left = x;						//����X
	rect.top = y;						//����Y
	int width = 0, height = 0;	//�����A����
	if (img == NULL)	//�摜���ݒ肳��Ă��Ȃ��ꍇ
	{
		//�e�L�X�g�̃T�C�Y���擾
		width = GetDrawStringWidth(text.c_str(), strlen(text.c_str()));	//�����擾
		height = GetFontSize();	//�����擾
	}
	else		//�摜���ݒ肳��Ă���ꍇ
	{
		//�摜�̃T�C�Y���擾
		img->SetInit();				//�摜�����ݒ�
		width = img->GetWidth();	//�摜�̉����擾
		height = img->GetHeight();	//�摜�̍����擾
	}
	rect.right = x + width;		//�E��X
	rect.bottom = y + height;	//�E��Y
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
	if (img == NULL)	//�摜���ݒ肳��Ă��Ȃ��ꍇ
	{
		DrawString(rect.left, rect.top, text.c_str(), COLOR_WHITE);	//�����`��
	}
	else //�摜���ݒ肳��Ă���ꍇ
	{
		img->Draw(rect.left, rect.top);	//�摜�`��
	}
}
