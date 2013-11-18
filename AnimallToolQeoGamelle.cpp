#include "AnimallToolQeoGamelle.hpp"

using namespace Animall::Tool::Qeo;

Gamelle::Gamelle(Animall::Object::Gamelle* gamelle) {
    this->gamelle = gamelle;
}

Gamelle::~Gamelle() {

}

bool Gamelle::publishNewWeight() {
    int32_t timestamp = 0;
    qeo_retcode_t retC;
    // malloc à l'ancienne car structure c
    this->msg = (qeo_animall_gamelle_NewWeight_t*) malloc(sizeof (qeo_animall_gamelle_NewWeight_t));

    this->msg->from = (char*) this->gamelle->getUuid().c_str();
    this->msg->weight = this->gamelle->getWeight();
    this->msg->timestamp = timestamp;

    this->qeo = qeo_factory_create();
    if (this->qeo != NULL) {
        this->msg_writer = qeo_factory_create_event_writer(qeo, qeo_animall_gamelle_NewWeight_type, NULL, 0);
        if (this->msg_writer != NULL) {
            retC = qeo_event_writer_write(this->msg_writer, this->msg);
            retC = qeo_event_writer_write(this->msg_writer, this->msg);
            if (retC == QEO_OK) {
                std::cout << "OK" << std::endl;
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
}
