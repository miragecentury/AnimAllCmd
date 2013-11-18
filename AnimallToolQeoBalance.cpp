#include "AnimallToolQeoBalance.hpp"

using namespace Animall::Tool::Qeo;

Balance::Balance(Animall::Object::Balance* gamelle) {
    this->balance = gamelle;
}

Balance::~Balance() {

}

bool Balance::publishNewWeight() {
    int32_t timestamp = 0;
    qeo_retcode_t retC;
    bool rt = false;
    ;
    // malloc à l'ancienne car structure c
    this->msg = (qeo_animall_balance_NewWeight_t*) malloc(sizeof (qeo_animall_balance_NewWeight_t));

    this->msg->uuid = (char*) this->balance->getUuid().c_str();
    this->msg->weight = this->balance->getWeight();
    this->msg->timestamp = timestamp;

    this->qeo = qeo_factory_create();
    if (this->qeo != NULL) {
        this->msg_writer = qeo_factory_create_event_writer(qeo, qeo_animall_balance_NewWeight_type, NULL, 0);
        if (this->msg_writer != NULL) {
            retC = qeo_event_writer_write(this->msg_writer, this->msg);
            retC = qeo_event_writer_write(this->msg_writer, this->msg);
            if (retC == QEO_OK) {
                std::cout << "OK" << std::endl;
                rt = true;
            } else {
                std::cout << "ERR" << std::endl;
            }
            qeo_event_writer_close(this->msg_writer);
        } else {
            std::cout << "Qeo Factory Create Event Writer return NULL " << std::endl;
        }
        qeo_factory_close(this->qeo);
    } else {
        std::cout << "Qeo Factory Create return NULL" << std::endl;
    }
    // free à l'ancienne car structure XD
    free(this->msg);
    return rt;
}
