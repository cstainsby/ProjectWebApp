#pragma once
#include "pch.h"
#include "TwoDimSimulationTypeWrapper.h"
#include "TwoDimSimulation_Fluid.h"


class TwoDimSimulation_FluidWrapper : public TwoDimSimulationTypeWrapper
{
public:
	// pointer to current fluid simulation project
	TwoDimSimulation_Fluid* project;

	// function lists for settings and views
	// kv list, key: string identifier, value: setting setter functions relating to string
	typedef void (TwoDimSimulation_Fluid::* settingSetterFunc)(float);
	ArrayListCollection<std::string, settingSetterFunc> settingInteractionList;

	// kv list, key: string identifier, value: view getter functions relating to string
	typedef void (TwoDimSimulation_Fluid::* viewReturnFunc)(float*&);
	ArrayListCollection<std::string, viewReturnFunc> viewInteractionList;

	typedef void(TwoDimSimulation_Fluid::* userInteractionFunc)(int xCord, int yCord);


	// use dependancy injection to link a given project with dll calls
	TwoDimSimulation_FluidWrapper(TwoDimSimulation_Fluid* project);

	// call to change a given setting
	void EditSetting(const std::string setting, float newVal);

	// get view
	void GetView(const std::string viewName, float*&);

};