#pragma once
#include "pch.h"
#include "TwoDimSimulation_Fluid.h"

class TwoDimSimulation_FluidFacade
{
public:
	// use dependancy injection to link a given project with dll calls
	TwoDimSimulation_FluidFacade(TwoDimSimulation_Fluid project);

private:
	// current fluid simulation project
	TwoDimSimulation_Fluid project;

	// function lists for settings and views
	// kv list, key: string identifier, value: setting setter functions relating to string
	typedef void (TwoDimSimulation_Fluid::* settingSetterFunc)(float);
	ArrayListCollection<std::string, settingSetterFunc> settingInteractionList; 

	// kv list, key: string identifier, value: view getter functions relating to string
	typedef void (TwoDimSimulation_Fluid::*viewReturnFunc)(float*&);
	ArrayListCollection<std::string, viewReturnFunc> viewInteractionList;
};