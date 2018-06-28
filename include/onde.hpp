#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

using namespace sf;
class Onde : public CircleShape {
	public:
		Onde(int lf_max = 1000, int dct = 10, float sc_min = 1, float sc_max = 2);
		~Onde();

		inline int getLifeTime() const { return life_time; }
		inline void setLifeTime(int time) { life_time = time; }

		inline int getLifeTimeMax() const { return life_time_max; }
		inline void setLifeTimeMax(int time) { life_time_max = time; }

		inline int getDecayTime() const { return decay_time; }
		inline void setDecayTime(int time) { decay_time = time; }

		inline int getDecayTimeMax() const { return decay_time_max; }
		inline void setDecayTimeMax(int time) { decay_time_max = time; }

		inline float getScaleMin() const { return scale_min; }
		inline void setScaleMin(float min) { scale_min = min; }

		inline float getScaleMax() const { return scale_max; }
		inline void setScaleMax(float max) { scale_max = max; }

	private:
		int life_time, life_time_max, decay_time, decay_time_max; //en miliseconde
		float scale_min, scale_max;
};