#include "pch.h"
#include "TwoDimSimulationType.h"


// helper function that finds the 1D equivalent coordinate given 2D (i,j)
int TwoDimSimulationType::findIndex(int i, int j) const
{
	return ((N+2)*j)+i;
}


