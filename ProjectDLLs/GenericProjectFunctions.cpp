#include "pch.h"
#include "GenericProjectFunctions.h"

int ProjectObj::add(int n1, int n2)
{
	return n1 + n2;
}

PROJECTAPI INT APIENTRY project_add(PROJECTHANDLE handle, INT n1, INT n2)
{
	int nResult = -1;

	if (handle) {
		nResult = handle->add(n1, n2);
	}

	return nResult;
}

void ProjectObj::release()
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

// regular c++ object implementation
int CProject::add(int n1, int n2)
{
	return n1 + n2;
}
