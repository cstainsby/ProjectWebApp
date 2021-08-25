#include "pch.h"
#include "GenericDLLProj.h"

// define T as a float in the simulation project
class TwoDimSimulationType : public IProject<float>
{
public:
	void init();                         // initiliazes project to a set state
	float* getProjectState();            // returns displayed grid
	void release();                      // call for destructor

	// virtual functions that must be in each simulation but implemented seperatly
	virtual void run() = 0;              // runs the main simulation
	virtual void nextStep() = 0;         // facilitates the main behavior of the Simulation

protected:
	
	float* displayedGrid;  // this 2d grid is the grid that will be sent to the display
	int N;             // this is the side length of the grid
	int gridArea;      // this is the total number of squares in the grid 

	// functions that are the same accross 
	int findIndex(int i, int j);         // finds the 1D equivalent coordinate given 2D (i,j)
};

// Factory function which creates Project object
EXTERN_C PROJECTAPI PROJECTHANDLE<FLOAT> WINAPI get_instance(VOID);

// export functions 
EXTERN_C PROJECTAPI VOID APIENTRY project_init(PROJECTHANDLE<FLOAT> handle);

EXTERN_C PROJECTAPI VOID APIENTRY project_release(PROJECTHANDLE<FLOAT> handle);

EXTERN_C PROJECTAPI FLOAT* APIENTRY project_get_project_state(PROJECTHANDLE<FLOAT> handle);