#pragma once
#include "CD3DApp.h"
#include <D3dx9shape.h>
#include <conio.h>
#include <fmod.h>
#include "Axis.h"
#include "Ground.h"

struct BULLET					//�Ѿ� �ϳ��ϳ��� �Ӽ�
{
	int nLife;
	D3DXVECTOR3 vPos;
	D3DXMATRIX matTranslation;
};

struct BULLET_PROPERTY			//�Ѿ� ��ü�Ӽ�
{
	float fBulletVelcoty;
	float fScale;
	D3DXMATRIX matScale;

	D3DXVECTOR3 vMin, vMax;		//�浹 ��ǥ
};

struct PLAYER
{
	int nLife;
	float fScale;
	float fRotationY;
	D3DXVECTOR3 vPos;
	float fVelocity;

	DWORD dwBulletFireTime;			//�̻��� �߻� ����
	DWORD dwOldBulletFireTime;		//���� �̻��� �߻� �ð�

	D3DXMATRIX matWorld;			//���� ���
	D3DXMATRIX matScale;			//ũ�� ���
	D3DXMATRIX matRotationY;		//ȸ�� ���
	D3DXMATRIX matTranslation;		//�̵� ���

	D3DXVECTOR3 vMin, vMax;		//�浹 ��ǥ
};

struct ENEMY				//���� ��ü�Ӽ�
{
	int nLife;
	DWORD dwAppearTime;		//�����ð�
	D3DXVECTOR3 vPos;

	DWORD dwOldFireTime;	//�̻��� �߻� ���� �ð�
	D3DXMATRIX matTranslation;
};

struct ENEMY_PROPERTY		//���� �����Ӽ�
{
	float fMoveVelcoty;
	float fScale;

	DWORD dwFireTime;		//�̻��� �߻� �ð� ����
	D3DXMATRIX matScale;

	D3DXVECTOR3 vMin, vMax;		//�浹 ��ǥ
};

class GameCode : public CD3DApp
{
	virtual void OnInit();
	virtual void OnRender();
	virtual void OnUpdate();
	virtual void OnRelease();

	static const int m_maxBulletCount = 15;

	D3DXMATRIX m_matView;
	D3DXMATRIX m_matProj;
	D3DXVECTOR3 m_Eye, m_At, m_Up;

	CGround m_Ground;

	LPD3DXMESH m_pTeapotMesh;
	LPD3DXMESH m_pPlayerBulletMesh;
	LPD3DXMESH m_pEnemyBoxMesh;
	LPD3DXMESH m_pEnemyBulletMesh;

	PLAYER m_sPlayer;
	BULLET_PROPERTY m_sPlayerBulletProperty;
	BULLET m_sPlayerBullet[m_maxBulletCount];

	// �� ĳ���� 
	ENEMY_PROPERTY m_EnemyProperty;
	ENEMY m_Enemy[100];				//�� ĳ���� 100�� 
	BULLET_PROPERTY m_EnemyBulletProperty;
	BULLET m_EnemyBullet[100];
	int m_nEnemyIndex;				//�� ĳ���� ������ �� �ֵ��� �ϴ� �迭�� �ε��� ��

	DWORD m_dwElapsedTime;

	// �������� ����
	DWORD m_dwGameStartTime;
	DWORD m_dwGameElapsedTime;

	int m_nEnemyCount;

	BOOL CheckCubeIntersection(D3DXVECTOR3* vMin1, D3DXVECTOR3* vMax1, D3DXVECTOR3* vMin2, D3DXVECTOR3* vMax2);
public:
	GameCode(void);
	~GameCode(void);
};

