/**
 * @file logger.h
 * @brief logs when the program was ran
 * @author Zachary Schwab
 * #assignment Lab 10.2
 * @date 11/11/2020
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

/**
 * @brief log the user
 * @date 11/14/2020
 * @param msg the message to output
 * @param programName the name of the program
 * @param logFile the file to output to
 */
bool log(std::string msg,  std::string programName, std::ofstream& logFile);

#endif