//Animation.cpp
//�A�j���[�V�������Ǘ�����N���X

//################ �w�b�_�t�@�C���ǂݍ��� ##################
#include "Animation.hpp"

//################ �N���X��` ##############

vector<vector<int>> Animation::AnimList;	//�ǂݍ��񂾃A�j���[�V�������X�g

//�R���X�g���N�^
/*
���@���Fint�F�A�j���[�V�����̎��
���@���Fdouble�F���̉摜�ɕύX���鑬��
���@���Fbool�F�A�j���[�V���������[�v���邩�ǂ���
*/

Animation::Animation(int number, double changeSpeed, bool IsLoop)
{

	//�A�j���[�V������ǂݍ���ŁA���X�g���쐬
	if (AnimList.empty())	//���X�g���쐬�Ȃ�
	{
		IsLoad = CreateList();
		if (!IsLoad) { return; }	//�ǂݍ��ݎ��s
	}

	//�����o�[�ϐ�������
	IsLoad = false;			//�ǂݍ��߂����H
	IsDrawEnd = false;		//�`��I��������?
	IsNowDraw = false;		//�`�撆��
	Width = 0;				//������������
	Height = 0;				//������������

	Handle = AnimList.at(number);	//�ꗗ����A�w�肳�ꂽ��ނ̃A�j���[�V�������擾

	ChangeMaxCnt = (GAME_FPS_SPEED * changeSpeed);
	ChangeCnt = 0;	//�A�j���[�V��������t���[���̃J�E���g

	NextChangeSpeed = changeSpeed;	//�摜��ς��鑬��

	IsAnimeLoop = IsLoop;		//�A�j���[�V���������[�v���邩

	Handle_itr = Handle.begin();	//�擪�v�f���C�e���[�^�ɐݒ�

	IsLoad = true;		//�ǂݍ��߂�

}

//�f�X�g���N�^
Animation::~Animation()
{

	//vector�̃�����������s��
	vector<int> v;			//���vector���쐬����
	Handle.swap(v);			//��ƒ��g�����ւ���

}

//���X�g�쐬
bool Animation::CreateList()
{
	vector<int> w;	//��Ɨp
	string Path;	//path

	//***************************** �e�̃A�j���[�V���� *****************************************
	w.resize(ANIM_BULLET_ALL_CNT);
	Path = ANIM_DIR;
	Path += ANIM_NAME_BULLET;

	//�ǂݍ���
	LoadDivGraph(Path.c_str(), ANIM_BULLET_ALL_CNT, ANIM_BULLET_YOKO_CNT, ANIM_BULLET_TATE_CNT, ANIM_BULLET_WIDTH, ANIM_BULLET_HEIGHT, &w.front());

	if (w.front() == -1)	//�摜���ǂݍ��߂Ȃ������Ƃ�
	{
		string ErrorMsg(ANIMATION_ERROR_MSG);		//�G���[���b�Z�[�W�쐬
		ErrorMsg += TEXT('\n');						//���s
		ErrorMsg += Path;							//�摜�̃p�X

		MessageBox(
			NULL,
			ErrorMsg.c_str(),	//char * ��Ԃ�
			TEXT(ANIMATION_ERROR_TTILE),
			MB_OK);

		return false;//�ǂݍ��ݎ��s
	}

	AnimList.push_back(w);	//�n���h����ۑ�

	//***************************** �����̃A�j���[�V���� *****************************************
	w.resize(ANIM_EXPLOSION_ALL_CNT);
	Path = ANIM_DIR;
	Path += ANIM_NAME_EXPLOSION;

	//�ǂݍ���
	LoadDivGraph(Path.c_str(), ANIM_EXPLOSION_ALL_CNT, ANIM_EXPLOSION_YOKO_CNT, ANIM_EXPLOSION_TATE_CNT, ANIM_EXPLOSION_WIDTH, ANIM_EXPLOSION_HEIGHT, &w.front());

	if (w.front() == -1)	//�摜���ǂݍ��߂Ȃ������Ƃ�
	{
		string ErrorMsg(ANIMATION_ERROR_MSG);		//�G���[���b�Z�[�W�쐬
		ErrorMsg += TEXT('\n');						//���s
		ErrorMsg += Path;							//�摜�̃p�X

		MessageBox(
			NULL,
			ErrorMsg.c_str(),	//char * ��Ԃ�
			TEXT(ANIMATION_ERROR_TTILE),
			MB_OK);

		return false;//�ǂݍ��ݎ��s
	}

	AnimList.push_back(w);	//�n���h����ۑ�

	return true;	//�ǂݍ��ݐ���

}

//���X�g�̃n���h�����폜
void Animation::DeleteHandle()
{
	//���X�g�ɓǂݍ��񂾃A�j���[�V�����̃n���h�����폜
	for (auto a : AnimList)
	{
		DeleteGraph(a.front());	
	}
}

//�����ݒ�
void Animation::SetInit()
{
	GetGraphSize(Handle.front(), &Width, &Height);		//�T�C�Y�擾
}

//�����擾
int Animation::GetWidth()
{
	return Width;
}

//�������擾
int Animation::GetHeight()
{
	return Height;
}

//�ǂݍ��߂��H
bool Animation::GetIsLoad(void)
{
	return IsLoad;
}

//�`��I���������ǂ����擾
bool Animation::GetIsDrawEnd()
{
	return IsDrawEnd;
}

//�`�撆���擾
bool Animation::GetIsNowDraw()
{
	return IsNowDraw;
}

