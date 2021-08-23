#include "pch.h"
#include "GenericDLLProj.h"

class TwoDimSimulationProject : public IProject
{
public:
	TwoDimSimulationProject();

	void release();

protected:
	int *TwoDimGrid; // might need to 
	int N;
	int gridArea;

	void nextStep(); // facilitates the main behavior of the Simulation

	int findIndex(int i, int j); // finds the 1D equivalent coordinate given 2D (i,j)
};

// Factory function which creates Project object
EXTERN_C PROJECTAPI PROJECTHANDLE WINAPI get_instance(VOID);

// functions 
EXTERN_C PROJECTAPI INT APIENTRY project_add_interaction(PROJECTHANDLE handle, INT n1, INT n2);

EXTERN_C PROJECTAPI VOID APIENTRY project_release(PROJECTHANDLE handle);