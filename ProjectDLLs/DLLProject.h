#pragma once
#include "pch.h"
#include "IDLLProject.h"

template<typename subclass, typename T>
class DLLProject : IDLLProject<subclass, T> 
{
	// virtual functions that must be in each simulation but implemented seperatly
	void init(std::string);                      // initiliazes project to a set state
	float* getProjectState();                    // returns displayed grid
	virtual void release();                      // call for destructor
	virtual void nextStep();                     // facilitates the main behavior of the Simulation
};

// Factory function which creates Project object
EXTERN_C PROJECTAPI PROJECTHANDLE<FLOAT> WINAPI get_instance(VOID);

// export functions 
EXTERN_C PROJECTAPI VOID APIENTRY project_init(PROJECTHANDLE<FLOAT> handle);

EXTERN_C PROJECTAPI VOID APIENTRY project_release(PROJECTHANDLE<FLOAT> handle);

EXTERN_C PROJECTAPI VOID APIENTRY project_next_step(PROJECTHANDLE<FLOAT> handle);

EXTERN_C PROJECTAPI FLOAT* APIENTRY project_get_project_state(PROJECTHANDLE<FLOAT> handle);