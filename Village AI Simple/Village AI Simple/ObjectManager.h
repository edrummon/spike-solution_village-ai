#pragma once

#include "BaseObject.h"
#include <list>
using std::list;

class CObjectManager
{
protected:
	list<CBaseObject*> m_cObjects;
	list<CBaseObject*> m_cDeadObjects;

	CObjectManager(void);
	~CObjectManager(void);

	void clean();

public:
	static CObjectManager& getInstance();
	inline size_t getNumberObjects() { return m_cObjects.size(); }

	inline void insertObject(CBaseObject* object) { m_cObjects.push_back(object); }
	void removeObject(CBaseObject* object);
	void updateObjects(float fDeltaTime);
};
