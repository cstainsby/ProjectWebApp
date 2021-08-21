#include "pch.h"
#include "GenericDLLProj.h"

// inplementation of the IGameOfLife interface 
class GameOfLifeObj : public IGameOfLife
{
	int add(int n1, int n2);
	void release();
};

int GameOfLifeObj::add(int n1, int n2)
{
	return n1 + n2;
}

void GameOfLifeObj::release()
{
	delete this;
}

// Factory function for the object
#if !defined(_WIN64)
#pragma comment(linker, "/export:GetInstance=_GetInstance@0")
#endif //_WIN64

GAMEOFLIFEAPI GAMEOFLIFEHANDLE APIENTRY GetInstance()
{
	return new GameOfLifeObj;
}

// regular c++ object implementation
int CGameOfLife::add(int n1, int n2)
{
	return n1 + n2;
}

GAMEOFLIFEAPI INT APIENTRY GameOfLifeadd(GAMEOFLIFEHANDLE handle, INT n1, INT n2)
{
	int nResult = -1;

	if (handle) {
		nResult = handle->add(n1, n2);
	}

	return nResult;
}

GAMEOFLIFEAPI VOID APIENTRY GameOfLiferelease(GAMEOFLIFEHANDLE handle)
{
	if (handle) {
		handle->release();
	}
}