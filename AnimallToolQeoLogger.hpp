/* 
 * File:   AnimallToolQeoLogger.hpp
 * Author: zeus
 *
 * Created on 18 novembre 2013, 17:25
 */

#include <iostream>
#include <cstdlib>

extern "C" {
#include "QeoAnimalEventMessage.h"
#include <qeo/api.h>
}

#ifndef ANIMALLTOOLQEOLOGGER_HPP
#define	ANIMALLTOOLQEOLOGGER_HPP

namespace Animall {
    namespace Tool {
        namespace Qeo {

            class Logger {
            public:
                Logger();
                ~Logger();
                void waitExit();
                /**/
                bool addAll();
                /**/
                bool addGamelle();
                bool addGamelleWeightUpdate();
                static qeo_event_reader_listener_t GamelleWeightUpdateLst;
                static void QeoGamelleWeightUpdateFct(const qeo_event_reader_t *reader, const void *data, uintptr_t userdata);
                /**/
                bool addBalance();
                bool addBalanceWeightUpdate();
                static qeo_event_reader_listener_t BalanceWeightUpdateLst;
                static void QeoBalanceWeightUpdateFct(const qeo_event_reader_t *reader, const void *data, uintptr_t userdata);
                /**/
            private:
                bool err;
                qeo_factory_t *qeo;

                qeo_event_reader_t* BalanceWeightUpdateER;
                qeo_event_reader_t* GamelleWeightUpdateER;
            };
        }
    }
}

#endif	/* ANIMALLTOOLQEOLOGGER_HPP */

