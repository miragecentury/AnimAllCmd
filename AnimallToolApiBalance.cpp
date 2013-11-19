#include "AnimallToolApiBalance.hpp"

using namespace Animall::Tool::Api;

void Balance::updateWeight(std::string urlBase, std::string uuid, float weight, int timestamp) {
    std::ostringstream* os;
    std::string exec = "";
    std::string cmd = "curl ";
    std::string url = "/api/v1/balance/push";
    std::string sweight;
    std::string stimestamp;
    int ret = 0;
    os = new std::ostringstream();
    (*os) << weight;
    sweight = os->str();
    delete os;
    os = new std::ostringstream();
    (*os) << timestamp;
    stimestamp = os->str();
    delete os;

    exec = cmd + urlBase + url + " --data '{\"id\":\"" + uuid + "\",\"date\":" + stimestamp + ",\"state\":" + sweight + "}'";
    ret = system(exec.c_str());
    std::cout << std::endl;
}