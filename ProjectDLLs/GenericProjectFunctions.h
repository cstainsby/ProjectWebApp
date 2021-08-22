#include "pch.h"
#include "GenericDLLProj.h"

class ProjectObj : public IProject
{
public:
	int add(int n1, int n2);
	void release();
};

// Factory function which creates GameOfLife object
EXTERN_C PROJECTAPI PROJECTHANDLE WINAPI get_instance(VOID);

// functions 
EXTERN_C PROJECTAPI INT APIENTRY project_add(PROJECTHANDLE handle, INT n1, INT n2);

EXTERN_C PROJECTAPI VOID APIENTRY project_release(PROJECTHANDLE handle);