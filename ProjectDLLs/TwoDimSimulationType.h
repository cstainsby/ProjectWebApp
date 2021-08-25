#include "pch.h"
#include "GenericDLLProj.h"

// define T as a float in the simulation project
class TwoDimSimulationType : public IProject<float>
{
public:

	// virtual functions that must be in each simulation but implemented seperatly
	virtual void init() = 0;                         // initiliazes project to a set state
	virtual float* getProjectState() = 0;            // returns displayed grid
	virtual void release() = 0;                      // call for destructor
	virtual void nextStep() = 0;                     // facilitates the main behavior of the Simulation

protected:
	// member attributes each 2D simulation should have
	int N;             // this is the side length of the grid
	int gridArea;      // this is the total number of squares in the grid 

	// functions that are the same accross 
	int findIndex(int i, int j) const;         // finds the 1D equivalent coordinate given 2D (i,j)
};