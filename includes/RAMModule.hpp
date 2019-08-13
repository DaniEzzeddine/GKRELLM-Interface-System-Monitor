#ifndef RAM_MODULE_HPP
#define RAM_MODULE_HPP
#include "IMonitorModule.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <sys/sysctl.h>
#include "bytes.hpp"
#include <fstream>
#include <iomanip>
class RAMModule: public IMonitorModule
{
private:

public:
    RAMModule();
    ~RAMModule();
    RAMModule(const RAMModule &obj);
    std::string getFieldName();
    std::string getFieldValue();

};


#endif