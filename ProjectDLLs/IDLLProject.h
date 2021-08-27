// setup macros for exporting to dll easier
#ifndef PROJECT_EXPORTS
#define PROJECTAPI __declspec(dllexport)
#else
#define PROJECTAPI __declspec(dllimport)
#endif

#ifdef __cplusplus
template<typename subclass, typename T>
struct IDLLProject
{
	// function lists for settings and views
	typedef void (subclass::*settingSetterFunc)(T);
	ArrayListCollection<std::string, settingSetterFunc> settingInteractionList;   // kv list, key: string identifier, value: setting setter functions relating to string

	typedef void (subclass::*viewReturnFunc)(T*&);
	ArrayListCollection<std::string, viewReturnFunc> viewInteractionList;  // kv list, key: string identifier, value: view getter functions relating to string

	virtual void init() = 0;                                                     // initializes the project
	virtual T* getProjectState() = 0;                                            // gets an array to be displayed in the view
	virtual void setView(std::string viewName) = 0;                              // sets the view to 
	virtual void setSetting(std::string settingName, T value) = 0;               // changes the value of a given setting
	virtual void interact(std:string inputType, int xCord, int yCord) = 0;       // take input type and coordinates and decides how to handle the request
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
