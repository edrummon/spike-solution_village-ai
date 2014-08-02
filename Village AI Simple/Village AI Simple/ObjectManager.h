#pragma once

#include "BaseObject.h"
#include <list>
using std::list;

class CObjectManager
{
protected:
	list<CBaseObject*> m_cObjects;

	CObjectManager(void);
	~CObjectManager(void);

public:
	static CObjectManager& getInstance();
	inline size_t getNumberObjects() { return m_cObjects.size(); }

	inline void insertObject(CBaseObject* object) { m_cObjects.push_back(object); }
	void updateObjects(float fDeltaTime);
};
