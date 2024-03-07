#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>

#define LOGGER Logger::GetLogger()

class Logger
{
public:
    void Log(const std::string& sMessage);
    //TODO: this whole function is sus. ... work as a string of ... , that doesn't
    // make any sence. the passed cstring is not really a cstring but some-
    // kind of formating tool, but at the same time it is a cstring with a 
    // message. really confusing function overall.
    void Log(const char* format, ...);
    //TODO: why have operators redefinition for singletons that doesn't really
    // have outside objects of themselfs?
    //Logger& operator<<(const std::string& sMessage);
    static Logger* GetLogger();

private:
    Logger() {};
    Logger(const Logger&) {};
    Logger& operator=(const Logger&) { return *this; };

    static const std::string m_LogFileName;
    static Logger* m_ptrLogger;
    static std::ofstream m_Logfile;
};
#endif //LOGGER_H