#include "DateTimeModule.hpp"


DateTimeModule::DateTimeModule(): IMonitorModule()
{
    const time_t my_time = time(NULL); 
    std::string temp(ctime(&my_time));
    _value = temp;
    _name = "Date/Time";
}

DateTimeModule::~DateTimeModule()
{
}


std::string DateTimeModule::getFieldName()
{
    return (_name);
}

std::string DateTimeModule::getFieldValue()
{
    const time_t my_time = time(NULL); 
    std::string temp(ctime(&my_time));
    _value = temp;
    return (_value);
}

