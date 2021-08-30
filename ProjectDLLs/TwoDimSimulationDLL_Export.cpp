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

PROJECTAPI VOID APIENTRY project_update(PROJECTHANDLE<FLOAT> handle) 
{
	if (handle) {
		handle->update();
	}
}

PROJECTAPI FLOAT* APIENTRY project_get_view(PROJECTHANDLE<FLOAT> handle, CHAR* viewName)
{
	if (handle) {
		return handle->getView(viewName);
	}
	else {
		return NULL;
	}
}

PROJECTAPI VOID APIENTRY project_set_setting(PROJECTHANDLE<FLOAT> handle, CHAR* settingName, FLOAT value)
{
	if (handle) {
		handle->setSetting(settingName, value);
	}
}

PROJECTAPI VOID APIENTRY project_interact(PROJECTHANDLE<FLOAT> handle, CHAR* inputType, INT xCord, INT yCord)
{
	if (handle) {
		handle->interact(inputType, xCord, yCord);
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