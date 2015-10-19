//For Alive Object
//ex. Hero, Monster,...

class IBaseAliveObject {
public:
	virtual bool AttackNormal()=0;
	virtual bool getType()=0;
	
};