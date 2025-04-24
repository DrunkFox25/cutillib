#ifndef OUTSRCSTRING_H_INCLUDED
#define OUTSRCSTRING_H_INCLUDED


#include <cstdio>
#include <windows.h>

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif



#ifdef __cplusplus
extern "C"
{
#endif

char* DLL_EXPORT PLUS(const char* lhs, const char* rhs);



int DLL_EXPORT filesize(FILE* f);




struct DLL_EXPORT outsourcedcstylestring{

private:
	FILE* f;

public:
	char *buff;
	//const char *shit = (const char*)("it do be doin dat tho");
	const char *filename;
	int fcharstart = -1, fcharstop = -1, bufflen = 0, flen = 0;

	bool readfile = true;

	bool sourceactive = false;

	int DLL_EXPORT read_file();

	int DLL_EXPORT read();

	void DLL_EXPORT alloc_buff();

	void DLL_EXPORT get_endpoints();

	void DLL_EXPORT actual_read();

	int DLL_EXPORT openf();
};




#ifdef __cplusplus
}
#endif










#endif // OUTSRCSTRING_H_INCLUDED

