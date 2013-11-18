/* 
 * File:   main.cpp
 * Author: zeus
 *
 * Created on 18 novembre 2013, 12:59
 */

#include <cstdlib>

#include "AnimallObjectGamelle.hpp"
#include "AnimallToolQeoGamelle.hpp"
#include "AnimallToolCmd.hpp"

extern "C" {

}

#include "AnimallToolApiBalance.hpp"
#include "AnimallToolApiGamelle.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Animall::Tool::Cmd* cmd;
    cmd = new Animall::Tool::Cmd(argc, argv);
    delete cmd;
    //    Animall::Tool::Api::Balance::updateWeight(std::string("http://guardgamelle.local"), std::string("7e5516bd-bc3b-4e16-bcb1-f83159a1993b"), 5564.5, 4565456);
    return 0;
}

