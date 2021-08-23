#include "pch.h"
#include "TwoDimSimulationProject.h"


TwoDimSimulationProject::TwoDimSimulationProject()
{
	
}

PROJECTAPI INT APIENTRY project_add_interaction(PROJECTHANDLE handle, INT n1, INT n2)
{
	int nResult = -1;

	if (handle) {
		nResult = handle->add(n1, n2);
	}

	return nResult;
}

void TwoDimSimulationProject::release()
{

	delete this;
}

PROJECTAPI VOID APIENTRY project_release(PROJECTHANDLE handle)
{
	if (handle) {
		handle->release();
	}
}

// Factory function for the object
#if !defined(_WIN64)
#pragma comment(linker, "/export:GetInstance=_GetInstance@0")
#endif //_WIN64

PROJECTAPI PROJECTHANDLE APIENTRY get_instance()
{
	return new ProjectObj;
}
