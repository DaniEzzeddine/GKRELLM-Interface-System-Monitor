#ifndef DATE_TIME_MODULE_HPP
#define DATE_TIME_MODULE_HPP
#include "IMonitorModule.hpp"

class DateTimeModule: public IMonitorModule
{
private:

public:
    DateTimeModule();
    ~DateTimeModule();
    DateTimeModule(const DateTimeModule &obj);
    std::string getFieldName();
    std::string getFieldValue();

};


#endif