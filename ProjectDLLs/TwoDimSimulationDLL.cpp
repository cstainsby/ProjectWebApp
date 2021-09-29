#include "TwoDimSimulationDLL.h"

// initializes the project
void TwoDimSimulationDLL::init(std::string projectName)
{
	TwoDimSimulationFactory factory;

	this->projectWrapper = factory.makeTwoDimSimulationObj(projectName);
}

// gets an array to be displayed in the view
float* TwoDimSimulationDLL::getView(std::string viewName)
{
	float* display;

	this->projectWrapper->getView(viewName, display);

	return display;
}

// changes the value of a given setting
void TwoDimSimulationDLL::setSetting(std::string settingName, float value)
{
	this->projectWrapper->setSetting(settingName, value);
}

// take input type and coordinates and decides how to handle the request
void TwoDimSimulationDLL::interact(std::string inputType, int xCord, int yCord)
{
	this->projectWrapper->interact(inputType, xCord, yCord);
}

// updates the project state
void TwoDimSimulationDLL::update()
{
	this->projectWrapper->update();
}

// delete all on memory items in object
void TwoDimSimulationDLL::release()
{
	delete projectWrapper;
}

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
	return new TwoDimSimulationDLL;
}