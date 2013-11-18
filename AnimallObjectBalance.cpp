#include "AnimallObjectBalance.hpp"

using namespace Animall::Object;

Balance::Balance(std::string uuid) {
    this->uuid = uuid;
}

Balance::~Balance() {
    //rien à nettoyer
}

void Balance::setWeight(float newWeight) {
    this->weight = newWeight;
}

float Balance::getWeight() {
    return this->weight;
}

std::string Balance::getUuid() {
    return this->uuid;
}

