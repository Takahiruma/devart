#include <iostream>
#include "onde.hpp"

class GestionOnde : public Onde {
public:
	GestionOnde();
	~GestionOnde();

	void addOnde(Onde o);
	void drawOnde(RenderWindow& win);
	void update();


private:
	std::vector<Onde> bebe_ondes;
};