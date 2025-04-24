#include "systems.h"


int run(sys::proctype &proc, sys::sysglobals* sysg){
	return (*proc)(sysg);
}



DLL_EXPORT sys::system::system(){
	sysg = &systemGlobals;
}

DLL_EXPORT sys::system::~system(){
	sysg = NULL;
}

void DLL_EXPORT sys::system::initsysgptr(){
	sysg = &systemGlobals;
	return;
}

bool DLL_EXPORT sys::system::run_next(){
	if(sysg->sys_q.empty()){
		return -1;
	}

	calltype call = sysg->sys_q.front();
	uint target_id = call.first;
	uint proc_id = procid[target_id];
	sys::proctype proc = procs[proc_id];

	int exitcode = run(proc, sysg);

	//app_g.exitq.push(exitcode);

	sysg->sys_q.pop();

	return 0;
}

int DLL_EXPORT sys::system::add_call(calltype call){
	sysg->sys_q.push(call);
	return 0;
}

int DLL_EXPORT sys::system::add_tcall(uint target, message msg){
	sysg->sys_q.push(calltype {target, msg});
	return 0;
}

int DLL_EXPORT sys::system::brodcast_call(std::vector<uint> targets, message msg){
	for(uint target : targets) sysg->sys_q.push(calltype {target, msg});
	return 0;
}

int DLL_EXPORT sys::system::add_proc(std::string name, sys::proctype proc){
	procs.push_back(proc);
	return nprocs++;
}

int DLL_EXPORT sys::system::add_element(std::string name, uint proc_id){
	sysg->data.push_back(nullptr);
	procid.push_back(proc_id);
	return nelements++;
}

int DLL_EXPORT sys::system::set_element_data(uint id, dataptr ptr){
	sysg->data[id] = ptr;
	return 0;
}




