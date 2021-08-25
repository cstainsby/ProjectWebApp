#pragma once
#include "TwoDimSimulationType.h"

class TwoDimFluidSimulationProject : TwoDimSimulationType 
{
public:
	TwoDimFluidSimulationProject();   // DVC
	~TwoDimFluidSimulationProject();  // EVC

private:
	// private member attributes
	float viscocity;
	float diff;
	float dt;
	float* velX; // x components of the vector field (next itteration)
	float* velY; // y components of the vector field (next itteration)
	float* velX_0; // x components of the vector field (initial itteration)
	float* velY_0; // y components of the vector field (initial itteration)
	float* s;
	float* density;

	// main simulation member functions 
	void nextStep();
	void run();

	// helper functions to the main member functions
	void diffuse(int b, float*& x, float*& x_0, float diff, float dt);

	void advect(int b, float* d, float* d_0, float* u, float* v, float dt);

	void project(float* u, float* v, float* p, float* div);

	void setBoundary(int b, float* x); // handles calculations for the grid boundry values
};