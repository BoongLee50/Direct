#pragma once
#include "CD3DApp.h"
#include <D3dx9shape.h>
#include <conio.h>
#include <fmod.h>
#include "Axis.h"
#include "Ground.h"

struct TEAPOT_PROPERTY
{
	float fScaling;
	float fRotX, fRotY, fRotZ;
	D3DXVECTOR3 vTranslation;
	TEAPOT_PROPERTY() : fScaling(1.0f) {}
};

class GameCode : public CD3DApp
{
	CGround m_Ground;

	D3DXMATRIX m_matView;
	D3DXMATRIX m_matProj;
	D3DXVECTOR3 m_Eye, m_At, m_Up;
	CAxis m_Axis;

	TEAPOT_PROPERTY m_TeapotProperty[3];
	LPD3DXMESH m_pTeapotMesh;
	int m_nAngle;

	virtual void OnInit();
	virtual void OnRender();
	virtual void OnUpdate();
	virtual void OnRelease();

public:
	GameCode(void);
	~GameCode(void);
};

