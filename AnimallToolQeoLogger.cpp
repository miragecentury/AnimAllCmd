#include "AnimallToolQeoLogger.hpp"

using namespace Animall::Tool::Qeo;

Logger::Logger() {
    this->err = false;
    this->qeo = qeo_factory_create();
    if (this->qeo == NULL) {
        std::cout << "QEO FACTORYCREATE == NULL" << std::endl;
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

/**/

bool Logger::addAll() {
    this->addBalance();
    this->addGamelle();
}

/**/
void Logger::QeoBalanceWeightUpdateFct(const qeo_event_reader_t *reader, const void *data, uintptr_t userdata) {
    qeo_animall_balance_NewWeight_t* msg = (qeo_animall_balance_NewWeight_t*) data;
    std::cout << "*****" << std::endl;
    std::cout << "*\t" << "BalanceWeightUpdate:" << std::endl;
    std::cout << "*\t\t" << "uuid:" << "\t\t" << msg->uuid << std::endl;
    std::cout << "*\t\t" << "weight:" << "\t\t" << msg->weight << std::endl;
    std::cout << "*\t\t" << "timestamp:" << "\t" << msg->timestamp << std::endl;
    std::cout << "*****" << std::endl;
}

qeo_event_reader_listener_t Logger::BalanceWeightUpdateLst = {.on_data = Logger::QeoBalanceWeightUpdateFct};

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
        std::cout << "BalanceWeightUpdateER:Ok" << std::endl;
    }
}

/**/
void Logger::QeoGamelleWeightUpdateFct(const qeo_event_reader_t *reader, const void *data, uintptr_t userdata) {
    qeo_animall_gamelle_NewWeight_t* msg = (qeo_animall_gamelle_NewWeight_t*) data;
    std::cout << "*****" << std::endl;
    std::cout << "*\t" << "GamelleWeightUpdate:" << std::endl;
    std::cout << "*\t\t" << "uuid:" << "\t\t" << msg->uuid << std::endl;
    std::cout << "*\t\t" << "weight:" << "\t\t" << msg->weight << std::endl;
    std::cout << "*\t\t" << "timestamp:" << "\t" << msg->timestamp << std::endl;
    std::cout << "*****" << std::endl;
}

qeo_event_reader_listener_t Logger::GamelleWeightUpdateLst = {.on_data = Logger::QeoGamelleWeightUpdateFct};

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
        std::cout << "GamelleWeightUpdateER:Ok" << std::endl;
    }
}

void Logger::waitExit() {
    std::string cmdExit = "exit";
    std::string cmd = "";
    do {
        std::cin >> cmd;
    } while (cmdExit.compare(cmd));
}

