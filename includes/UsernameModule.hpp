#ifndef USERNAME_MODULE_HPP
#define USERNAME_MODULE_HPP
#include "IMonitorModule.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>

class UsernameModule: public IMonitorModule
{
private:

public:
    UsernameModule();
    ~UsernameModule();
    UsernameModule(const UsernameModule &obj);
    std::string getFieldName();
    std::string getFieldValue();

};


#endif