#include "AnimallObjectGamelle.hpp"

using namespace Animall::Object;

Gamelle::Gamelle(std::string uuid) {
    this->uuid = uuid;
}

Gamelle::~Gamelle() {
    //rien à nettoyer
}

void Gamelle::setWeight(float newWeight) {
    this->weight = newWeight;
}

float Gamelle::getWeight() {
    return this->weight;
}

std::string Gamelle::getUuid() {
    return this->uuid;
}
