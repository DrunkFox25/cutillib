#ifndef COLORTABLE_H_INCLUDED
#define COLORTABLE_H_INCLUDED


#include "resouces.h"

#define COLOR_HEX uint


//extern turns definition into declaration
//static makes linker ingnore def/dec


#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

void DLL_EXPORT get_color(const char* name, COLOR_HEX &color);

int DLL_EXPORT loadColorTable(const char* path);

#ifdef __cplusplus
}
#endif

#endif // COLORTABLE_H_INCLUDED
