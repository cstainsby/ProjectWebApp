#include "pch.h"


class TwoDimSimulationType 
{
public:
	TwoDimSimulationType() { this->N = 0, this->gridArea = 0; };
protected:
	// member attributes each 2D simulation should have
	int N;             // this is the side length of the grid
	int gridArea;      // this is the total number of squares in the grid 
	
	// functions that are the same accross 
	int findIndex(int i, int j) const;         // finds the 1D equivalent coordinate given 2D (i,j)
};
