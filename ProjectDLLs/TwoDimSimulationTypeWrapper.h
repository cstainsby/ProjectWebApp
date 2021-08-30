#pragma once
#include "pch.h"

class TwoDimSimulationTypeWrapper
{
public:
	TwoDimSimulationTypeWrapper();

	// call to change a given setting
	virtual void EditSetting(const std::string setting, float newVal);

	// get view
	virtual void GetView(const std::string viewName, float*&);
};

TwoDimSimulationTypeWrapper::TwoDimSimulationTypeWrapper() 
{

}