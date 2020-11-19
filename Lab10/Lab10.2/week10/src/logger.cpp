/**
 * @file logger.h
 * @brief logs when the program was ran
 * @author Zachary Schwab
 * #assignment Lab 10.2
 * @date 11/11/2020
 */

#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include "logger.h"
#include <limits.h>

bool log(std::string msg, std::string programName, std::ofstream& logFile)
{
    std::string strTime;

    time_t logTime = time(0);
    strTime = ctime(&logTime);

    int timeSize = strTime.size();
    if(timeSize)
    {
        strTime[timeSize - 1] = ' ';
    }
    char hostname[HOST_NAME_MAX];
    int temp = gethostname(hostname, HOST_NAME_MAX);

    if(logFile)
    {
        logFile << strTime << hostname << " " << programName << "[" << getpid() << "]: " << msg  << std::endl; 
        return true;
    }
    else
    {
        return false;
    }
    
}