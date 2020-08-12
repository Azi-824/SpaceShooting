//Mouse.hpp
//�}�E�X�̏����Ǘ�����N���X

#pragma once

//#################### �w�b�_�t�@�C���ǂݍ��� ##################
#include "Global.hpp"

//#################### �}�N����` ######################

//#################### �N���X��` ######################
class Mouse
{

private:

	static bool CheckClickOnRect(RECT);	//�N���b�N�����ʒu���A�w�肳�ꂽ�̈�����m�F
	static int LeftInfo;	//���N���b�N�̏��
	static int RightInfo;	//�E�N���b�N�̏��

public:

	Mouse();	//�R���X�g���N�^
	~Mouse();	//�f�X�g���N�^

	static void ClickUpDate();			//�N���b�N���X�V

	static bool GetPos(int*, int*);	//�}�E�X�̈ʒu���擾
	static bool OnLeftClick();		//���N���b�N���ꂽ��(��ʓ�)
	static bool OnLeftClick(RECT);	//���N���b�N���ꂽ��(�w�肳�ꂽ�̈��)
	static bool OnRightClick();		//�E�N���b�N���ꂽ��(��ʓ�)
	static bool OnRightClick(RECT);	//�E�N���b�N���ꂽ��(�w�肳�ꂽ�̈��)

};
