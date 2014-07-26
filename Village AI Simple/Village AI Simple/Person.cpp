#include "ObjectManager.h"
#include "Person.h"
#include "Village.h"
#include <time.h>
#include <cstdlib>

CPerson::CPerson(CVillage* pVillage, int nAge) : m_pVillage(pVillage), m_nAge(nAge), m_nLastAge(m_nAge), m_nHunger(0), m_nDaysPast(0),
										m_bFemale(static_cast<bool>(rand() % 2)), m_nBirthingAge(0), m_nMenopauseAge(0), m_nNumChildren(0), m_nMaxChildren(0)
{
	if(false == rand() % 10)
		setDeathAge(rand() % 35);
	else
		setDeathAge(rand() % 100 + 17);

	if(m_bFemale)
	{
		setBirthingAge(rand() % 6 + 13);
		setMenopauseAge(rand() % 10 + 40);
		setMaxChildren(rand() % 10);
	}
}

CPerson::~CPerson(void)
{
}

bool CPerson::update(float fDelta)
{
	// fDelta is unused in this method
	// Village will call update on each villager once per in-game day

	int nStartingHunger = (getHunger() + rand() % 3 + 1);
	int nNewHunger = nStartingHunger - m_pVillage->getFood();
	m_pVillage->setFood(m_pVillage->getFood() - nStartingHunger);
	if(nNewHunger < 0)
		nNewHunger = 0;

	setDaysPast(getDaysPast() + 1);
	setHunger(nNewHunger);

	if(getHunger() > 24)
		return false;
	else if(getHunger() > 5)
		setDeathAge(getDeathAge() - 1);

	if(getDaysPast() > 365)
	{
		setAge(getAge() + 1);
		setDaysPast(0);
	}

	if(getAge() >= getDeathAge())
		return false;

	if(getAge() > getLastAge())
	{
		setLastAge(getAge());

		if(isFemale() && getAge() >= getBirthingAge() && getAge() <= getMenopauseAge() && getNumChildren() < getMaxChildren())
		{
			if(rand() % 10 < 3)
			{
				m_pVillage->addVillager(new CPerson(m_pVillage, 0));
				setNumChildren(getNumChildren() + 1);
			}
		}
	}

	return true;
}