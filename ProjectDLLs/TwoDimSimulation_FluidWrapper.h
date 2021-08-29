#pragma once
#include "pch.h"
#include "ITwoDimSimulationWrapper.h"
#include "TwoDimSimulation_Fluid.h"

class TwoDimSimulation_FluidWrapper : ITwoDimSimulationWrapper<TwoDimSim_Subtype>
{
public:
	// use dependancy injection to link a given project with dll calls
	TwoDimSimulation_FluidWrapper(TwoDim_subtype project);

	// call to change a given setting
	void EditSetting(std::string setting, float newVal);

	// get view
	void GetView(std::string viewName, float*&);

private:
	// current fluid simulation project
	TwoDim_subtype project;

	// function lists for settings and views
	// kv list, key: string identifier, value: setting setter functions relating to string
	typedef void (TwoDim_subtype::*settingSetterFunc)(float);
	ArrayListCollection<std::string, settingSetterFunc> settingInteractionList;

	// kv list, key: string identifier, value: view getter functions relating to string
	typedef void (TwoDim_subtype::*viewReturnFunc)(float*&);
	ArrayListCollection<std::string, viewReturnFunc> viewInteractionList;

	typedef void(TwoDim_subtype::*userInteractionFunc)(int xCord, int yCord)
};