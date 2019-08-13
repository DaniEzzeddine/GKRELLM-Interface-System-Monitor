#ifndef NETWORK_MODULE_HPP
#define NETWORK_MODULE_HPP
#include "IMonitorModule.hpp"
#include <string>
#include <sstream>
#include <iostream>
class NetworkModule: public IMonitorModule
{
private:

public:
    NetworkModule();
    ~NetworkModule();
    NetworkModule(const NetworkModule &obj);
    std::string getFieldName();
    std::string getFieldValue();

};


#endif