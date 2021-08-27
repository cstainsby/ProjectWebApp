#pragma once
#include "pch.h"
#include "IDLLProject.h"

template<typename subclass, typename T>
class DLLTwoDimSimulationFacade : IDLLProject<subclass, float> 
{
	void init(std::string projectName);                              // initializes the project
	void update();                                                   // updates the project state
	float* getProjectState();                                        // gets an array to be displayed in the view
	void setView(std::string viewName);                              // sets the view to a given type
	void setSetting(std::string settingName, float value);           // changes the value of a given setting
	void interact(std:string inputType, int xCord, int yCord);       // take input type and coordinates and decides how to handle the request
	void release();                                                  // frees the project from memory when finished
};

// Factory function which creates Project object
EXTERN_C PROJECTAPI PROJECTHANDLE<FLOAT> WINAPI get_instance(VOID);

// export functions 
EXTERN_C PROJECTAPI VOID APIENTRY project_init(PROJECTHANDLE<FLOAT> handle);
EXTERN_C PROJECTAPI VOID APIENTRY project_update(PROJECTHANDLE<FLOAT> handle);
EXTERN_C PROJECTAPI FLOAT* APIENTRY project_get_project_state(PROJECTHANDLE<FLOAT> handle);
EXTERN_C PROJECTAPI VOID APIENTRY project_set_view(PROJECTHANDLE<FLOAT> handle, CHAR* viewName);
EXTERN_C PROJECTAPI VOID APIENTRY project_set_setting(PROJECTHANDLE<FLOAT> handle, CHAR* settingName, FLOAT value);
EXTERN_C PROJECTAPI VOID APIENTRY project_interact(PROJECTHANDLE<FLOAT> handle, CHAR* inputType, INT xCord, INT yCord);
EXTERN_C PROJECTAPI VOID APIENTRY project_release(PROJECTHANDLE<FLOAT> handle);