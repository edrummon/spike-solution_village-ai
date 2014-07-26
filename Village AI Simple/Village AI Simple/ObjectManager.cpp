#include "ObjectManager.h"

CObjectManager::CObjectManager(void)
{
}

CObjectManager::~CObjectManager(void)
{
	clean();

	while(false == m_cObjects.empty())
	{
		delete *(m_cObjects.begin());
		m_cObjects.remove(*(m_cObjects.begin()));
	}
}

void CObjectManager::clean()
{
	while(false == m_cDeadObjects.empty())
	{
		m_cObjects.remove(*(m_cDeadObjects.begin()));
		delete *(m_cDeadObjects.begin());
		m_cDeadObjects.remove(*(m_cDeadObjects.begin()));
	}
}

CObjectManager& CObjectManager::getInstance()
{
	static CObjectManager s_cObjectManager;
	return s_cObjectManager;
}

void CObjectManager::updateObjects(float fDeltaTime)
{
	for(list<CBaseObject*>::iterator iter = m_cObjects.begin(); iter != m_cObjects.end();)
	{
		if(false == (*iter)->update(fDeltaTime))
			m_cObjects.erase(iter++);
		else
			++iter;
	}
}

void CObjectManager::removeObject(CBaseObject* object) 
{
	m_cDeadObjects.push_back(object); 
}