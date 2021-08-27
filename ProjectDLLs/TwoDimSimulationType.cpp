#include "pch.h"
#include "TwoDimSimulationType.h"


// helper function that finds the 1D equivalent coordinate given 2D (i,j)
int TwoDimSimulationType::findIndex(int i, int j) const
{
	return ((N+2)*j)+i;
}

// ---------- exported functions -----------
// initializes the project in a given format based on inputs
void TwoDimSimulationType::init() 
{

}



void TwoDimSimulationType::release()
{
	delete this;
}



