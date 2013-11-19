/* 
 * File:   AnimallObjectBridge.hpp
 * Author: zeus
 *
 * Created on 19 novembre 2013, 15:19
 */

#include <map>

#include "AnimallToolQeoBridge.hpp"

#ifndef ANIMALLOBJECTBRIDGE_HPP
#define	ANIMALLOBJECTBRIDGE_HPP

namespace Animall {
    namespace Object {

        class Bridge {
        public:
            Bridge(std::string baseUrl);
            ~Bridge();
        private:
            void initListen();
            void wait();
            Animall::Tool::Qeo::Bridge* qeoBr;
            std::string urlBase;
        };
    }
}

#endif	/* ANIMALLOBJECTBRIDGE_HPP */

