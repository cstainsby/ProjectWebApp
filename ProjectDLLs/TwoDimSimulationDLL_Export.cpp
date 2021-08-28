#include "TwoDimSimulationDLL.h"

// export functions 
PROJECTAPI VOID APIENTRY project_init(PROJECTHANDLE<FLOAT> handle, CHAR* projectName)
{
	if (handle) {
		handle->init(projectName);
	}
}

PROJECTAPI VOID APIENTRY project_release(PROJECTHANDLE<FLOAT> handle)
{
	if (handle) {
		handle->release();
	}
}

EXTERN_C PROJECTAPI VOID APIENTRY project_next_step(PROJECTHANDLE<FLOAT> handle);

PROJECTAPI FLOAT* APIENTRY project_get_project_state(PROJECTHANDLE<FLOAT> handle)
{
	if (handle) {
		handle->getProjectState();
	}
}


// Factory function for the object
#if !defined(_WIN64)
#pragma comment(linker, "/export:GetInstance=_GetInstance@0")
#endif //_WIN64

PROJECTAPI PROJECTHANDLE<FLOAT> APIENTRY get_instance()
{
	return new TwoDimSimulation_Fluid;
}