//Global.hpp
//�����̃\�[�X�Ŏg�p��������`�Ȃǂ��܂Ƃ߂��w�b�_�[�t�@�C��

#pragma once

//################## �w�b�_�t�@�C���ǂݍ��� ##################
#include "DxLib.h"
#include "Mouse.hpp"
//#include "Font.hpp"
#include <vector>
#include <string>

//################## �}�N����` ######################
#define GAME_LEFT	  0		//��ʂ̉��̎n�_
#define GAME_TOP	  0		//��ʂ̏c�̎n�_
#define GAME_WIDTH	800		//��ʂ̉��̑傫��
#define GAME_HEIGHT	600		//��ʂ̏c�̑傫��
#define GAME_FPS_SPEED					   60

//�F�֌W
#define COLOR_RED	GetColor(255,0,0)		//�ԐF
#define COLOR_GREEN	GetColor(0,255,0)		//�ΐF
#define COLOR_BLUE	GetColor(0,0,255)		//�F
#define COLOR_WHITE GetColor(255,255,255)	//���F
#define COLOR_BLACK GetColor(0,0,0)			//���F
#define COLOR_GRAY GetColor(128,128,128)	//�D�F

//****************** ���̑� ***********************
#define INIT_VALUE		0	//�����l
#define FADE_MAX_CNT	60	//�t�F�[�h�����̃J�E���g�ő�l
#define TOUKA_MAX_VALUE	255	//���߂̍ő�l

//##################### �}�N����` #####################
