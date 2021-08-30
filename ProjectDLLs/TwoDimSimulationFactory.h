#pragma once
#include "pch.h"
#include "TwoDimSimulationType.h"

#include "TwoDimSimulation_Fluid.h"
#include "TwoDimSimulation_FluidWrapper.h"


class TwoDimSimulationFactory
{
public:
	TwoDimSimulationTypeWrapper* makeTwoDimSimulationObj(std::string newSimulationType);
};


TwoDimSimulationTypeWrapper* TwoDimSimulationFactory::makeTwoDimSimulationObj(std::string newSimulationType)
{
	if (newSimulationType.compare("Fluid")) {
		// return the wrapper with ties to the newly created fluid simulation 
		return new TwoDimSimulation_FluidWrapper(new TwoDimSimulation_Fluid());
	}
	else 
	{
		return nullptr;
	}
}


