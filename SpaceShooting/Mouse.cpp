//Mouse.cpp
//�}�E�X�̏����Ǘ�����N���X

//############### �w�b�_�t�@�C���ǂݍ��� #################
#include "Mouse.hpp"

//############### �N���X��` #################

int Mouse::LeftInfo = 0;	//���N���b�N�̏��
int Mouse::RightInfo = 0;	//�E�N���b�N�̏��

//�R���X�g���N�^
Mouse::Mouse(){}

//�f�X�g���N�^
Mouse::~Mouse(){}

//�w�肳�ꂽ�ʒu���A�w�肳�ꂽ�̈�����m�F
//�߂�l: true �̈��: false �̈�O
bool Mouse::CheckClickOnRect(RECT rect)
{
	int x = 0, y = 0;	//�N���b�N���ꂽ���W
	GetPos(&x, &y);		//�ʒu�擾

	//�̈��������
	//X���W����
	if (rect.left <= x && rect.right >= x)
	{
		//Y���W����
		if (rect.top <= y && rect.bottom >= y)
		{
			return true;	//�̈��
		}
	}

	return false;	//�̈�O
}

//�N���b�N���X�V
void Mouse::ClickUpDate()
{

	//���N���b�N����Ă���Ƃ��́A���Z�A����Ă��Ȃ����̓��Z�b�g
	(GetMouseInput() & MOUSE_INPUT_LEFT) != 0 ? ++LeftInfo : LeftInfo = 0;
	//�E�N���b�N����Ă���Ƃ��́A���Z�A����Ă��Ȃ����̓��Z�b�g
	(GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 ? ++RightInfo : RightInfo = 0;

}

//�}�E�X�̈ʒu���擾
bool Mouse::GetPos(int* x, int* y)
{
	//�}�E�X�̈ʒu���擾���A����������Atrue���s������Afalse��Ԃ�
	return GetMousePoint(x, y) == 0 ? true : false;
}

//���N���b�N���ꂽ��(��ʓ�)
//�߂�l: true �N���b�N���ꂽ: false �N���b�N����Ă��Ȃ�
bool Mouse::OnLeftClick()
{
	//�N���b�N���ꂽ�u�Ԃ���true��Ԃ�
	return LeftInfo == 1 ? true : false;
}

//���N���b�N���ꂽ��(�w�肳�ꂽ�̈��)
//�߂�l: true �N���b�N���ꂽ: false �N���b�N����Ă��Ȃ�
bool Mouse::OnLeftClick(RECT rect)
{
	if (CheckClickOnRect(rect))	//�̈���̎�
	{
		//�N���b�N���ꂽ�u�Ԃ���true��Ԃ�
		return OnLeftClick();
	}
	else //�̈�O�̎�
	{
		return false;	
	}
}

//�E�N���b�N���ꂽ��(��ʓ�)
//�߂�l: true �N���b�N���ꂽ: false �N���b�N����Ă��Ȃ�
bool Mouse::OnRightClick()
{
	//�N���b�N���ꂽ�u�Ԃ���true��Ԃ�
	return RightInfo == 1 ? true : false;
}

//�E�N���b�N���ꂽ��(�w�肳�ꂽ�̈��)
//�߂�l: true �N���b�N���ꂽ: false �N���b�N����Ă��Ȃ�
bool Mouse::OnRightClick(RECT rect)
{
	if (CheckClickOnRect(rect))	//�̈���̎�
	{
		//�N���b�N���ꂽ�u�Ԃ���true��Ԃ�
		return OnRightClick();
	}
	else //�̈�O�̎�
	{
		return false;
	}
}

