#include "AnimallToolQeoBridge.hpp"

using namespace Animall::Tool::Qeo;

std::string Bridge::baseUrl = "";

Bridge::Bridge(std::string baseUrl) {
    Bridge::baseUrl = baseUrl;
    this->err = false;
    this->qeo = qeo_factory_create();
    if (this->qeo == NULL) {
        std::cout << "QEO FACTORYCREATE == NULL" << std::endl;
        this->err = true;
    }

    this->BalanceWeightUpdateER = NULL;
    this->GamelleWeightUpdateER = NULL;

}

Bridge::~Bridge() {
    if (this->BalanceWeightUpdateER != NULL) {
        qeo_event_reader_close(this->BalanceWeightUpdateER);
    }
    if (this->GamelleWeightUpdateER != NULL) {
        qeo_event_reader_close(this->GamelleWeightUpdateER);
    }
    if (this->qeo != NULL) {
        qeo_factory_close(this->qeo);
    }
}

bool Bridge::addBalance() {
    this->addBalanceWeightUpdate();
}

/**/
void Bridge::QeoBalanceWeightUpdateFct(const qeo_event_reader_t *reader, const void *data, uintptr_t userdata) {
    qeo_animall_balance_NewWeight_t* msg = (qeo_animall_balance_NewWeight_t*) data;
    Animall::Tool::Api::Balance::updateWeight(Bridge::baseUrl, msg->uuid, msg->weight, msg->timestamp);
}

qeo_event_reader_listener_t Bridge::BalanceWeightUpdateLst = {.on_data = Bridge::QeoBalanceWeightUpdateFct};

bool Bridge::addBalanceWeightUpdate() {
    if (this->err == false) {
        this->BalanceWeightUpdateER = qeo_factory_create_event_reader(qeo, qeo_animall_balance_NewWeight_type, &Bridge::BalanceWeightUpdateLst, 0);
        if (this->BalanceWeightUpdateER == NULL) {
            std::cout << "BalanceWeightUpdateER == NULL" << std::endl;
            this->err = true;
        }
        std::cout << "BalanceWeightUpdateER:Ok" << std::endl;
    }
}

bool Bridge::addGamelle() {
    this->addGamelleWeightUpdate();
}

void Bridge::QeoGamelleWeightUpdateFct(const qeo_event_reader_t *reader, const void *data, uintptr_t userdata) {
    qeo_animall_gamelle_NewWeight_t* msg = (qeo_animall_gamelle_NewWeight_t*) data;
    Animall::Tool::Api::Gamelle::updateWeight(Bridge::baseUrl, msg->uuid, msg->weight, msg->timestamp);
}

qeo_event_reader_listener_t Bridge::GamelleWeightUpdateLst = {.on_data = Bridge::QeoGamelleWeightUpdateFct};

bool Bridge::addGamelleWeightUpdate() {
    if (this->err == false) {
        this->GamelleWeightUpdateER = qeo_factory_create_event_reader(qeo, qeo_animall_gamelle_NewWeight_type, &Bridge::GamelleWeightUpdateLst, 0);
        if (this->GamelleWeightUpdateER == NULL) {
            std::cout << "GamelleWeightUpdateER == NULL" << std::endl;
            this->err = true;
        }
        std::cout << "GamelleWeightUpdateER:Ok" << std::endl;
    }
}