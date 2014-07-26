#include "ObjectManager.h"
#include "Village.h"

#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using std::cout;

#define FAST_FOWARD 16

int main()
{
	DWORD dwPrevTime = 0;
	float fDeltaTime = 0;
	
	unsigned int frames = 0;
	float time = 0;
	int elapsedTime = 0;

	for(unsigned int i = 0; i < 1; ++i)
		CObjectManager::getInstance().insertObject(new CVillage());

	while(CObjectManager::getInstance().getNumberObjects() > 0)
	{
		DWORD dwStartTime = GetTickCount();
		fDeltaTime = (dwStartTime - dwPrevTime) / 1000.0f;
		dwPrevTime = dwStartTime;

		srand(dwStartTime);

		if(fDeltaTime > 0.2f)
			fDeltaTime = 0.2f;

		CObjectManager::getInstance().updateObjects(fDeltaTime * FAST_FOWARD);

		time += fDeltaTime;
		++frames;
		if(time > 1)
		{
			cout << "-========= TIMER ==========-" << '\n';
			cout << "Time:\t" << ++elapsedTime << '\n';
			cout << "FPS:\t" << frames << '\n';
			cout << "-========= TIMER ==========-" << '\n';
			time = 0;
			frames = 0;
			//Sleep(50);
		}
	}

	return 0;
}