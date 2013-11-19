#include "AnimallObjectBridge.hpp"

using namespace Animall::Object;

Bridge::Bridge(std::string baseUrl) {
    this->urlBase = baseUrl;
    this->initListen();
    this->wait();
}

void Bridge::initListen() {
    this->qeoBr = new Animall::Tool::Qeo::Bridge(this->urlBase);
    this->qeoBr->addBalance();
    this->qeoBr->addGamelle();
}

void Bridge::wait() {
    std::string cmd;
    std::string cmdExit = "exit";
    do {
        std::cin >> cmd;
    } while (cmdExit.compare(cmd));
}

Bridge::~Bridge() {

}