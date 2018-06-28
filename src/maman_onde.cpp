#include <vector>
#include <utility>
#include "maman_onde.hpp"

GestionOnde::GestionOnde(){
	//construire à partir d'un vector passé un paramètre; vide si nullptr
}

GestionOnde::~GestionOnde(){
	//suppression du vector
}

void GestionOnde::addOnde(Onde o){
	bebe_ondes.push_back(o);
}

void GestionOnde::drawOnde(RenderWindow& win) {
	win.clear();
	if (!bebe_ondes.empty()) {
		for (std::vector<Onde>::iterator it = bebe_ondes.begin(); it != bebe_ondes.end(); ++it) {
			float inter = 1.0f - (float(it->getLifeTime()) / float(it->getLifeTimeMax()));
			float newscale = (it->getScaleMin()*(1-inter))+(it->getScaleMax()*inter);
			it->setScale(newscale,newscale);
			float inter2 = (float(it->getDecayTime()) / float(it->getDecayTimeMax()));
			Color color(it->getOutlineColor());
			color.a = inter2*255;
			it->setOutlineColor(color);
			win.draw(*it);
		}
	}
}

void GestionOnde::update() {

	if (!bebe_ondes.empty()) {

		std::vector<Onde>::iterator it = bebe_ondes.begin();
		int remainingTime, decayingTime;
		while (it != bebe_ondes.end()) {
			if ((remainingTime = (it->getLifeTime() - 1)) > 0) {
				it->setLifeTime(remainingTime);
				++it;
			}
			else if ((decayingTime = (it->getDecayTime()-1)) > 0)
			{
				it->setDecayTime(decayingTime);
				++it;
			}
			else {
				bebe_ondes.erase(it);
			}
		}
	}

}