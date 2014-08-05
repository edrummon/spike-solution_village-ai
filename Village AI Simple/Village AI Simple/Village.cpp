#include "Village.h"
#include "Person.h"

#if _DEBUG
#include <iostream>
using std::cout;
#endif

CVillage::CVillage(void) : m_nFood(250), m_fTime(0)
{
	for(int i = 0; i < s_nStartingVillagers; ++i)
	{
		if(0 == rand() % 2)
			m_cFemaleVillagers.push_back(new CPerson(this, 17, true));
		else
			m_cMaleVillagers.push_back(new CPerson(this, 17, false));
	}
}

CVillage::~CVillage(void)
{
}

bool CVillage::update(float fDelta)
{
#if _DEBUG
	static int daysPast = 0;
#endif
	setTime(getTime() + fDelta);

	while(getTime() > 1)
	{
#if _DEBUG
		cout << "-----------------------------------" << '\n';
		cout << "Days Past: " << ++daysPast << '\n';
		cout << "Villagers: " << getVillageSize() << '\n';
#endif

		bool loopFemale = true;
		setTime(getTime() - 1);
		setFood(250);
		for (auto femaleIter = m_cFemaleVillagers.begin(), maleIter = m_cMaleVillagers.begin();
			femaleIter != m_cFemaleVillagers.end() || maleIter != m_cMaleVillagers.end();)
		{
			if (loopFemale && femaleIter != m_cFemaleVillagers.end())
			{
				if (false == (*femaleIter)->update(fDelta))
				{
#if _DEBUG
					cout << '\n';
					cout << "Age:\t\t" << (*femaleIter)->getAge() << '\n';
					cout << "Death Age:\t" << (*femaleIter)->getDeathAge() << '\n';
					cout << "Is Female:\t" << "true" << '\n';
#endif
					delete *femaleIter;
					m_cFemaleVillagers.erase(femaleIter++);
				}
				else
					++femaleIter;
				loopFemale = false;
			}
			else
			{
				if (maleIter == m_cMaleVillagers.end())
				{
					loopFemale = true;
					continue;
				}
				if (false == (*maleIter)->update(fDelta))
				{
#if _DEBUG
					cout << '\n';
					cout << "Age:\t\t" << (*maleIter)->getAge() << '\n';
					cout << "Death Age:\t" << (*maleIter)->getDeathAge() << '\n';
					cout << "Is Female:\t" << "false" << '\n';
#endif
					delete *maleIter;
					m_cMaleVillagers.erase(maleIter++);
				}
				else
					++maleIter;
				loopFemale = true;
			}
		}

#if _DEBUG
		cout << "Food:\t" << getFood() << '\n';
#endif
	}

	if(0 == getVillageSize())
		return false;

	return true;
}