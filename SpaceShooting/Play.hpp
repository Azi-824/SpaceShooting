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
	CHARA_KIND_ENEMY1	//�G1
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
