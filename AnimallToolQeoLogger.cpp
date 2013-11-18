#include "AnimallToolQeoLogger.hpp"

using namespace Animall::Tool::Qeo;

Logger::Logger() {
    this->err = false;
    this->qeo = qeo_factory_create();
    if (this->qeo == NULL) {
        this->err = true;
    }

    this->BalanceWeightUpdateER = NULL;
    this->GamelleWeightUpdateER = NULL;

}

Logger::~Logger() {
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

void Logger::waitExit() {
    std::string cmd;
    std::string cmdExit = "exit";
    do {
        std::cin >> cmd;
    } while (cmdExit.compare(cmd));
}

/**/

bool Logger::addAll() {
    this->addBalance();
    this->addGamelle();
}

/**/
static void QeoBalanceWeightUpdateFct(const qeo_event_reader_t *reader, const void *data, uintptr_t userdata) {
    qeo_animall_balance_NewWeight_t* msg = (qeo_animall_balance_NewWeight_t*) data;
    std::cout << "*****" << std::endl;
    std::cout << "*\t" << "BalanceWeightUpdate:" << std::endl;
    std::cout << "*\t\t" << "uuid:" << "\t" << msg->uuid << std::endl;
    std::cout << "*\t\t" << "weight:" << "\t" << msg->weight << std::endl;
    std::cout << "*\t\t" << "timestamp:" << "\t" << msg->timestamp << std::endl;
    std::cout << "*****" << std::endl;
}

qeo_event_reader_listener_t Logger::BalanceWeightUpdateLst = {.on_data = QeoBalanceWeightUpdateFct};

bool Logger::addBalance() {
    this->addBalanceWeightUpdate();
}

bool Logger::addBalanceWeightUpdate() {
    if (this->err == false) {
        this->BalanceWeightUpdateER = qeo_factory_create_event_reader(qeo, qeo_animall_balance_NewWeight_type, &Logger::BalanceWeightUpdateLst, 0);
        if (this->BalanceWeightUpdateER == NULL) {
            std::cout << "BalanceWeightUpdateER == NULL" << std::endl;
            this->err = true;
        }
    }
}

/**/
static void QeoGamelleWeightUpdateFct(const qeo_event_reader_t *reader, const void *data, uintptr_t userdata) {
    qeo_animall_gamelle_NewWeight_t* msg = (qeo_animall_gamelle_NewWeight_t*) data;
    std::cout << "*****" << std::endl;
    std::cout << "*\t" << "GamelleWeightUpdate:" << std::endl;
    std::cout << "*\t\t" << "uuid:" << "\t" << msg->uuid << std::endl;
    std::cout << "*\t\t" << "weight:" << "\t" << msg->weight << std::endl;
    std::cout << "*\t\t" << "timestamp:" << "\t" << msg->timestamp << std::endl;
    std::cout << "*****" << std::endl;
}

qeo_event_reader_listener_t Logger::GamelleWeightUpdateLst = {.on_data = QeoGamelleWeightUpdateFct};

bool Logger::addGamelle() {
    this->addGamelleWeightUpdate();
}

bool Logger::addGamelleWeightUpdate() {
    if (this->err == false) {
        this->GamelleWeightUpdateER = qeo_factory_create_event_reader(qeo, qeo_animall_gamelle_NewWeight_type, &Logger::GamelleWeightUpdateLst, 0);
        if (this->GamelleWeightUpdateER == NULL) {
            std::cout << "GamelleWeightUpdateER == NULL" << std::endl;
            this->err = true;
        }
    }
}



