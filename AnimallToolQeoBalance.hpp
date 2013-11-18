/* 
 * File:   AnimallToolQeoBalance.hpp
 * Author: zeus
 *
 * Created on 18 novembre 2013, 14:49
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "AnimallObjectBalance.hpp"

extern "C" {
#include <unistd.h>
#include "QeoAnimalEventMessage.h"
#include <qeo/api.h>
}

#ifndef ANIMALLTOOLQEOBALANCE_HPP
#define	ANIMALLTOOLQEOBALANCE_HPP

namespace Animall {
    namespace Tool {
        namespace Qeo {

            class Balance {
            public:
                /**
                 * Constructeur de l'outils de communication Qeo
                 * @param Animall::Object::Gamelle* gamelle
                 * pointeur vers un objet Gamelle
                 */
                Balance(Animall::Object::Balance* Balance);

                bool publishNewWeight();

                /**
                 * Descturteur
                 */
                ~Balance();

            private:
                qeo_factory_t *qeo;
                qeo_event_writer_t *msg_writer;
                qeo_animall_balance_NewWeight_t* msg;
                Animall::Object::Balance* balance;
            };
        }
    }
}

#endif	/* ANIMALLTOOLQEOBALANCE_HPP */

