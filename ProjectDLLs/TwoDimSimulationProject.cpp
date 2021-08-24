#include "pch.h"
#include "TwoDimSimulationProject.h"

template<typename T>
TwoDimSimulationProject<T>::TwoDimSimulationProject()
{
	
}

template<typename T> 
TwoDimSimulationProject<T>::~TwoDimSimulationProject()
{

}

template<typename T>
int TwoDimSimulationProject<T>::findIndex(int i, int j) 
{

}


template<typename T> 
T* TwoDimSimulationProject<T>::getGrid() 
{
	return displayedGrid;
}

template<typename T>
PROJECTAPI T* APIENTRY project_get_grid(PROJECTHANDLE handle) 
{
	if (handle) {
		handle->getGrid();
	}
}


template<typename T>
void TwoDimSimulationProject<T>::release()
{
	delete this;
}

template<typename T>
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

template<typename T>
PROJECTAPI PROJECTHANDLE APIENTRY get_instance()
{
	return new ProjectObj;
}
