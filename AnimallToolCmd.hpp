/* 
 * File:   Animall.hpp
 * Author: zeus
 *
 * Created on 18 novembre 2013, 13:09
 */
#include <sstream>
#include <iostream>
#include <string>
#include <ostream>

#ifndef ANIMALL_HPP
#define	ANIMALL_HPP

namespace Animall {
    namespace Tool {

        //J'aurais pu faire une class compléte d'élément statique mais au cas où.

        class Cmd {
        public:
            Cmd(int argc, char** argv);
            ~Cmd();
        private:
            /**/

            void dispatchCmd(int argc, char** argv);
            void printHelp();

            /**/

            /**
             * Commande permettante de mettre à jour le poid d'une gamelle
             * @param uuid      identifiant de l'objet
             * @param weight    nouveau poid
             */
            void GamelleWeightUpdate(std::string uuid, float weight);

            /**
             * Commande pour GamelleWeightUpdate
             * @param argc
             * @param argv
             */
            void GamelleWeightUpdateCmd(int argc, char** argv);
            /**
             * Affiche l'aide de la commande
             */
            void GamelleWeightupdateHelp();

            /**/

            /**
             * Commande permettante de mettre à jour le poid d'une balance
             * @param uuid      identifiant de l'objet
             * @param weight    nouveau poid
             */
            void BalenceWeightUpdate(std::string uuid, float weight);

            /**
             * Commande pour BalanceWeightUpdate
             * @param argc
             * @param argv
             */
            void BalenceWeightUpdateCmd(int argc, char** argv);
            /**
             * Affiche l'aide de la commande
             */
            void BalanceWeightupdateHelp();

            /**/

            void LoggerCmd(int argc, char** argv);

            void Logger(std::string scope, std::string s_scope);

            void LoggerHelp();

            /**/

            void GamelleRemplieCmd(int argc, char** argv);

            void GamelleRemplie(std::string uuid, float diff, float newweight);

            void GamelleremplieHelp();

            /**/

            void GamelleMangerCmd(int argc, char** argv);

            void GamelleManger(std::string uuid, float diff, float newweight);

            void GamelleMangerHelp();

            /**/
        };
    }
}

#endif	/* ANIMALL_HPP */

