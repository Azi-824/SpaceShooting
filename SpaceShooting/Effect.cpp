//Effect.cpp
//�G�t�F�N�g�N���X

//################## �w�b�_�t�@�C���ǂݍ��� ##################
#include "Effect.hpp"

//################## �N���X��` #######################

//�R���X�g���N�^
//����:Animation* :�A�j���[�V����
//����:Music* :���ʉ�
Effect::Effect(Animation* anim,Music* se)
{
	//�����o�[������
	IsFadein = false;	//�t�F�[�h�C�����邩
	IsFadeout = false;	//�t�F�[�h�A�E�g���邩

	this->anim = anim;	//�A�j���[�V����
	this->se = se;		//���ʉ�
}

//�R���X�g���N�^
Effect::Effect()
{
	//�����o�[������
	IsFadein = false;	//�t�F�[�h�C�����邩
	IsFadeout = false;	//�t�F�[�h�A�E�g���邩
}

//�f�X�g���N�^
Effect::~Effect()
{

	delete anim;	//anim�j��
	delete se;		//se�j��

}

//�G�t�F�N�g��ݒ�
//����:Animation* :�A�j���[�V����
//����:Music* :���ʉ�
void Effect::SetEffect(Animation* anim,Music* se)
{
	this->anim = anim;
	this->se = se;
}

//�`��
/*
�����Fint�FX�̕`��ʒu
�����Fint�FY�̕`��ʒu
*/
void Effect::Draw(int x, int y)
{
	anim->Draw(x, y);	//�A�j���[�V�����`��
	se->PlayOne(false);	//���ʉ��Đ�
}

//��ʒ����ɕ`��
void Effect::DrawCenter()
{
	anim->DrawCenter();	//�A�j���[�V�����`��
	se->PlayOne(false);	//���ʉ��Đ�
}

//�w�肳�ꂽ�̈���̒����ɕ`��
void Effect::DrawCenter(RECT rect)
{
	anim->DrawCenter(rect);	//�A�j���[�V�����`��
	se->PlayOne(false);	//���ʉ��Đ�
}

//�����ݒ�
void Effect::SetInit(void)
{
	anim->SetInit();	//�A�j���[�V���������ݒ�
	se->SetInit(DX_PLAYTYPE_BACK, 60);		//�����ݒ�
}

//�G�t�F�N�g�I���������擾
bool Effect::GetIsEffectEnd()
{
	return anim->GetIsDrawEnd();
}

//�G�t�F�N�g�`�撆���擾
bool Effect::GetIsNowEffect()
{
	return anim->GetIsNowDraw();
}

//���Z�b�g
void Effect::Reset()
{
	anim->Reset();	//�A�j���[�V�������Z�b�g
	se->Reset();//���ʉ����Z�b�g
}
