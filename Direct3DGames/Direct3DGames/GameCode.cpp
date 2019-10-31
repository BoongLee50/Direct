#include "stdafx.h"
#include "GameCode.h"

GameCode::GameCode(void)
{
	
}


GameCode::~GameCode(void)
{

}

void GameCode::OnInit()
{
	RECT rect;
	D3DVIEWPORT9 vp;					//ºäÆ÷Æ®, Ã¢ÀÇ Å©±â¸¦ Á¤ÇÔ
	GetClientRect(m_hWnd, &rect);

	vp.X = 0;
	vp.Y = 0;
	vp.Width = rect.right - rect.left;  // ÁÂÇ¥°³³äÀÌ ¾Æ´Ï¶ó Å©±â °³³ä 800, 600 °è»êµÊ
	vp.Height = rect.bottom - rect.top;
	vp.MinZ = 0.0f;
	vp.MaxZ = 1.0f;

	m_Eye.x = 10.0f;
	m_Eye.y = 10.0f;
	m_Eye.z = -15.0f;

	m_At.x = 0.0f;
	m_At.y = 0.0f;
	m_At.z = 0.0f;

	m_Up.x = 0.0f;
	m_Up.y = 1.0f;
	m_Up.z = 0.0f;

	D3DXMatrixLookAtLH(&m_matView, &m_Eye, &m_At, &m_Up);
	m_pd3dDevice->SetTransform(D3DTS_VIEW, &m_matView);

	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	m_pd3dDevice->SetTransform(D3DTS_PROJECTION, &m_matProj);
	m_pd3dDevice->SetViewport(&vp);

	m_Axis.OnInit(m_pd3dDevice);

	D3DXCreateTeapot( m_pd3dDevice, &m_pTeapotMesh, NULL );

	m_Ground.Create(m_pd3dDevice, 20, 20, 2.0f);
}

void GameCode::OnRender()
{
	D3DXMATRIX matRotationY, matWorld, matTrans, matScaling;
	float fScaling[3] = { 0.3f, 0.6f, 1.0f };
	D3DXVECTOR3 vTrans[3] = { D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(2.0f, 0.0f, 0.0f), D3DXVECTOR3(5.0f, 0.0f, 0.0f) };

	D3DXMatrixRotationY(&matRotationY, GetTickCount() * 0.004f);

	m_Axis.OnRender();

	m_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	D3DXMatrixRotationY(&matRotationY, GetTickCount() * 0.004f);

	D3DXMatrixScaling(&matScaling, fScaling[0], fScaling[0], fScaling[0]);
	D3DXMatrixTranslation(&matTrans, vTrans[0].x, vTrans[0].y, vTrans[0].z);
	matWorld = matScaling * matRotationY * matTrans;		//SRT
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_pTeapotMesh->DrawSubset(0);

	D3DXMatrixScaling(&matScaling, fScaling[1], fScaling[1], fScaling[1]);
	D3DXMatrixTranslation(&matTrans, vTrans[1].x, vTrans[1].y, vTrans[1].z);
	matWorld = matScaling * matRotationY * matTrans;		//SRT
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_pTeapotMesh->DrawSubset(0);

	D3DXMatrixScaling(&matScaling, fScaling[2], fScaling[2], fScaling[2]);
	D3DXMatrixTranslation(&matTrans, vTrans[2].x, vTrans[2].y, vTrans[2].z);
	matWorld = matScaling * matTrans * matRotationY;		//STR
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_pTeapotMesh->DrawSubset(0);

	m_Ground.OnRender();
}

void GameCode::OnUpdate()
{

}

void GameCode::OnRelease()
{
	m_pTeapotMesh->Release();
	m_Axis.OnRelease();
	m_Ground.OnRelease();
}