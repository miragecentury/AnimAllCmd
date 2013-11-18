/* 
 * File:   AnimallGamelle.hpp
 * Author: zeus
 *
 * Created on 18 novembre 2013, 13:04
 */

#include <string>

#ifndef ANIMALLGAMELLE_HPP
#define	ANIMALLGAMELLE_HPP

namespace Animall {
    namespace Object {

        /**
         */
        class Gamelle {
        public:
            /**
             * 
             * @param uuid
             */
            Gamelle(std::string uuid);

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
            ~Gamelle();
        private:
            std::string uuid;
            float weight;
        };
    }
}

#endif	/* ANIMALLGAMELLE_HPP */

