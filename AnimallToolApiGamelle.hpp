/* 
 * File:   AnimallToolApiGamelle.hpp
 * Author: zeus
 *
 * Created on 18 novembre 2013, 20:17
 */
#include <string>
#include <iostream>
#include <ios>
#include <iosfwd>
#include <sstream>

extern "C" {
#include <stdlib.h>
}

#ifndef ANIMALLTOOLAPIGAMELLE_HPP
#define	ANIMALLTOOLAPIGAMELLE_HPP

namespace Animall {
    namespace Tool {
        namespace Api {

            class Gamelle {
            public:
                static void updateWeight(std::string urlBase, std::string uuid, float weight, int timestamp);
            private:
            };
        }
    }
}

#endif	/* ANIMALLTOOLAPIGAMELLE_HPP */

