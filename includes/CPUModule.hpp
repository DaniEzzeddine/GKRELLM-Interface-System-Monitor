#ifndef CPU_MODULE_HPP
#define CPU_MODULE_HPP
#include <iostream>
#include "IMonitorModule.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
class CPUModule: public IMonitorModule
{
private:

public:
    CPUModule();
    ~CPUModule();
    CPUModule(const CPUModule &obj);
    std::string getFieldName();
    std::string getFieldValue();

};


#endif