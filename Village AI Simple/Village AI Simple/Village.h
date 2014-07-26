#pragma once
#include "BaseObject.h"
#include <list>
using std::list;

class CPerson;

class CVillage : public CBaseObject
{
private:
	int m_nFood;

protected:
	list<CPerson*> m_cVillagers;

	static const int s_nStartingVillagers = 24;
	float m_fTime;

public:
	CVillage(void);
	~CVillage(void);

	bool update(float fDelta);

	inline void addVillager(CPerson* villager)		{ m_cVillagers.push_back(villager); }
	inline void removeVillager(CPerson* villager)	{ m_cVillagers.remove(villager); }

	inline void setFood(int nFood)					{ m_nFood = nFood; if(m_nFood < 0) m_nFood = 0; }
	inline int getFood()							{ return m_nFood; }

	inline void setTime(float fNewTime)				{ m_fTime = fNewTime; }
	inline float getTime()							{ return m_fTime; }
};
