#include <map>

class IBaseGameWorldPlace;
class PlaceManager {
public:
	PlaceManager(){};
	~PlaceManager(){};
	void Init();
	
private:
	IBaseGameWorldPlace* placeInn_;
	IBaseGameWorldPlace* placePub_;
	IBaseGameWorldPlace* placeDunjeon_;
	std::map<int ,IBaseGameWorldPlace*> place_map_;
};