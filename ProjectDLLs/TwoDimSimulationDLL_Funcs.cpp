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

}

// gets an array to be displayed in the view
float* TwoDimSimulationDLL::getView(std::string viewName)
{

}

// changes the value of a given setting
void TwoDimSimulationDLL::setSetting(std::string settingName, float value)
{

}

// take input type and coordinates and decides how to handle the request
void TwoDimSimulationDLL::interact(std::string inputType, int xCord, int yCord)
{

}

void TwoDimSimulationDLL::release()
{

}
