#include "pch.h"

// setup macros for exporting to dll easier
#ifndef PROJECT_EXPORTS
#define PROJECTAPI __declspec(dllexport)
#else
#define PROJECTAPI __declspec(dllimport)
#endif

#ifdef __cplusplus
template<typename T>
struct IDLLProject
{
	// virtual functions that will be used in every project and will be exported to c# program
	virtual void init(std::string projectName) = 0;                              // initializes the project
	virtual void update() = 0;
	virtual T* getView(std::string viewName) = 0;                                // gets an array to be displayed in the view
	virtual void setSetting(std::string settingName, T value) = 0;               // changes the value of a given setting
	virtual void interact(std::string inputType, int xCord, int yCord) = 0;       // take input type and coordinates and decides how to handle the request
	virtual void release() = 0;                                                  // frees the project from memory when finished
};

// alias template for project handle
// a good reference -> https://www.nextptr.com/tutorial/ta1193988140/how-cplusplus-using-or-aliasdeclaration-is-better-than-typedef
template<typename T>
using PROJECTHANDLE = IDLLProject<T>*;
#else 
typedef struct tagPROJECTHANDLE {} * PROJECTHANDLE;
#endif //__cplusplus


// define macro for extern "C"
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else 
#define EXTERN_C
#endif // !__cplusplus
