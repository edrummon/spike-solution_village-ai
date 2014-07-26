#pragma once

class CBaseObject
{
public:
	CBaseObject(void);
	virtual ~CBaseObject(void);

	virtual bool update(float fDelta) = 0;
};
