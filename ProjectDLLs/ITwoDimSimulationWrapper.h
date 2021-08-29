#pragma once

template<typename TwoDimSim_Subtype>
class ITwoDimSimulationWrapper
{
protected:
	// current fluid simulation project
	TwoDim_subtype project;

	// function lists for settings and views
	// kv list, key: string identifier, value: setting setter functions relating to string
	typedef void (TwoDim_subtype::* settingSetterFunc)(float);
	ArrayListCollection<std::string, settingSetterFunc> settingInteractionList;

	// kv list, key: string identifier, value: view getter functions relating to string
	typedef void (TwoDim_subtype::* viewReturnFunc)(float*&);
	ArrayListCollection<std::string, viewReturnFunc> viewInteractionList;

	typedef void(TwoDim_subtype::* userInteractionFunc)(int xCord, int yCord)
};