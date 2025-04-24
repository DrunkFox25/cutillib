#include "screen.h"


void DLL_EXPORT Screen::reSize(short X, short Y){
	x = X;
	y = Y;
	memsize = ((int)X)*((int)Y);

	bmiHeader->biWidth = X;
	bmiHeader->biHeight = Y;

	if(mem) free(mem);
	mem = (uint*) malloc(sizeof(uint)*memsize);



	return;
}


void DLL_EXPORT Screen::render(HDC hdc){
	StretchDIBits(hdc, 0, 0, x, y, 0, 0, x, y, mem, &bmi, DIB_RGB_COLORS, SRCCOPY);
}


void DLL_EXPORT Screen::reSize(DWORD rs){reSize(LOWORD(rs), HIWORD(rs));}


void DLL_EXPORT Screen::operator()(short X, short Y){reSize(X, Y);}


DLL_EXPORT Screen::Screen(short X, short Y){

	bmiHeader->biSize = sizeof(bmiHeader);
	bmiHeader->biPlanes = 1;
	bmiHeader->biBitCount = 32;
	bmiHeader->biCompression = BI_RGB;

	reSize(X, Y);
}


DLL_EXPORT Screen::~Screen(){
	reSize(0, 0);

	bmiHeader = NULL;
	mem = NULL;
#include "scooby.h"


