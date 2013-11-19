

#include "AnimallToolCmd.hpp"

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
    std::string cmdLogger = "Logger";
    std::string cmdDev = "Dev";
    std::string cmdBridge = "Bridge";
    std::string cmdNao = "Nao";

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
    if (exec == false && !cmdLogger.compare(argv[1])) {
        this->LoggerCmd(argc, argv);
        exec = true;
    }
    if (exec == false && !cmdBridge.compare(argv[1])) {
        this->BridgeDaemonCmd(argc, argv);
        exec = true;
    }
    if (exec == false && !cmdDev.compare(argv[1])) {
        this->DevCmd(argc, argv);
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
    std::cout << "\t" << "Logger" << " args... : " << "Log sur la sortie standart des events" << std::endl;
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
        } else {
            std::cout << "Trop peu d'argument ou incohérent" << std::endl;
            this->BalanceWeightupdateHelp();
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
        } else {
            std::cout << "Trop peu d'argument ou incohérent" << std::endl;
            this->GamelleWeightupdateHelp();
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

void Cmd::LoggerCmd(int argc, char** argv) {
    std::string cmdHelp = "help";
    std::string cmdAll = "all";
    std::string cmdGamelle = "Gamelle";
    std::string cmdBalance = "Balance";
    bool exec = false;
    if (argc >= 2) {
        if (argc >= 3) {
            if (!cmdHelp.compare(argv[2])) {
                this->LoggerHelp();
                exec = true;
            }
            if (!cmdAll.compare(argv[2])) {
                this->Logger(cmdAll, "");
                exec = true;
            }
            if (!cmdGamelle.compare(argv[2])) {
                this->Logger(cmdGamelle, "");
                exec = true;
            }
            if (!cmdBalance.compare(argv[2])) {
                this->Logger(cmdBalance, "");
                exec = true;
            }
            if (exec == false) {
                std::cout << "Logger Aucun Scope ne correspond" << std::endl;
            }
        }
    } else {
        std::cout << "Trop peu d'arguments" << std::endl;
        this->LoggerHelp();
    }
}

void Cmd::Logger(std::string scope, std::string s_scope) {
    Animall::Tool::Qeo::Logger* logger = new Animall::Tool::Qeo::Logger();
    if (!scope.compare("all")) {
        std::cout << "All Log :" << std::endl;
        logger->addAll();
    }
    if (!scope.compare("Gamelle")) {
        logger->addBalance();
    }
    if (!scope.compare("Balance")) {
        logger->addGamelle();
    }
    logger->waitExit();
    delete logger;
}

void Cmd::LoggerHelp() {
    std::cout << "Logger :Aide:" << std::endl;
    std::cout << "Arguments possible" << std::endl;
    std::cout << "\tLogger" << " " << "help" << " : " << "affiche cette aide" << std::endl;
    std::cout << "\tLogger" << " " << "scope [sous_scope]" << " : " << "Log les events dans le scope" << std::endl;
    std::cout << "\t\t - " << "scope" << "\t\t: " << "" << "\texemple: " << "all|Gamelle|Balance" << std::endl;
}

/**/

void Cmd::DevCmd(int argc, char** argv) {
    this->Dev(argc, argv);
}

void Cmd::Dev(int argc, char** argv) {
    Animall::Tool::Api::Balance::updateWeight(std::string(""), std::string(""), 562.3, (int) time(NULL));
    Animall::Tool::Api::Gamelle::updateWeight(std::string(""), std::string(""), 562.3, (int) time(NULL));
}

void Cmd::DevHelp() {

}

/**/

void Cmd::BridgeDaemonCmd(int argc, char** argv) {
    this->BridgeDaemon(std::string(""));
}

void Cmd::BridgeDaemon(std::string urlBase) {
    if (!urlBase.compare("")) {
        urlBase = "http://guardgamelle.local";
    }
    Animall::Object::Bridge* br = new Animall::Object::Bridge(urlBase);
    br->~Bridge();
}

void Cmd::BridgeDaemonHelp() {

}

/**/