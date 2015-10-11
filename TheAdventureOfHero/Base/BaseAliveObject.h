//For Alive Object
//ex. Hero, Monster,...

class IBaseAliveObject {
public:
	virtual bool AttackNormal()=0;
protected:
//capabilities 
	int HP_;
	int SP_;
	int ATK_;
	int DEF_;
	int LEV_;
//items
	int Gold_;
};