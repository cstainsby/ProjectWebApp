#pragma once
#include "pch.h"

class TwoDimSimulationTypeWrapper
{
public:
	TwoDimSimulationTypeWrapper();

	~TwoDimSimulationTypeWrapper() {};

	// call to change a given setting
	virtual void setSetting(const std::string setting, float newVal);

	// get view
	virtual void getView(const std::string viewName, float*&);

	// update function
	virtual void update() const;

	// interact function
	virtual void interact(const std::string interactionName, int xCord, int yCord);
};

TwoDimSimulationTypeWrapper::TwoDimSimulationTypeWrapper() 
{

}