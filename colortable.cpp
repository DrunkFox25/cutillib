#include <fstream>
#include <cstdio>


#include "colortable.h"
//
using namespace std;




hash_map<string, COLOR_HEX> ColorTable;
static bool initColorTable = false;


void DLL_EXPORT get_color(const char* name, COLOR_HEX &color){
	color = ColorTable[(string)name];
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


