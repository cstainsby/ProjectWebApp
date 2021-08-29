#include "TwoDimSimulation_Fluid.h"

// DVC
TwoDimSimulation_Fluid::TwoDimSimulation_Fluid() {
    this->N = 10; // for now set N to 10
    this->gridArea = (N + 2) * (N + 2);

    this->viscocity = 1;
    this->diff = 1;
    this->dt = 1;
    this->velX = new float[gridArea];
    this->velY = new float[gridArea];
    this->velX_0 = new float[gridArea];
    this->velY_0 = new float[gridArea];
    this->s = new float[gridArea];
    this->density = new float[gridArea];

    //this->settingInteractionList = new ArrayListCollection<std::string, settingSetterFunc>();

    for (int i = 0; i < gridArea; ++i) {
        velX[i] = 0;
        velY[i] = 0;
        velX_0[i] = 0;
        velY_0[i] = 0;
        s[i] = 0;
        density[i] = 0;
    }
}

// Destructor
TwoDimSimulation_Fluid::~TwoDimSimulation_Fluid() {
    delete []velX;
    delete []velY;
    delete []velX_0;
    delete []velY_0;
    delete []s;
    delete []density;
}

// ------------- user interactable functions --------------
// this function will be looped to play the simulation
// include a velocity and density step
// it will take a square, in case of user input, 
void TwoDimSimulation_Fluid::nextStep() {

    // viscocity set to 1 temporarily, dt set to 1
    //diffuse velocity twice for x and y velocity vector components
    /*diffuse(1, velX, velX_0, viscocity, dt);
    diffuse(2, velY, velY_0, viscocity, dt);

    //project velocity (both x and y components in the same function
    project(velX_0, velY_0, velX, velY);

    //advect the velocities two times, x then y
    advect(1, velX, velX_0, velX_0, velY_0, dt);
    advect(2, velY, velY_0, velX_0, velY_0, dt);

    // project velocity but in the opposite order
    project(velX, velY, velX_0, velY_0);*/

    // diffuse density
    diffuse(0, s, density, diff, dt);

    // advect with density and next velocities
    advect(0, density, s, velX, velY, dt);
}

// 
// add Density
void TwoDimSimulation_Fluid::addDensity(int x, int y, float densityAdded) {
    density[findIndex(x, y)] += densityAdded;
}

// add velocity
void TwoDimSimulation_Fluid::addVelocity(int x, int y, float xVel, float yVel) {
    velX_0[findIndex(x, y)] += xVel;
    velY_0[findIndex(x, y)] += yVel;
}


// set viscocity
void TwoDimSimulation_Fluid::setViscocity(float viscocity)
{
    this->viscocity = viscocity;
}

// set diff
void TwoDimSimulation_Fluid::setDiff(float diff)
{
    this->diff = diff;
}

// set dt
void TwoDimSimulation_Fluid::setDt(float dt)
{
    this->dt = dt;
}

// ------------- display return functions --------------
void TwoDimSimulation_Fluid::getDensity(float*& denArr) {
    // TODO find solution for returning the velocity
    // possible bug by not deleting the array
    //delete denArr;
    denArr = new float[gridArea];

    for (int i = 0; i < gridArea; ++i) {
        denArr[i] = density[i];
    }
}

void TwoDimSimulation_Fluid::getXVelocity(float*& velXArr) {

    velXArr = new float[gridArea];

    for (int i = 0; i < gridArea; ++i) {
        velXArr[i] = velX_0[i];
    }
}

void TwoDimSimulation_Fluid::getYVelocity(float*& velYArr) {
    velYArr = new float[gridArea];

    for (int i = 0; i < gridArea; ++i) {
        velYArr[i] = velY_0[i];
    }
}

// ------------- main sim helper functions --------------
// diffusion helper function 
void TwoDimSimulation_Fluid::diffuse(int b, float*& x, float*& x_0, float diff, float dt) {
    float a = dt * diff * N * N;

    for (int k = 0; k < 10; ++k) {
        // itterate over only non-boundary squares
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                x[findIndex(i, j)] = (x_0[findIndex(i, j)] + a * (x[findIndex(i - 1, j)] + x[findIndex(i + 1, j)] + x[findIndex(i, j - 1)] + x[findIndex(i, j + 1)])) / (1 + 4 * a);
            }
        }
        setBoundary(b, x);
    }
}

