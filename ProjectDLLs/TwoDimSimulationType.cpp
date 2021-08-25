#include "pch.h"
#include "TwoDimSimulationProject.h"

// DVC
TwoDimSimulationProject::TwoDimSimulationProject()
{
	
}

// Destructor
TwoDimSimulationProject::~TwoDimSimulationProject()
{

}

// helper function that finds the 1D equivalent coordinate given 2D (i,j)
int TwoDimSimulationProject::findIndex(int i, int j) 
{

}

void TwoDimSimulationProject::init() 
{

}

PROJECTAPI VOID APIENTRY project_init(PROJECTHANDLE<FLOAT> handle) 
{
	if (handle) {
		handle->init();
	}
}

float* TwoDimSimulationProject::getProjectState() 
{
	return displayedGrid;
}

PROJECTAPI FLOAT* APIENTRY project_get_project_state(PROJECTHANDLE<FLOAT> handle) 
{
	if (handle) {
		handle->getProjectState();
	}
}


void TwoDimSimulationProject::release()
{
	delete this;
}

PROJECTAPI VOID APIENTRY project_release(PROJECTHANDLE<FLOAT> handle)
{
	if (handle) {
		handle->release();
	}
}

// Factory function for the object
#if !defined(_WIN64)
#pragma comment(linker, "/export:GetInstance=_GetInstance@0")
#endif //_WIN64

PROJECTAPI PROJECTHANDLE<FLOAT> APIENTRY get_instance()
{
	return new ProjectObj;
}
