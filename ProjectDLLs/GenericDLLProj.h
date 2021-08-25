// setup macros for exporting to dll easier
#ifndef PROJECT_EXPORTS
#define PROJECTAPI __declspec(dllexport)
#else
#define PROJECTAPI __declspec(dllimport)
#endif

#ifdef __cplusplus
template<typename T>
struct IProject
{
	virtual void init() = 0;
	virtual T* getProjectState() = 0;
	virtual void release() = 0;
};

// alias template for project handle
// a good reference -> https://www.nextptr.com/tutorial/ta1193988140/how-cplusplus-using-or-aliasdeclaration-is-better-than-typedef
template<typename T>
using PROJECTHANDLE = IProject<T>*;
#else 
typedef struct tagPROJECTHANDLE {} * PROJECTHANDLE;
#endif //__cplusplus


// define macro for extern "C"
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else 
#define EXTERN_C
#endif // !__cplusplus
