//Play.hpp
//�v���C��ʂ̏���

#pragma once

//############### �w�b�_�t�@�C���ǂݍ��� ##############
#include "Scene.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

//############### �}�N����` #################

//##################### �񋓌^ ##################
enum CHARA_KIND
{
	CHARA_KIND_PLAYER,	//�v���C���[
	CHARA_KIND_ENEMY1,	//�G1
	CHARA_KIND_ENEMY2,	//�G2
	CHARA_KIND_ENEMY3,	//�G3
	CHARA_KIND_ENEMY4,	//�G4
	CHARA_KIND_ENEMY5,	//�G5
	CHARA_KIND_ENEMY6	//�G6
};

//############### �N���X��` #################
class Play : public Scene	//Scene�N���X���p��
{
private:

	vector<Image*> chara_img;	//�L�����̉摜
	vector<Enemy*> enemy;		//�G
	Player* player;				//�v���C���[

public:

	Play();		//�R���X�g���N�^
	~Play();	//�f�X�g���N�^

	void SetInit() override;	//�����ݒ�
	void PlayScene() override;	//�v���C��ʂ̏���

};
