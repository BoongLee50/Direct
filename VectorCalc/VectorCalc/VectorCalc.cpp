#include "stdafx.h"
#include <d3dx9math.h>

int _tmain(int argc, _TCHAR* argv[])
{
	/*D3DXVECTOR3 v1(0.f, 3.0f, 0.0f);
	D3DXVECTOR3 v2(3.0f, 0.0f, 0.0f);
	D3DXVECTOR3 v3;
	D3DXVECTOR3 v4(3.0f, 4.0f, 0.0f);
	float fLength;*/

	//// 벡터의 합
	//v3 = v1 + v2;
	//printf( "합 : %f %f %f \n",  v3.x, v3.y, v3.z );

	//D3DXVec3Add( &v3, &v1, &v2 );
	//printf( "합 : %f %f %f \n",  v3.x, v3.y, v3.z );

	// 벡터의 뺄셈
	/*v3 = v1 - v2;

	printf( "뺄셈 : %f %f %f \n",  v3.x, v3.y, v3.z );

	D3DXVec3Subtract( &v3, &v1, &v2 );
	printf( "뺄셈 : %f %f %f \n",  v3.x, v3.y, v3.z );*/

	// 크기 
	//fLength = D3DXVec3Length( &v4 );
	//printf( "크기 : %f \n", fLength );

	// 벡터의 크기 변환 
	/*float fScale = 2.0f;
	D3DXVECTOR3 v5( 2.0f, 1.0f, 0.0f );

	D3DXVec3Scale( &v5, &v5, fScale );
	printf( "값과 벡터의 곱 : %f %f %f \n", v5.x, v5.y, v5.z );*/

	// 벡터의 단위벡터
	/*D3DXVECTOR3 v6(2.0f, 2.0f, 3.0f);
	D3DXVECTOR3 vResult;
	float fNormalize;

	D3DXVec3Normalize(&vResult, &v6);
	printf("단위벡터 : %f %f %f \n", vResult.x, vResult.y, vResult.z);
	fNormalize = D3DXVec3Length(&vResult);
	printf("크기 : %f \n", fNormalize);*/

	// 내적을 이용하여 사이각을 알아내는 부분
	/*D3DXVECTOR3 v7(3.0f, 0.0f, 0.0f);
	D3DXVECTOR3 v8(-3.0f, 0.0f, 0.0f);
	float fCos, fDot, fScale;

	fDot = D3DXVec3Dot(&v7, &v8);
	fScale = D3DXVec3Length(&v7) * D3DXVec3Length(&v8);
	fCos = fDot / fScale;
	printf("라디안 : %f \n", fCos);*/

	// 외적을 이용하여 법선벡터를 알아냄
	D3DXVECTOR3 v9(3.0f, 0.0f, 0.0f);
	D3DXVECTOR3 v10(0.0f, 3.0f, 0.0f);
	D3DXVECTOR3 vResult;

	D3DXVec3Cross(&vResult, &v9, &v10);
	D3DXVec3Normalize(&vResult, &vResult);
	printf("%f %f %f \n", vResult.x, vResult.y, vResult.z);

	return 0;
}

