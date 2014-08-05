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
	list<CPerson*> m_cFemaleVillagers;
	list<CPerson*> m_cMaleVillagers;

	static const int s_nStartingVillagers = 24;
	float m_fTime;

public:
	CVillage(void);
	~CVillage(void);

	bool update(float fDelta);
	//CPerson* findPounder(CPerson* poundee);

	inline void addFemaleVillager(CPerson* villager)		{ m_cFemaleVillagers.push_back(villager); }
	inline void removeFemaleVillager(CPerson* villager)		{ m_cFemaleVillagers.remove(villager); }

	inline void addMaleVillager(CPerson* villager)			{ m_cMaleVillagers.push_back(villager); }
	inline void removeMaleVillager(CPerson* villager)		{ m_cMaleVillagers.remove(villager); }

	inline void setFood(int nFood)							{ m_nFood = nFood; if(m_nFood < 0) m_nFood = 0; }
	inline const int getFood() const						{ return m_nFood; }

	inline void setTime(float fNewTime)						{ m_fTime = fNewTime; }
	inline const float getTime() const						{ return m_fTime; }

	inline const size_t getVillageSize() const				{ return m_cFemaleVillagers.size() + m_cMaleVillagers.size(); }
};
