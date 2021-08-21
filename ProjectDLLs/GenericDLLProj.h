// setup macros for exporting to dll easier
#ifdef GAMEOFLIFE_EXPORTS
#define GAMEOFLIFEAPI __declspec(dllimport)
#else
#define GAMEOFLIFEAPI __declspec(dllexport)
#endif

#ifdef __cplusplus	
struct IGameOfLife
{
	virtual int add(int n1, int n2) = 0;
	virtual void release() = 0;
};

class GAMEOFLIFEAPI CGameOfLife
{
public:
	int add(int, int);
};

typedef IGameOfLife* GAMEOFLIFEHANDLE;
#else 
typedef struct tagGAMEOFLIFEHANDLE {} *GAMEOFLIFEHANDLE;
#endif //__cplusplus

// define macro for extern "C"
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else 
#define EXTERN_C
#endif // !__cplusplus

// Factory function which creates GameOfLife object
EXTERN_C GAMEOFLIFEAPI GAMEOFLIFEHANDLE WINAPI GetInstance(VOID);

// functions 
EXTERN_C GAMEOFLIFEAPI INT APIENTRY GameOfLifeadd(GAMEOFLIFEHANDLE handle, INT n1, INT n2);

EXTERN_C GAMEOFLIFEAPI VOID APIENTRY GameOfLiferelease(GAMEOFLIFEHANDLE handle);
