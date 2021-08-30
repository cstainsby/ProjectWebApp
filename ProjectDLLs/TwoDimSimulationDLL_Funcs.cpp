#include "TwoDimSimulationDLL.h"

// initializes the project
void TwoDimSimulationDLL::init(std::string projectName)
{
	TwoDimSimulationFactory factory;

	this->projectWrapper = factory.makeTwoDimSimulationObj(projectName);
}

// updates the project state
void TwoDimSimulationDLL::update()
{
	this->projectWrapper->update();
}

// gets an array to be displayed in the view
float* TwoDimSimulationDLL::getView(std::string viewName)
{
	float* display;

	this->projectWrapper->getView(viewName, display);

	return display;
}

// changes the value of a given setting
void TwoDimSimulationDLL::setSetting(std::string settingName, float value)
{
	this->projectWrapper->setSetting(settingName, value);
}

// take input type and coordinates and decides how to handle the request
void TwoDimSimulationDLL::interact(std::string inputType, int xCord, int yCord)
{

}

// delete all on memory items in object
void TwoDimSimulationDLL::release()
{
	delete projectWrapper;
}
