#ifndef SYSTEMS_H_INCLUDED
#define SYSTEMS_H_INCLUDED

#include "resouces.h"
#include <windows.h>

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif



typedef void* dataptr;

typedef std::pair<int /*msgcode*/, dataptr /*msgptr*/> message;

typedef std::pair<uint /*target id*/, message /*message*/> calltype;// target id, message








namespace sys{

	struct DLL_EXPORT sysglobals{
		std::queue<calltype> sys_q;
		std::queue<message /*err*/> errq;
		std::queue<int /*exitcode*/> exitq;
		std::vector<dataptr> data;
		dataptr globaldata;
	};

	typedef int (*proctype)(sys::sysglobals* /*app_gptr*/);



	struct DLL_EXPORT system{

	private:
		sysglobals systemGlobals;
	public:

		sysglobals* sysg;

		uint nprocs = 0;
		uint nelements = 0;

		std::vector<proctype> procs;//proc_id -> proc
		std::vector<uint /*proc_id*/> procid;//element_id -> proc_id

		DLL_EXPORT system();

		DLL_EXPORT ~system();

		void DLL_EXPORT initsysgptr();

		bool DLL_EXPORT run_next();

		int DLL_EXPORT add_call(calltype call);

		int DLL_EXPORT add_tcall(uint target, message msg);

		int DLL_EXPORT brodcast_call(std::vector<uint> targets, message msg);

		int DLL_EXPORT add_proc(std::string name, proctype proc);

		int DLL_EXPORT add_element(std::string name, uint proc_id);

		int DLL_EXPORT set_element_data(uint id, dataptr ptr);
	};

}


#endif // SYSTEMS_H_INCLUDED
