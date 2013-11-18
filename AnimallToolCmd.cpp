
#include <sstream>

#include "AnimallToolCmd.hpp"
#include "AnimallObjectGamelle.hpp"
#include "AnimallObjectBalance.hpp"
#include "AnimallToolQeoGamelle.hpp"
#include "AnimallToolQeoBalance.hpp"

using namespace Animall::Tool;

Cmd::Cmd(int argc, char** argv) {
    if (argc > 1) {
        this->dispatchCmd(argc, argv);
    } else {
        std::cout << "Aucun argument passé à la commande" << std::endl;
        this->printHelp();
    }
}

Cmd::~Cmd() {

}

void Cmd::dispatchCmd(int argc, char** argv) {
    std::string cmdHelp = "help";
    std::string cmdBalenceWeightUpdate = "BalanceUpdate";
    std::string cmdGamelleWeightUpdate = "GamelleUpdate";
    bool exec = false;
    if (exec == false && !cmdHelp.compare(argv[1])) {
        this->printHelp();
        exec = true;
    }
    if (exec == false && !cmdBalenceWeightUpdate.compare(argv[1])) {
        this->BalenceWeightUpdateCmd(argc, argv);
        exec = true;
    }
    if (exec == false && !cmdGamelleWeightUpdate.compare(argv[1])) {
        this->GamelleWeightUpdateCmd(argc, argv);
        exec = true;
    }

    /**/
    if (exec == false) {
        std::cout << "Aucune Commande ne corresponde" << std::endl;
        this->printHelp();
    }
}

void Cmd::printHelp() {
    std::cout << "Help:" << std::endl;
    std::cout << "Pour avoir plus d'infos sur une commande: cmd help" << std::endl;
    std::cout << "Liste des Commandes:" << std::endl;
    std::cout << "\t" << "BalanceUpdate" << " args... : " << "Mise à jour du poid pour une balance" << std::endl;
    std::cout << "\t" << "GamelleUpdate" << " args... : " << "Mise à jour du poid pour une gamelle" << std::endl;
}

void Cmd::BalenceWeightUpdateCmd(int argc, char** argv) {
    std::string cmdHelp = "help";
    std::stringstream ss;
    float newweight;
    std::string uuid;
    if (argc >= 2) {
        if (argc >= 3) {
            if (!cmdHelp.compare(argv[2])) {
                this->BalanceWeightupdateHelp();
            } else {
                if (argc >= 4) {
                    uuid = argv[2];
                    ss.str(argv[3]);
                    ss >> newweight;
                    this->BalenceWeightUpdate(uuid, newweight);
                } else {
                    std::cout << "Trop peu d'argument ou incohérent" << std::endl;
                    this->BalanceWeightupdateHelp();
                }
            }
        }
    } else {
        std::cout << "Trop peu d'arguments" << std::endl;
        this->BalanceWeightupdateHelp();
    }
}

void Cmd::BalanceWeightupdateHelp() {
    std::cout << "BalanceUpdate :Aide:" << std::endl;
    std::cout << "Arguments possible" << std::endl;
    std::cout << "\tBalanceUpdate" << " " << "help" << " : " << "affiche cette aide" << std::endl;
    std::cout << "\tBalanceUpdate" << " " << "uuid newweight" << " : " << "affiche cette aide" << std::endl;
    std::cout << "\t\t - " << "uuid" << "\t\t: " << "identifiant unique de l'appareil" << "\texemple: " << "qjjdkqsd-456q4sd-546546" << std::endl;
    std::cout << "\t\t - " << "newweight" << "\t: " << "nouveau poids de l'animal en g" << "\texemple: " << "11542.56" << std::endl;
}

void Cmd::BalenceWeightUpdate(std::string uuid, float weight) {
    Animall::Object::Balance* balance;
    Animall::Tool::Qeo::Balance* balanceQeo;
    balance = new Animall::Object::Balance(uuid);
    balance->setWeight(weight);
    balanceQeo = new Animall::Tool::Qeo::Balance(balance);
    balanceQeo->publishNewWeight();
    delete balanceQeo;
    delete balance;
}

void Cmd::GamelleWeightUpdateCmd(int argc, char** argv) {
    std::string cmdHelp = "help";
    std::stringstream ss;
    float newweight;
    std::string uuid;
    if (argc >= 2) {
        if (argc >= 3) {
            if (!cmdHelp.compare(argv[2])) {
                this->GamelleWeightupdateHelp();
            } else {
                if (argc >= 4) {
                    uuid = argv[2];
                    ss.str(argv[3]);
                    ss >> newweight;
                    this->GamelleWeightUpdate(uuid, newweight);
                } else {
                    std::cout << "Trop peu d'argument ou incohérent" << std::endl;
                    this->GamelleWeightupdateHelp();
                }
            }
        }
    } else {
        std::cout << "Trop peu d'arguments" << std::endl;
        this->GamelleWeightupdateHelp();
    }
}

void Cmd::GamelleWeightUpdate(std::string uuid, float weight) {
    Animall::Object::Gamelle* gamelle;
    Animall::Tool::Qeo::Gamelle* gamelleQeo;
    gamelle = new Animall::Object::Gamelle(uuid);
    gamelle->setWeight(weight);
    gamelleQeo = new Animall::Tool::Qeo::Gamelle(gamelle);
    gamelleQeo->publishNewWeight();
    delete gamelleQeo;
    delete gamelle;
}

void Cmd::GamelleWeightupdateHelp() {
    std::cout << "GamelleUpdate :Aide:" << std::endl;
    std::cout << "Arguments possible" << std::endl;
    std::cout << "\tGamelleUpdate" << " " << "help" << " : " << "affiche cette aide" << std::endl;
    std::cout << "\tGamelleUpdate" << " " << "uuid newweight" << " : " << "affiche cette aide" << std::endl;
    std::cout << "\t\t - " << "uuid" << "\t\t: " << "identifiant unique de l'appareil" << "\texemple: " << "qjjdkqsd-456q4sd-546546" << std::endl;
    std::cout << "\t\t - " << "newweight" << "\t: " << "nouveau poids de l'animal en g" << "\texemple: " << "11542.56" << std::endl;
}