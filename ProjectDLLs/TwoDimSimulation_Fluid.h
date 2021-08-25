#pragma once
#include "TwoDimSimulationType.h"
#include <string>

class TwoDimSimulation_Fluid : TwoDimSimulationType 
{
public:
	TwoDimSimulation_Fluid();   // DVC
	~TwoDimSimulation_Fluid();  // EVC

private:
	// private member attributes
	// settings controlling liquid attributes
	float viscocity;
	float diff;
	float dt;

	// arrays that hold state of project 
	float* velX; // x components of the vector field (next itteration)
	float* velY; // y components of the vector field (next itteration)
	float* velX_0; // x components of the vector field (initial itteration)
	float* velY_0; // y components of the vector field (initial itteration)
	float* s;
	float* density;

	// setters for settings
	void setViscocity(float viscocity);
	void setDiff(float diff);
	void setDt(float dt);

	// main simulation member functions 
	void nextStep();

	// helper functions to the main member functions
	void diffuse(int b, float*& x, float*& x_0, float diff, float dt);
	void advect(int b, float* d, float* d_0, float* u, float* v, float dt);
	void project(float* u, float* v, float* p, float* div);
	void setBoundary(int b, float* x); // handles calculations for the grid boundry values
};

// Factory function which creates Project object
EXTERN_C PROJECTAPI PROJECTHANDLE<FLOAT> WINAPI get_instance(VOID);

// export functions 
EXTERN_C PROJECTAPI VOID APIENTRY project_init(PROJECTHANDLE<FLOAT> handle);

EXTERN_C PROJECTAPI VOID APIENTRY project_release(PROJECTHANDLE<FLOAT> handle);

EXTERN_C PROJECTAPI VOID APIENTRY project_next_step(PROJECTHANDLE<FLOAT> handle);

EXTERN_C PROJECTAPI FLOAT* APIENTRY project_get_project_state(PROJECTHANDLE<FLOAT> handle);
