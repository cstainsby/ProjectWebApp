#pragma once
#include "TwoDimSimulationTypeWrapper.h"
#include "TwoDimSimulation_Fluid.h"


class TwoDimSimulation_FluidWrapper : public TwoDimSimulationTypeWrapper
{
public:
	// use dependancy injection to link a given project with dll calls
	TwoDimSimulation_FluidWrapper(TwoDimSimulation_Fluid* project);

	// overloaded destructor
	~TwoDimSimulation_FluidWrapper();

	// call to change a given setting
	void setSetting(const std::string setting, float newVal);

	// get view
	void getView(const std::string viewName, float*&);

	// interact with the project
	void interact(const std::string interactionName, int xCord, int yCord);

	// update to next step
	void update() const;

private:
	// pointer to current fluid simulation project
	TwoDimSimulation_Fluid* project;

	// function lists for settings and views
	// kv list, key: string identifier, value: setting setter functions relating to string
	typedef void (TwoDimSimulation_Fluid::* settingSetterFunc)(float);
	ArrayListCollection<std::string, settingSetterFunc> settingInteractionList;

	// kv list, key: string identifier, value: view getter functions relating to string
	typedef void (TwoDimSimulation_Fluid::* viewReturnFunc)(float*&);
	ArrayListCollection<std::string, viewReturnFunc> viewInteractionList;

	// kv list, key: string identifier, value: view getter functions relating to string
	typedef void(TwoDimSimulation_Fluid::* userInteractionFunc)(int xCord, int yCord);
	ArrayListCollection<std::string, userInteractionFunc> userInteractionList;
};