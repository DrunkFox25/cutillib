#include <fstream>
#include <cstdio>


#include "colortable.h"
//
using namespace std;




hash_map<string, COLOR_HEX> ColorTable;
static bool initColorTable = false;


COLOR_HEX DLL_EXPORT getColor(const char* name){
	return ColorTable[(string)name];
}

int DLL_EXPORT loadColorTable(const char* path){
	if(initColorTable){
		return 0;
	}



	ifstream colorfile(path);


	if(!colorfile.is_open()){
		if(DEBUG){

            puts("unable to open colorfile");
			throw("unable to open colorfile");
		}
		return -1;
	}


	string name;
	while(colorfile >> name){
		colorfile >> std::hex >> ColorTable[name];
	}
	colorfile.close();

	initColorTable = true;

	return 0;
}


