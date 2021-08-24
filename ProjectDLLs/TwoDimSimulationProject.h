#include "pch.h"
#include "GenericDLLProj.h"

template<typename T>
class TwoDimSimulationProject : public IProject
{
public:
	void release();                      // call for destructor 
	T* getGrid();                        // gets the current state of the grid

protected:
	
	T* displayedGrid;  // this 2d grid is the grid that will be sent to the display
	int N;             // this is the side length of the grid
	int gridArea;      // this is the total number of squares in the grid 

	// functions that are the same accross 

	TwoDimSimulationProject();           // constructor
	~TwoDimSimulationProject();          // destructor 
	int findIndex(int i, int j);         // finds the 1D equivalent coordinate given 2D (i,j)

	// virtual functions that must be in each simulation but implemented seperatly

	virtual void nextStep() = 0;         // facilitates the main behavior of the Simulation
};

// Factory function which creates Project object
EXTERN_C PROJECTAPI PROJECTHANDLE WINAPI get_instance(VOID);

// export functions 
EXTERN_C PROJECTAPI VOID APIENTRY project_release(PROJECTHANDLE handle);

EXTERN_C PROJECTAPI T* APIENTRY project_get_grid(PROJECTHANDLE handle);