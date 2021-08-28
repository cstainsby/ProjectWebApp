#pragma once
#include "pch.h"
#include "TwoDimSimulationType.h"

#include "TwoDimSimulation_Fluid.h"

template<typename projType>
class TwoDimSimulationFactory
{
public:
	projType makeTwoDimSimulation(std::string newSimulationType);
};

template<typename projType>
projType TwoDimSimulationFactory<projType>::makeTwoDimSimulation(std::string newSimulationType) 
{
	if (newSimulationType.compare("Fluid")) {
		return new TwoDimSimulation_Fluid();
	}
	else 
	{
		return nullptr;
	}
}