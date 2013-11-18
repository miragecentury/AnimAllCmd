/* 
 * File:   AnimallToolApiBalance.hpp
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

#ifndef ANIMALLTOOLAPIBALANCE_HPP
#define	ANIMALLTOOLAPIBALANCE_HPP

namespace Animall {
    namespace Tool {
        namespace Api {

            class Balance {
            public:
                static void updateWeight(std::string urlBase, std::string uuid, float weight, int timestamp);
            private:
            };
        }
    }
}

#endif	/* ANIMALLTOOLAPIBALANCE_HPP */

