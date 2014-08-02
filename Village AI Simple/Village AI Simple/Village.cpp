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
		m_cVillagers.push_back(new CPerson(this, 17));
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
		cout << "Villagers: " << m_cVillagers.size() << '\n';
#endif

		setTime(getTime() - 1);
		setFood(250);
		for(list<CPerson*>::iterator iter = m_cVillagers.begin(); iter != m_cVillagers.end();)
		{
			if(false == (*iter)->update(fDelta))
			{
#if _DEBUG
				cout << '\n';
				cout << "Age:\t\t" << (*iter)->getAge() << '\n';
				cout << "Death Age:\t" << (*iter)->getDeathAge() << '\n';
				cout << "Is Female:\t" << (*iter)->isFemale() << '\n';
#endif
				delete *iter;
				m_cVillagers.erase(iter++);
			}
			else
				++iter;
		}

#if _DEBUG
		cout << "Food:\t" << getFood() << '\n';
#endif
	}

	if(0 == m_cVillagers.size())
		return false;

	return true;
}