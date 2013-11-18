/* 
 * File:   AnimallObjectBalance.hpp
 * Author: zeus
 *
 * Created on 18 novembre 2013, 14:50
 */

#include <string>

#ifndef ANIMALLOBJECTBALANCE_HPP
#define	ANIMALLOBJECTBALANCE_HPP

namespace Animall {
    namespace Object {

        /**
         */
        class Balance {
        public:
            /**
             * 
             * @param uuid
             */
            Balance(std::string uuid);

            /**
             * Modifie le nouveau poids
             * @param float newWeight
             */
            void setWeight(float newWeight);

            /**
             * récupére le poids
             * @return float poids
             */
            float getWeight();

            /**
             * Récupère l'identifiant unique
             * @return 
             */
            std::string getUuid();

            /**
             * 
             */
            ~Balance();
        private:
            std::string uuid;
            float weight;
        };
    }
}

#endif	/* ANIMALLOBJECTBALANCE_HPP */

