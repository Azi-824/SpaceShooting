/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* Fps.hpp     																					   */
/* Fps(Flame Per Second)�N���X																	   */
/* ��̃C���X�^���X�݂̂ɂ���																	   */

#pragma once

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "Global.hpp"

//########## �N���X�̒�` ##########
class Fps
{
private:
	int			value;					//FPS�l
	double		drawValue;				//Draw����Ƃ���FPS�l
	double		calcStartTime;			//0�t���[���ڂ̊J�n����
	double		calcEndTime;			//�ݒ肵���t���[���̏I������
	double		flameCount;				//�t���[���̃J�E���g
	double		calcAverage; 			//FPS���v�Z���邽�߂̕��σT���v����

	int			TotalFlameCnt;			//���݂̑��t���[����

public:

	//�R���X�g���N�^
	//���@���Fint�@�FFPS�l
	Fps(int);

	//�w�肵��FPS�ɂȂ�悤�ɑ҂�
	void Wait(void);

	//��ʍX�V�̎������擾����
	void Update(void);

	//FPS�̒l��\������
	//���@���Fint�@�F�l��\������X�ʒu
	//���@���Fint�@�F�l��\������Y�ʒu
	void Draw(int, int);

	//FPS�l���擾����
	int Getvalue(void);

	//���t���[�����擾����
	int GetTotalFlameCnt(void);

	//�f�X�g���N�^
	virtual ~Fps();
};

//########## �O���I�u�W�F�N�g ##########
extern Fps *fps;