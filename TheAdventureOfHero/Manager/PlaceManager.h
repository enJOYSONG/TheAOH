#include <map>

class IBaseGameWorldPlace;
class GamePlaceInn;
class GamePlacePub;
class GamePlaceDunjeon;
class PlaceManager {
public:
	PlaceManager(){};
	~PlaceManager(){};
	void Init();
	
private:
	GamePlaceInn* placeInn_;
	GamePlacePub* placePub_;
	GamePlaceDunjeon* placeDunjeon_;
	std::map<int ,IBaseGameWorldPlace*> place_map_;
};