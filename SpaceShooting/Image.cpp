/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* Image.cpp     																				�@ */
/*       																						�@ */

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "Image.hpp"

//########## �N���X�̒�` ##########

//�R���X�g���N�^
//���@���Fconst char *�F�摜�̃f�B���N�g��
//���@���Fconst char *�F�摜�̖��O
Image::Image(const char *dir,const char *name)
{
	//�����o�ϐ���������
	FilePath = "";	//�p�X
	FileName = "";	//���O
	
	IsLoad = false;	//�ǂݍ��߂����H

	//�摜��ǂݍ���
	string LoadfilePath;	//�摜�̃t�@�C���p�X���쐬
	LoadfilePath += dir;
	LoadfilePath += name;

	Handle = LoadGraph(LoadfilePath.c_str());//�摜��ǂݍ���
	
	if (Handle == -1)	//�摜���ǂݍ��߂Ȃ������Ƃ�
	{
		string ErroeMsg(IMAGE_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
		ErroeMsg += TEXT('\n');				//���s
		ErroeMsg += LoadfilePath;			//�摜�̃p�X

		MessageBox(
			NULL, 
			ErroeMsg.c_str(),	//char * ��Ԃ�
			TEXT(IMAGE_ERROR_TITLE),
			MB_OK);

		return;
	}

	FilePath = LoadfilePath;		//�摜�̃p�X��ݒ�
	FileName = name;				//�摜�̖��O��ݒ�

	IsLoad = true;		//�ǂݍ��߂�

	IsDraw = true;	//�`�悵�Ă悢

	IsFade = false;	//�t�F�[�h�A�E�g���Ȃ�
	FadeEnd = false;//�t�F�[�h�G�t�F�N�g���I����Ă��Ȃ�
}

//�R���X�g���N�^
Image::Image()
{
	//�����o�ϐ���������
	FilePath = "";	//�p�X
	FileName = "";	//���O
	IsLoad = false;	//�ǂݍ��߂����H
	Handle = 0;
	IsDraw = true;	//�`�悵�Ă悢
	IsFade = false;	//�t�F�[�h�A�E�g���Ȃ�
	FadeEnd = false;//�t�F�[�h�G�t�F�N�g���I����Ă��Ȃ�

}

//�f�X�g���N�^
Image::~Image()
{
	DeleteGraph(Handle);	//�ǂݍ��񂾉摜���폜
}

//�ǂݍ���
bool Image::Load(const char* dir, const char* name)
{
	//�����o�ϐ���������
	FilePath = "";	//�p�X
	FileName = "";	//���O

	IsLoad = false;	//�ǂݍ��߂����H

	//�摜��ǂݍ���
	string LoadfilePath;	//�摜�̃t�@�C���p�X���쐬
	LoadfilePath += dir;
	LoadfilePath += name;

	Handle = LoadGraph(LoadfilePath.c_str());//�摜��ǂݍ���

	if (Handle == -1)	//�摜���ǂݍ��߂Ȃ������Ƃ�
	{
		string ErroeMsg(IMAGE_ERROR_MSG);	//�G���[���b�Z�[�W�쐬
		ErroeMsg += TEXT('\n');				//���s
		ErroeMsg += LoadfilePath;			//�摜�̃p�X

		MessageBox(
			NULL,
			ErroeMsg.c_str(),	//char * ��Ԃ�
			TEXT(IMAGE_ERROR_TITLE),
			MB_OK);

		return false;
	}

	FilePath = LoadfilePath;		//�摜�̃p�X��ݒ�
	FileName = name;				//�摜�̖��O��ݒ�

	IsDraw = true;	//�`�悵�Ă悢

	IsFade = false;	//�t�F�[�h�A�E�g���Ȃ�
	FadeEnd = false;//�t�F�[�h�G�t�F�N�g���I����Ă��Ȃ�

	return true;	//�ǂݍ��߂�

}

//�t�@�C���̖��O���擾
std::string Image::GetFileName(void)
{
	return FileName;
}

//�T�C�Y��ݒ肷��
void Image::SetInit(void)
{
	GetGraphSize(Handle, &Width, &Height);	//�摜�T�C�Y�擾
	return;
}

//�����擾
int Image::GetWidth()
{
	return Width;
}

//�������擾
int Image::GetHeight()
{
	return Height;
}

//�ǂݍ��߂��H
bool Image::GetIsLoad(void)
{
	return IsLoad;
}

//�`�悵�Ă悢���擾
bool Image::GetIsDraw()
{
	return IsDraw;
}

//�`�悵�Ă悢���ݒ�
void Image::SetIsDraw(bool isdraw)
{
	IsDraw = isdraw;
	FadeEnd = false;	//�t�F�[�h�A�E�g�I���t���O���Z�b�g
}

//�摜��`��
void Image::Draw(int x, int y)
{

	static int cnt = FADE_MAX_CNT;				//�J�E���g�p

	if (IsFade)	//�t�F�[�h�A�E�g����Ƃ���
	{
		if (!FadeEnd)	//�t�F�[�h�A�E�g�I�����Ă��Ȃ����
		{

			if (IsDraw)	//�`�悵�Ă悯���
			{
				
				//60�t���[�����A�҂�
				if (cnt > 0)
				{
					--cnt;	//�J�E���g�A�b�v
				}
				else
				{
					FadeEnd = true;	//�t�F�[�h�I��
				}

				//�t�F�[�h�A�E�g�̏���
				double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//����%���v�Z
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//���߂�����
				DrawGraph(x, y, Handle, TRUE);											//�摜��`��
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//���߂���߂�


			}


		}
		else 		//�t�F�[�h�A�E�g�I��������
		{
			IsDraw = false;			//�`�悵�Ȃ�
			cnt = FADE_MAX_CNT;		//�J�E���g���Z�b�g
			IsFade = false;			//�t�F�[�h�A�E�g���Ȃ�
		}

	}
	else		//�t�F�[�h�A�E�g���Ȃ�����
	{
		cnt = FADE_MAX_CNT;		//�J�E���g���Z�b�g

		if (IsDraw)	//�`�悵�Ă悯���
		{
			DrawGraph(x, y, Handle, TRUE);	//�摜��`��
		}

	}
	

	return;

}

//�摜��`��i�����j
void Image::DrawCenter()
{

	int x = 0, y = 0;	//�`�悷��X�ʒu,Y�ʒu
	x = (GAME_WIDTH / 2) - (Width / 2);			//��ʒ����ɂȂ�悤�Ɍv�Z
	y = (GAME_HEIGHT / 2) - (Height / 2);		//��ʒ����ɂȂ�悤�Ɍv�Z

	static int cnt = FADE_MAX_CNT;				//�J�E���g�p

	if (IsFade)	//�t�F�[�h�A�E�g����Ƃ���
	{
		if (!FadeEnd)	//�t�F�[�h�A�E�g�I�����Ă��Ȃ����
		{

			if (IsDraw)	//�`�悵�Ă悯���
			{

				//60�t���[�����A�҂�
				if (cnt > 0)
				{
					--cnt;	//�J�E���g�A�b�v
				}
				else
				{
					FadeEnd = true;	//�t�F�[�h�I��
				}

				//�t�F�[�h�A�E�g�̏���
				double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//����%���v�Z
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//���߂�����
				DrawGraph(x, y, Handle, TRUE);					//�摜��`��
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//���߂���߂�


			}


		}
		else 		//�t�F�[�h�A�E�g�I��������
		{
			IsDraw = false;	//�`�悵�Ȃ�
			cnt = FADE_MAX_CNT;				//�J�E���g���Z�b�g
			IsFade = false;	//�t�F�[�h�A�E�g���Ȃ�
		}

	}
	else		//�t�F�[�h�A�E�g���Ȃ�����
	{
		cnt = FADE_MAX_CNT;		//�J�E���g���Z�b�g

		if (IsDraw)	//�`�悵�Ă悯���
		{
			DrawGraph(x, y, Handle, TRUE);	//�摜��`��
		}

	}



	return;
}

//�摜��`��i�㉺�����j
//�����Fint�F�`��X�ʒu
void Image::DrawCenterY(int x)
{

	int y = 0;	//�`�悷��Y�ʒu
	y = (GAME_HEIGHT / 2) - (Height / 2);	//�㉺�����ɂȂ�悤�Ɍv�Z

	static int cnt = FADE_MAX_CNT;				//�J�E���g�p

	if (IsFade)	//�t�F�[�h�A�E�g����Ƃ���
	{
		if (!FadeEnd)	//�t�F�[�h�A�E�g�I�����Ă��Ȃ����
		{

			if (IsDraw)	//�`�悵�Ă悯���
			{

				//60�t���[�����A�҂�
				if (cnt > 0)
				{
					--cnt;	//�J�E���g�A�b�v
				}
				else
				{
					FadeEnd = true;	//�t�F�[�h�I��
				}

				//�t�F�[�h�A�E�g�̏���
				double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//����%���v�Z
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//���߂�����
				DrawGraph(x, y, Handle, TRUE);					//�摜��`��
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//���߂���߂�


			}


		}
		else 		//�t�F�[�h�A�E�g�I��������
		{
			IsDraw = false;	//�`�悵�Ȃ�
			cnt = FADE_MAX_CNT;				//�J�E���g���Z�b�g
			IsFade = false;	//�t�F�[�h�A�E�g���Ȃ�
		}

	}
	else		//�t�F�[�h�A�E�g���Ȃ�����
	{
		cnt = FADE_MAX_CNT;		//�J�E���g���Z�b�g

		if (IsDraw)	//�`�悵�Ă悯���
		{
			DrawGraph(x, y, Handle, TRUE);	//�摜��`��
		}

	}



	return;
}

//�摜��`��i���E�����j
//�����Fint�F�`��Y�ʒu
void Image::DrawCenterX(int y)
{

	int x = 0;	//�`�悷��Y�ʒu
	x = (GAME_WIDTH / 2) - (Width / 2);	//���E�����ɂȂ�悤�Ɍv�Z

	static int cnt = FADE_MAX_CNT;				//�J�E���g�p

	if (IsFade)	//�t�F�[�h�A�E�g����Ƃ���
	{
		if (!FadeEnd)	//�t�F�[�h�A�E�g�I�����Ă��Ȃ����
		{

			if (IsDraw)	//�`�悵�Ă悯���
			{

				//60�t���[�����A�҂�
				if (cnt > 0)
				{
					--cnt;	//�J�E���g�A�b�v
				}
				else
				{
					FadeEnd = true;	//�t�F�[�h�I��
				}

				//�t�F�[�h�A�E�g�̏���
				double ToukaPercent = cnt / (double)FADE_MAX_CNT;						//����%���v�Z
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, ToukaPercent * TOUKA_MAX_VALUE);	//���߂�����
				DrawGraph(x, y, Handle, TRUE);					//�摜��`��
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//���߂���߂�


			}


		}
		else 		//�t�F�[�h�A�E�g�I��������
		{
			IsDraw = false;	//�`�悵�Ȃ�
			cnt = FADE_MAX_CNT;				//�J�E���g���Z�b�g
			IsFade = false;	//�t�F�[�h�A�E�g���Ȃ�
		}

	}
	else		//�t�F�[�h�A�E�g���Ȃ�����
	{
		cnt = FADE_MAX_CNT;		//�J�E���g���Z�b�g

		if (IsDraw)	//�`�悵�Ă悯���
		{
			DrawGraph(x, y, Handle, TRUE);	//�摜��`��
		}

	}



	return;
}

//�t�F�[�h�A�E�g���邩�ݒ�
void Image::SetIsFade(bool isfade)
{
	IsFade = isfade;
	FadeEnd = false;	//�t�F�[�h�A�E�g�I���t���O���Z�b�g

	return;
}

//�t�F�[�h�G�t�F�N�g���I�����Ă��邩�擾
bool Image::GetFadeEnd()
{
	return FadeEnd;
}
