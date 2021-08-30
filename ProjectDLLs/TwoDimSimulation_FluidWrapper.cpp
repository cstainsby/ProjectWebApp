#include "TwoDimSimulation_FluidWrapper.h"

TwoDimSimulation_FluidWrapper::TwoDimSimulation_FluidWrapper(TwoDimSimulation_Fluid* project)
{
	this->project = project;

	// setup all callable setting setter functions
	settingInteractionList.add("Viscocity", &TwoDimSimulation_Fluid::setViscocity);
	settingInteractionList.add("Diff", &TwoDimSimulation_Fluid::setDiff);
	settingInteractionList.add("Dt", &TwoDimSimulation_Fluid::setDt);

	// setup all callable view getter functions
	viewInteractionList.add("Density", &TwoDimSimulation_Fluid::getDensity);
	viewInteractionList.add("XVelocity", &TwoDimSimulation_Fluid::getXVelocity);
	viewInteractionList.add("YVelocity", &TwoDimSimulation_Fluid::getYVelocity);
}

TwoDimSimulation_FluidWrapper::~TwoDimSimulation_FluidWrapper() 
{
	delete project;
}

void TwoDimSimulation_FluidWrapper::setSetting(const std::string settingName, float newVal)
{
	settingSetterFunc function;

	bool found = settingInteractionList.find(settingName, function);

	// if the member function is found then call it using the project object 
	if (found) {
		(this->project->*function)(newVal);
	}
}

void TwoDimSimulation_FluidWrapper::getView(const std::string viewName, float*& view)
{
	viewReturnFunc function;

	bool found = viewInteractionList.find(viewName, function);

	// if the member function is found then pass in the view array to have the specifed array state copied in
	if (found) {
		(this->project->*function)(view);
	}
}

void TwoDimSimulation_FluidWrapper::update() const
{
	this->project->nextStep();
}

void TwoDimSimulation_FluidWrapper::interact(const std::string interactionName, int xCord, int yCord)
{
	this->project->addDensity(xCord, yCord);
}
