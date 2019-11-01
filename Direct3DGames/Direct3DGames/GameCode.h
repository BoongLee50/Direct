#pragma once
#include "CD3DApp.h"
#include <D3dx9shape.h>
#include <conio.h>
#include <fmod.h>
#include "Axis.h"
#include "Ground.h"

struct BULLET					//총알 하나하나의 속성
{
	int nLife;
	D3DXVECTOR3 vPos;
	D3DXMATRIX matTranslation;
};

struct BULLET_PROPERTY			//총알 전체속성
{
	float fBulletVelcoty;
	float fScale;
	D3DXMATRIX matScale;

	D3DXVECTOR3 vMin, vMax;		//충돌 좌표
};

struct PLAYER
{
	int nLife;
	float fScale;
	float fRotationY;
	D3DXVECTOR3 vPos;
	float fVelocity;

	DWORD dwBulletFireTime;			//미사일 발사 간격
	DWORD dwOldBulletFireTime;		//이전 미사일 발사 시간

	D3DXMATRIX matWorld;			//월드 행렬
	D3DXMATRIX matScale;			//크기 행렬
	D3DXMATRIX matRotationY;		//회전 행렬
	D3DXMATRIX matTranslation;		//이동 행렬

	D3DXVECTOR3 vMin, vMax;		//충돌 좌표
};

struct ENEMY				//적의 전체속성
{
	int nLife;
	DWORD dwAppearTime;		//출현시간
	D3DXVECTOR3 vPos;

	DWORD dwOldFireTime;	//미사일 발사 이전 시간
	D3DXMATRIX matTranslation;
};

struct ENEMY_PROPERTY		//적의 개별속성
{
	float fMoveVelcoty;
	float fScale;

	DWORD dwFireTime;		//미사일 발사 시간 간격
	D3DXMATRIX matScale;

	D3DXVECTOR3 vMin, vMax;		//충돌 좌표
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

	// 적 캐릭터 
	ENEMY_PROPERTY m_EnemyProperty;
	ENEMY m_Enemy[100];				//적 캐릭터 100개 
	BULLET_PROPERTY m_EnemyBulletProperty;
	BULLET m_EnemyBullet[100];
	int m_nEnemyIndex;				//적 캐릭터 구분할 수 있도록 하는 배열의 인덱스 값

	DWORD m_dwElapsedTime;

	// 스테이지 정보
	DWORD m_dwGameStartTime;
	DWORD m_dwGameElapsedTime;

	int m_nEnemyCount;

	BOOL CheckCubeIntersection(D3DXVECTOR3* vMin1, D3DXVECTOR3* vMax1, D3DXVECTOR3* vMin2, D3DXVECTOR3* vMax2);
public:
	GameCode(void);
	~GameCode(void);
};

