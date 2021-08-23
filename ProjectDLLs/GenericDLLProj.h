// setup macros for exporting to dll easier
#ifndef PROJECT_EXPORTS
#define PROJECTAPI __declspec(dllexport)
#else
#define PROJECTAPI __declspec(dllimport)
#endif

#ifdef __cplusplus	
struct IProject
{
	virtual void init() = 0;
	virtual void release() = 0;
};

typedef IProject* PROJECTHANDLE;
#else 
typedef struct tagPROJECTHANDLE {} * PROJECTHANDLE;
#endif //__cplusplus

// define macro for extern "C"
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else 
#define EXTERN_C
#endif // !__cplusplus
