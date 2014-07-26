#pragma once
#include "BaseObject.h"

#define DAY (0.002739726f * 11) // (1 / 365) * 11. It will take ~35 seconds to age 1 year
#define TIME_HOUR_MODIFIER 240

class CPerson : public CBaseObject
{
	friend class CVillage;
private:
	CVillage * m_pVillage;
	int m_nDaysPast;
	int m_nAge;
	int m_nHunger;
	int m_nDeathAge;
	int m_nBirthingAge;
	int m_nMenopauseAge;
	int m_nNumChildren;
	int m_nMaxChildren;
	int m_nLastAge;
	bool m_bFemale;

public:
	CPerson(CVillage* pVillage, int nAge);
	~CPerson(void);

	bool update(float fDelta);

	////////////////////////////
	// Accessors
	////////////////////////////
	inline int getDaysPast()							{ return m_nDaysPast; }
	inline int getLastAge()								{ return m_nLastAge; }
	inline int getAge()									{ return m_nAge; }
	inline int getHunger()								{ return m_nHunger; }
	inline int getDeathAge()							{ return m_nDeathAge; }
	inline int getBirthingAge()							{ return m_nBirthingAge; }
	inline int getMenopauseAge()						{ return m_nMenopauseAge; }
	inline int getNumChildren()							{ return m_nNumChildren; }
	inline int getMaxChildren()							{ return m_nMaxChildren; }
	inline bool isFemale()								{ return m_bFemale; }

	////////////////////////////
	// Mutators
	////////////////////////////
	inline void setDaysPast(int nNewDaysPast)			{ m_nDaysPast = nNewDaysPast; }
	inline void setLastAge(int nNewLastAge)				{ m_nLastAge = nNewLastAge; }
	inline void setAge(int nNewAge)						{ m_nAge = nNewAge; }
	inline void setHunger(int nNewHunger)				{ m_nHunger = nNewHunger; }
	inline void setDeathAge(int nNewDeathAge)			{ m_nDeathAge = nNewDeathAge; }
	inline void setBirthingAge(int nNewBirthingAge)		{ m_nBirthingAge = nNewBirthingAge; }
	inline void setMenopauseAge(int nNewMenopauseAge)	{ m_nMenopauseAge = nNewMenopauseAge; }
	inline void setNumChildren(int nNewNumChildren)		{ m_nNumChildren = nNewNumChildren; }
	inline void setMaxChildren(int nNewMaxChildren)		{ m_nMaxChildren = nNewMaxChildren; }
};
