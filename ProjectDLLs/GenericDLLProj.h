// setup macros for exporting to dll easier
#ifndef PROJECT_EXPORTS
#define PROJECTAPI __declspec(dllexport)
#else
#define PROJECTAPI __declspec(dllimport)
#endif

#ifdef __cplusplus	
struct IProject
{
	virtual int add(int n1, int n2) = 0;
	virtual void release() = 0;
};

class PROJECTAPI CProject
{
public:
	int add(int, int);
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

// Factory function which creates GameOfLife object
EXTERN_C PROJECTAPI PROJECTHANDLE WINAPI get_instance(VOID);

// functions 
EXTERN_C PROJECTAPI INT APIENTRY project_add(PROJECTHANDLE handle, INT n1, INT n2);

EXTERN_C PROJECTAPI VOID APIENTRY project_release(PROJECTHANDLE handle);
