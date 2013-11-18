/* 
 * File:   AnimallToolQeoGamelle.hpp
 * Author: zeus
 *
 * Created on 18 novembre 2013, 13:15
 */

// Lib std
#include <time.h>       //récupére les fonctions times (héritée du c inchangé)
#include <cstdlib>      //récupére les fonctions c de la stdlib importé pour le c++
#include <iostream>

// Projet
#include "AnimallObjectGamelle.hpp"

extern "C" {
    //QEO
#include <qeo/api.h>
#include <qeo/error.h>
    //Projet
#include "QeoAnimalEventMessage.h"
}

#ifndef ANIMALLTOOLQEOGAMELLE_HPP
#define	ANIMALLTOOLQEOGAMELLE_HPP

namespace Animall {
    namespace Tool {
        namespace Qeo {

            class Gamelle {
            public:
                /**
                 * Constructeur de l'outils de communication Qeo
                 * @param Animall::Object::Gamelle* gamelle
                 * pointeur vers un objet Gamelle
                 */
                Gamelle(Animall::Object::Gamelle* gamelle);

                /**
                 * Publie l'event correspondant sur Qeo
                 * @return bool true si ok / false si erreur
                 */
                bool publishNewWeight();

                /**
                 * Descturteur
                 */
                ~Gamelle();

            private:
                qeo_factory_t *qeo;
                qeo_event_writer_t *msg_writer;
                qeo_animall_gamelle_NewWeight_t* msg;
                Animall::Object::Gamelle* gamelle;
            };
        }
    }
}

#endif	/* ANIMALLTOOLQEOGAMELLE_HPP */

