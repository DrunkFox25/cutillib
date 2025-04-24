#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include "resouces.h"
#include <windows.h>

#define WINDOW_STYLE uint// can be stored in a short
#define WINDOW_EXSTYLE uint
#define WINDOW_CLASS_STYLE DWORD


#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif



enum windowstyle{
	mabox = 16,//maxbox
	mibox,//minbox
	sizbo,//sizebox
	sysme,//system menu
	hscrl,//horizontal scroll
	vscrl,//vertical scroll
	frame,
	bordr,//border
	maxim,//maximized
	clchi,//clip children
	clsib,//clip siplings
	disab,//disables
	visib,//visible
	minim,//minimized
	child,
	popup,
};//frame + border = caption

enum windowexstyle{
	dlgmf,//double sized border
	void1,//
	nomsg,//The child window created with this style does not send the WM_PARENTNOTIFY message to its parent window when it is created or destroyed.
	top00,//perma topmost
	files,//drag and drop
	stran,//semitransperent
	mdich,//The window is a MDI child window.
	tools,//floating tool window
	redge,//raised edge
	sedge,//sunken edge
	cxthl,//Includes a question mark. When the user clicks the question mark, enter ? mode => clicks a child window it gets WM_HELP message. Cannot be used with the MIN/MAXBOX
	void2,
	right,//The window has generic "right-aligned" properties. ~= use 12,13 at once
	rtl00,//If the shell language is Hebrew, Arabic, or another language that supports reading-order alignment, the window text is displayed using right-to-left reading-order properties. For other languages, the style is ignored.
	lscrl,//If the shell language is Hebrew, Arabic, or another language that supports reading order alignment, the vertical scroll bar (if present) is to the left of the client area. For other languages, the style is ignored.
	void3,
	ctrlp,//The window itself contains child windows that should take part in dialog box navigation. If this style is specified, the dialog manager recurses into children of this window when performing navigation operations such as handling the TAB key, an arrow key, or a keyboard mnemonic.
	statc,//static edge: the window has a three-dimensional border style intended to be used for items that do not accept user input.
	app00,//Forces taskbar
	layer,//layered window. exclusive with CS_OWNDC, CS_CLASSDC. Windows 8: The WS_EX_LAYERED style is supported for top-level windows and child windows. Previous Windows versions support WS_EX_LAYERED only for top-level windows.
	nolay,//The window does not pass its window layout to its child windows.
	ndrbm,//The window does not render to a redirection surface. This is for windows that do not have visible content or that use mechanisms other than surfaces to provide their visual.
	rtlfl,//If the shell language is Hebrew, Arabic, or another language that supports reading order alignment, the horizontal origin of the window is on the right edge. Increasing horizontal values advance to the left.
	cmpos,//Paints all descendants of a window in bottom-to-top painting order using double-buffering. Bottom-to-top painting order allows a descendent window to have translucency (alpha) and transparency (color-key) effects, but only if the descendent window also has the WS_EX_TRANSPARENT bit set. Double-buffering allows the window and its descendents to be painted without flicker. This cannot be used if the window has a class style of either CS_OWNDC or CS_CLASSDC. This style is not by windows 2000
	void4,
	noact,//shouldn't/can't be activated by user. To activate the window, use the SetActiveWindow or SetForegroundWindow function. No def taskbar -> To force taskbar, use the app00.
};





struct DLL_EXPORT Screen{
	short x, y;
	int memsize;
	uint* mem;

	BITMAPINFO bmi;

private:
	BITMAPINFOHEADER *bmiHeader = &bmi.bmiHeader;
public:

	void DLL_EXPORT reSize(short X, short Y);


	void DLL_EXPORT render(HDC hdc);


	void DLL_EXPORT reSize(DWORD rs);


	void DLL_EXPORT operator()(short X, short Y);


	DLL_EXPORT Screen(short X, short Y);


	DLL_EXPORT ~Screen();
};






#endif // SCREEN_H_INCLUDED

