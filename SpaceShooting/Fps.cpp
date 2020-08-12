/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* Fps.cpp     																					   */
/* Fps(Flame Per Second)�N���X																	   */
/* ��̃C���X�^���X�݂̂ɂ���																	   */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "Fps.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
Fps::Fps(int fps_value)
{
	value = fps_value;
	drawValue = 0;
	calcStartTime = 0;
	flameCount = 0;
	calcAverage = (double)value;

	TotalFlameCnt = 0;

	return;
}

//�w�肵��FPS�ɂȂ�悤�ɑ҂�
void Fps::Wait(void)
{
	//���݂̎������~���b�Ŏ擾
	double nowTime = GetTickCount();

	//1�t���[���ڂ�����ۂɂ����������Ԃ��v�Z
	double keikaTime = nowTime - calcStartTime;

	//�[�����Z�΍�
	if (value > 0)
	{
		//�҂ׂ����� = �t���[�������Ƃɂ�����ׂ����� - ���ۂɂ�����������;
		int wait_tm = (flameCount * 1000 / value) - (keikaTime);

		//�҂ׂ����Ԃ��������ꍇ
		if (wait_tm > 0)
		{
			//�~���b���A�����𒆒f����
			Sleep(wait_tm);
		}
	}

	//���t���[�����J�E���g
	TotalFlameCnt++;

	return;
}

//��ʍX�V�̎������擾����
void Fps::Update(void)
{
	//1�t���[���ڂȂ玞�����L��
	if (flameCount == 0)
	{
		//Windows���N�����Ă��猻�݂܂ł̎������~���b�Ŏ擾
		calcStartTime = GetTickCount();
	}

	//�w��t���[���̍Ō�̃t���[���Ȃ�A���ς��v�Z����
	if (flameCount == calcAverage)
	{
		//Windows���N�����Ă��猻�݂܂ł̎������~���b�Ŏ擾
		calcEndTime = GetTickCount();

		//���ϓI��FPS�l���v�Z
		drawValue = 1000.0f / ((calcEndTime - calcStartTime) / calcAverage);

		//����FPS�v�Z�̏���
		calcStartTime = calcEndTime;

		//�J�E���g������
		flameCount = 0;
	}

	//�t���[�����J�E���g�A�b�v
	flameCount++;

	return;
}

//FPS�̒l��\������
void Fps::Draw(int drawX, int drawY)
{
	//�������`��
	DrawFormatString(drawX, drawY, GetColor(255, 255, 255), "FPS:%.1f", drawValue);
	return;
}

//FPS�l���擾����
int Fps::Getvalue(void)
{
	return value;
}

//���t���[�����擾����
int Fps::GetTotalFlameCnt(void)
{
	return TotalFlameCnt;
}

//�f�X�g���N�^
Fps::~Fps()
{
	return;
}