#include "onde.hpp"
#include <iostream>

Onde::Onde(int lf_max, int dct_max, float sc_min, float sc_max):CircleShape(),life_time_max(lf_max), life_time(lf_max), decay_time_max(dct_max), decay_time(dct_max), scale_min(sc_min), scale_max(sc_max) {
}

Onde::~Onde() {}