//���Z�b�g
void Animation::Reset()
{
	IsDrawEnd = false;
	IsNowDraw = false;		//�`�撆��
}

//�`��
/*
�����Fint�FX�̕`��ʒu
�����Fint�FY�̕`��ʒu
*/
void Animation::Draw(int x, int y)
{
	if (IsDrawEnd == false)	//�A�j���[�V�������I����Ă��Ȃ����
	{
		IsNowDraw = true;		//�`�撆��
		DrawGraph(x, y, *Handle_itr, TRUE);	//�C�e���[�^(�|�C���^)���g�p���ĕ`��
	}

	if (ChangeCnt == ChangeMaxCnt)	//���̉摜��\�����鎞��������
	{
		//this->Handle.end()�́A�Ō�̗v�f�̂P���̃C�e���[�^��Ԃ��̂ŁA-1���Ă���B
		if (Handle_itr == Handle.end() - 1)	//�C�e���[�^(�|�C���^)���Ō�̗v�f�̂Ƃ���
		{
			//�A�j���[�V���������[�v���Ȃ��Ȃ�
			if (IsAnimeLoop == false)
			{
				IsDrawEnd = true;	//�`��I��
				IsNowDraw = false;	//�`�撆��
			}

			//����̕`��ɔ����āA�擪�̉摜�ɖ߂��Ă���
			Handle_itr = Handle.begin();	//�C�e���[�^(�|�C���^)��v�f�̍ŏ��ɖ߂�
		}
		else
		{
			++Handle_itr;	//���̃C�e���[�^(�|�C���^)(���̉摜)�Ɉړ�����
		}

		ChangeCnt = 0;	//�J�E���g������
	}
	else
	{
		++ChangeCnt;	//�J�E���g�A�b�v
	}

}

//��ʒ����ɕ`��
void Animation::DrawCenter()
{
	if (IsDrawEnd == false)	//�A�j���[�V�������I����Ă��Ȃ����
	{
		IsNowDraw = true;		//�`�撆��
		DrawGraph((GAME_WIDTH / 2) - (Width / 2), (GAME_HEIGHT / 2) - (Height / 2), *Handle_itr, TRUE);	//�C�e���[�^(�|�C���^)���g�p���ĕ`��
	}

	if (ChangeCnt == ChangeMaxCnt)	//���̉摜��\�����鎞��������
	{
		//this->Handle.end()�́A�Ō�̗v�f�̂P���̃C�e���[�^��Ԃ��̂ŁA-1���Ă���B
		if (Handle_itr == Handle.end() - 1)	//�C�e���[�^(�|�C���^)���Ō�̗v�f�̂Ƃ���
		{
			//�A�j���[�V���������[�v���Ȃ��Ȃ�
			if (IsAnimeLoop == false)
			{
				IsNowDraw = false;	//�`�撆��
				IsDrawEnd = true;	//�`��I��
			}

			//����̕`��ɔ����āA�擪�̉摜�ɖ߂��Ă���
			Handle_itr = Handle.begin();	//�C�e���[�^(�|�C���^)��v�f�̍ŏ��ɖ߂�
		}
		else
		{
			++Handle_itr;	//���̃C�e���[�^(�|�C���^)(���̉摜)�Ɉړ�����
		}

		ChangeCnt = 0;	//�J�E���g������
	}
	else
	{
		++ChangeCnt;	//�J�E���g�A�b�v
	}

}

//�w�肳�ꂽ�̈���̒����ɕ`��
void Animation::DrawCenter(RECT rect)
{

	int rect_center_x = rect.left + ((rect.right - rect.left) / 2);	//�̈�̒���X�ʒu���v�Z
	int rect_center_y = rect.top + ((rect.bottom - rect.top) / 2);	//�̈�̒���Y�ʒu���v�Z
	int x = rect_center_x - (Width / 2);				//�`��ʒuX���v�Z
	int y = rect_center_y - (Height / 2);				//�`��ʒuY���v�Z

	if (IsDrawEnd == false)	//�A�j���[�V�������I����Ă��Ȃ����
	{
		IsNowDraw = true;		//�`�撆��
		DrawGraph(x, y, *Handle_itr, TRUE);	//�C�e���[�^(�|�C���^)���g�p���ĕ`��
	}

	if (ChangeCnt == ChangeMaxCnt)	//���̉摜��\�����鎞��������
	{
		//this->Handle.end()�́A�Ō�̗v�f�̂P���̃C�e���[�^��Ԃ��̂ŁA-1���Ă���B
		if (Handle_itr == Handle.end() - 1)	//�C�e���[�^(�|�C���^)���Ō�̗v�f�̂Ƃ���
		{
			//�A�j���[�V���������[�v���Ȃ��Ȃ�
			if (IsAnimeLoop == false)
			{
				IsDrawEnd = true;	//�`��I��
				IsNowDraw = false;	//�`�撆��
			}

			//����̕`��ɔ����āA�擪�̉摜�ɖ߂��Ă���
			Handle_itr = Handle.begin();	//�C�e���[�^(�|�C���^)��v�f�̍ŏ��ɖ߂�
		}
		else
		{
			++Handle_itr;	//���̃C�e���[�^(�|�C���^)(���̉摜)�Ɉړ�����
		}

		ChangeCnt = 0;	//�J�E���g������
	}
	else
	{
		++ChangeCnt;	//�J�E���g�A�b�v
	}

}
