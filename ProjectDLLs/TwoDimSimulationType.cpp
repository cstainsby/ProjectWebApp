#include "pch.h"
#include "TwoDimSimulationType.h"


// helper function that finds the 1D equivalent coordinate given 2D (i,j)
int TwoDimSimulationType::findIndex(int i, int j) const
{
	return ((N+2)*j)+i;
}

// ---------- exported functions -----------
// initializes the project in a given format based on inputs
void TwoDimSimulationType::init() 
{

}

PROJECTAPI VOID APIENTRY project_init(PROJECTHANDLE<FLOAT> handle) 
{
	if (handle) {
		handle->init();
	}
}

float* TwoDimSimulationType::getProjectState() 
{
	return displayedGrid;
}

PROJECTAPI FLOAT* APIENTRY project_get_project_state(PROJECTHANDLE<FLOAT> handle) 
{
	if (handle) {
		handle->getProjectState();
	}
}


void TwoDimSimulationType::release()
{
	delete this;
}

PROJECTAPI VOID APIENTRY project_release(PROJECTHANDLE<FLOAT> handle)
{
	if (handle) {
		handle->release();
	}
}