// project fluid function - keeps system in equalibrium
// u stores x vector components and v stores y
void TwoDimSimulation_Fluid::project(float* u, float* v, float* p, float* div) {

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {

            div[findIndex(i, j)] = -0.5 * (u[findIndex(i + 1, j)] - u[findIndex(i - 1, j)] + v[findIndex(i, j + 1)] - v[findIndex(i, j - 1)]) / ((float)N);

            p[findIndex(i, j)] = 0;
        }
    }
    setBoundary(0, div);
    setBoundary(0, p);

    //Gauss Sidel
    for (int k = 0; k < 20; ++k) {
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                float adjacentP = p[findIndex(i - 1, j)] + p[findIndex(i + 1, j)] + p[findIndex(i, j - 1)] + p[findIndex(i, j + 1)];
                p[findIndex(i, j)] = (div[findIndex(i, j)] + adjacentP) / 4;
            }
        }
        setBoundary(0, p);
    }

    // find new velocity vectors
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            u[findIndex(i, j)] -= 0.5 * (p[findIndex(i + 1, j)] - p[findIndex(i - 1, j)]) / ((float)N);
            v[findIndex(i, j)] -= 0.5 * (p[findIndex(i, j + 1)] - p[findIndex(i, j - 1)]) / ((float)N);
        }
    }
    setBoundary(1, u);
    setBoundary(2, v);
}

// advect helper function
void TwoDimSimulation_Fluid::advect(int b, float* d, float* d_0, float* u, float* v, float dt) {
    float jfloat = 1;
    float ifloat = 1;
    float xVel, yVel; // velocity vector components of vector (i,j)
    int i0, i1, j0, j1; // ceilings and floors, used to index grid array
    float s0, s1, t0, t1;
    float dt0 = dt * N;

    for (int j = 1; j <= N; ++j) {
        for (int i = 1; i <= N; ++i) {
            xVel = ifloat - (dt0 * u[findIndex(i, j)]);
            yVel = jfloat - (dt0 * v[findIndex(i, j)]);

            if (xVel < 0.5) { xVel = 0.5; }
            if (xVel > (float)N + 0.5) { xVel = (float)N + 0.5; }

            if (yVel < 0.5) { yVel = 0.5; }
            if (yVel > (float)N + 0.5) { yVel = (float)N + 0.5; }

            // i0 and j0 will be the floors of x and y respectivly, i1 and j1 will be the ceilings
            i0 = (int)xVel;
            i1 = i0 + 1;
            j0 = (int)yVel;
            j1 = j0 + 1;

            s1 = xVel - i0;
            s0 = 1 - s1;
            t1 = yVel - j0;
            t0 = 1 - t1;

            d[findIndex(i, j)] = s0 * (t0 * d_0[findIndex(i0, j0)] + t1 * d_0[findIndex(i0, j1)]) + s1 * (t0 * d_0[findIndex(i1, j0)] + t1 * d_0[findIndex(i1, j1)]);

            ++ifloat;
        }
        ++jfloat;
    }
    setBoundary(b, d);
}

// set boundary functions, handles some simple cases when fluid collides with the container walls we have set
// arr can handle, xVel, yVel, and density
void TwoDimSimulation_Fluid::setBoundary(int b, float* x) {

    // set the non-corner-edges of the grid
    for (int j = 1; j < N; ++j) {
        for (int i = 1; i < N; ++i) {
            // a ? b : c
            // if a == true b, otherwise c
            x[findIndex(0, i)] = b == 1 ? -x[findIndex(1, i)] : x[findIndex(1, i)];

            x[findIndex(N + 1, i)] = b == 1 ? -x[findIndex(N, i)] : x[findIndex(N, i)];

            x[findIndex(i, 0)] = b == 2 ? -x[findIndex(i, 1)] : x[findIndex(i, 1)];

            x[findIndex(i, N + 1)] = b == 2 ? -x[findIndex(i, N)] : x[findIndex(i, N)];
        }
    }

    // find corner squares values
    x[findIndex(0, 0)] = 0.5 * (x[findIndex(1, 0)] + x[findIndex(0, 1)]);
    x[findIndex(0, N + 1)] = 0.5 * (x[findIndex(1, N + 1)] + x[findIndex(0, N)]);
    x[findIndex(N + 1, 0)] = 0.5 * (x[findIndex(N, 0)] + x[findIndex(N + 1, 1)]);
    x[findIndex(N + 1, N + 1)] = 0.5 * (x[findIndex(N, N + 1)] + x[findIndex(N + 1, N)]);
}