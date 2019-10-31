#pragma once
#include <d3d9.h>

class CAxis
{
private:
	LPDIRECT3DDEVICE9   m_pd3dDevice;
	LPDIRECT3DVERTEXBUFFER9 m_pVB;		//정점 버퍼

public:
	void OnInit(LPDIRECT3DDEVICE9 pd3dDevice);
	void OnRender();
	void OnRelease();

public:
	CAxis(void);
	~CAxis(void);
};

