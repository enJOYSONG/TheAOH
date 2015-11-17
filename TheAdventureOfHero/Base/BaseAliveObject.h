//For Alive Object
//ex. Hero, Monster,...
#pragma once

class IBaseAliveObject {
public:
	virtual bool AttackNormal()=0;
	virtual bool CheckState()=0;
	
};