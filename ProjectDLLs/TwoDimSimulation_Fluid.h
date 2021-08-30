#pragma once
#include "TwoDimSimulationType.h"

class TwoDimSimulation_Fluid : public TwoDimSimulationType
{
public:
	TwoDimSimulation_Fluid();   // DVC
	~TwoDimSimulation_Fluid();  // EVC

	// setters for settings
	void setViscocity(float viscocity);
	void setDiff(float diff);
	void setDt(float dt);
	void setDensityRate();
	void setXVelocityRate();
	void setYVelocityRate();

	// interaction function with simulation
	void addDensity(int x, int y);
	void addVelocity(int x, int y, float xVel, float yVel);

	// view functions 
	void getDensity(float*& denArr);
	void getXVelocity(float*& velXArr);
	void getYVelocity(float*& velYArr);

	// main simulation member functions 
	void nextStep();

private:
	// private member attributes
	// settings controlling liquid attributes
	float viscocity;
	float diff;
	float dt;
	float densityRate;                           // rate of liquid added when clicking 
	std::pair<float, float> velocityRate;        // how fast liquid is displaced when clicking (pair::<xVel,yVel>)

	// arrays that hold state of project 
	float* velX; // x components of the vector field (next itteration)
	float* velY; // y components of the vector field (next itteration)
	float* velX_0; // x components of the vector field (initial itteration)
	float* velY_0; // y components of the vector field (initial itteration)
	float* s;
	float* density;

	// helper functions to the main member functions
	void diffuse(int b, float*& x, float*& x_0, float diff, float dt);
	void advect(int b, float* d, float* d_0, float* u, float* v, float dt);
	void project(float* u, float* v, float* p, float* div);
	void setBoundary(int b, float* x); // handles calculations for the grid boundry values
};