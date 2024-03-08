#include "Logger.h"
#include"Utilities.h"

//TODO: Is there any reason why we declare members outside the constructor? mb because they are
//static inside of class? 

const std::string Logger::m_LogFileName = "Log.txt";
Logger* Logger::m_ptrLogger = NULL;
std::ofstream Logger::m_Logfile;
//TODO: need to look up the filesystem and fstream documentation, to understand the workings
//with files. or better yet look up how files work with each other in general, without
//standard librarys


Logger* Logger::GetLogger()
{
    if (m_ptrLogger == NULL)
    {
        m_ptrLogger = new Logger();
        m_Logfile.open(m_LogFileName.c_str(), std::ios::out | std::ios::app);
        //TODO: what happens with open files? they are opened in the background and take ap
        //process power, or are they just market, so that in the process of writing or 
        //reading to/from the file it will open the file, not before that?
    }
    return m_ptrLogger;
}

void Logger::Log(const char* format, ...)
{
    char* sMessage = NULL;
    int nLength = 0;
    //TODO: variadic functions for char* storage with start, end, copy and arg functionality
    //question: reason not to use simple const char* or string?
    va_list args;
    va_start(args, format);

    nLength = _vscprintf(format, args) + 1;
    sMessage = new char[nLength];
    vsprintf_s(sMessage, nLength, format, args);
    //vsprintf(sMessage, format, args);
    m_Logfile << Util::CurrentDateTime() << ":\t";
    m_Logfile << sMessage << "\n";
    va_end(args);

    delete[] sMessage;
}

void Logger::Log(const std::string& sMessage)
{
    m_Logfile << Util::CurrentDateTime() << ":\t";
    m_Logfile << sMessage << "\n";
}

/*

*/
Logger& Logger::operator<<(const std::string& sMessage)
{
    m_Logfile << "\n" << Util::CurrentDateTime() << ":\t";
    m_Logfile << sMessage << "\n";
    return *this;
}
