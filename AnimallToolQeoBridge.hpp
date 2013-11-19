/* 
 * File:   AnimallToolQeoBridge.hpp
 * Author: zeus
 *
 * Created on 18 novembre 2013, 20:19
 */

#include <iostream>
#include <cstdlib>
#include "AnimallToolApiBalance.hpp"
#include "AnimallToolApiGamelle.hpp"
extern "C" {
#include "QeoAnimalEventMessage.h"
#include <qeo/api.h>
}

#ifndef ANIMALLTOOLQEOBRIDGE_HPP
#define	ANIMALLTOOLQEOBRIDGE_HPP

namespace Animall {
    namespace Tool {
        namespace Qeo {

            class Bridge {
            public:
                Bridge(std::string baseUrl);
                ~Bridge();
                /**/
                bool addGamelle();
                bool addGamelleWeightUpdate();
                static qeo_event_reader_listener_t GamelleWeightUpdateLst;
                static void QeoBalanceWeightUpdateFct(const qeo_event_reader_t *reader, const void *data, uintptr_t userdata);
                /**/
                bool addBalance();
                bool addBalanceWeightUpdate();
                static qeo_event_reader_listener_t BalanceWeightUpdateLst;
                static void QeoGamelleWeightUpdateFct(const qeo_event_reader_t *reader, const void *data, uintptr_t userdata);
                /**/
                static std::string baseUrl;
            private:
                bool err;
                qeo_factory_t *qeo;



                qeo_event_reader_t* BalanceWeightUpdateER;
                qeo_event_reader_t* GamelleWeightUpdateER;
            };
        }
    }
}

#endif	/* ANIMALLTOOLQEOBRIDGE_HPP */

