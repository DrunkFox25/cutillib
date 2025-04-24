#ifndef RESOUCES_H_INCLUDED
#define RESOUCES_H_INCLUDED





#define mystdlib
#define def_unicode

#define debug

#define types_4_me
#define hash_types
#define abrev_types

#define basic_types




#ifdef def_unicode
	#if defined(UNICODE) && !defined(_UNICODE)
		#define _UNICODE
	#elif defined(_UNICODE) && !defined(UNICODE)
		#define UNICODE
	#endif

	#ifdef _MSC_VER
	#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
	#endif
#endif//def_unicode



#ifdef mystdlib
	#include <tchar.h>
	#include <windows.h>
	#include <thread>
	#include <chrono>
	#include <functional>
	#include <cstdio>
	#include <fstream>
	#include <iostream>
	#include <math.h>
	//#include <>
#endif // mystdlib



#ifdef debug
	#define DEBUG true
#endif



#ifdef types_4_me

    #include <string>
    #include <array>
    #include <map>
    #include <set>
    #include <vector>
    #include <unordered_map>
    #include <unordered_set>
    #include <queue>
    //#include <priority_queue> it is in queue

    #ifdef hash_types
        #define hash_map std::unordered_map
        #define hash_set std::unordered_set
        #define pqueue std::priority_queue
    #endif

    #ifdef abrev_types
        #define uchar unsigned char
        #define ushort unsigned short
        #define ulong unsigned long
        #define uint unsigned int
        #define ull unsigned long long
    #endif

#endif //types_4_me








#endif // RESOUCES_H_INCLUDED
