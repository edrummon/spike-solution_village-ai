#include "ObjectManager.h"

CObjectManager::CObjectManager(void)
{
}

CObjectManager::~CObjectManager(void)
{
	while(false == m_cObjects.empty())
	{
		delete *(m_cObjects.begin());
		m_cObjects.remove(*(m_cObjects.begin()));
	}
}

CObjectManager& CObjectManager::getInstance()
{
	static CObjectManager s_cObjectManager;
	return s_cObjectManager;
}

void CObjectManager::updateObjects(float fDeltaTime)
{
	for(auto iter = m_cObjects.begin(); iter != m_cObjects.end();)
	{
		if(false == (*iter)->update(fDeltaTime))
			m_cObjects.erase(iter++);
		else
			++iter;
	}
}