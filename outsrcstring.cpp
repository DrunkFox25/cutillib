
#include "outsrcstring.h"



extern "C"{


char* DLL_EXPORT PLUS(const char* lhs, const char* rhs){
    auto sum = (char*)malloc(sizeof(char)*(strlen(rhs)+strlen(lhs)+1));
    sum[0] = 0;
    strcat(sum, lhs);
    strcat(sum, rhs);

    return sum;
}

}





int DLL_EXPORT filesize(FILE* f){
	fseek(f, 0, SEEK_END);
	return ftell(f)+1;
}

int DLL_EXPORT outsourcedcstylestring::read_file(){

	if(openf() == -1) return(fprintf(stderr, "FNF err:: File Not Found!: %s:\n", filename));
	get_endpoints();
	actual_read();

	return 0;
}

int DLL_EXPORT outsourcedcstylestring::read(){

	if(readfile) return read_file();// outsourcing

	return 0;
}

void DLL_EXPORT outsourcedcstylestring::get_endpoints(){
	if(fcharstart == -1) fcharstart = 0;
	if(fcharstop == -1) fcharstop = flen;

	bufflen = fcharstop - fcharstart;

	return;
}

void DLL_EXPORT outsourcedcstylestring::actual_read(){

    buff = (char*)malloc(sizeof(char)*(bufflen+1));
    buff[bufflen] = 0;

	sourceactive = true;

	fseek(f, fcharstart, SEEK_SET);

	int out = fread(buff, 1, bufflen, f);

	/*
	if(out != bufflen){
        fprintf(stderr, "Only %d bytes can be read of file %s of size %d bytes", out, filename, filesize(f));
        #ifdef DEBUG
            throw("potato & gpu");
        #endif // DEBUG
	}
	*/

	fclose(f);

	return;
}

int DLL_EXPORT outsourcedcstylestring::openf(){
	f = fopen(filename, "r");

	if(f == NULL) return -1;

	flen = filesize(f);

	return 0;
}














