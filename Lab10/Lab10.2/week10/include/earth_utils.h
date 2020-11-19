/**
 * @file earth_utils.h
 * @brief impliments google earth processing
 * @author Zachary Schwab
 * #assignment Lab 10.2
 * @date 11/18/2020
 */


#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H
#include <string>
#include <fstream>

/**
 * @brief log the user
 * @date 11/16/2020
 * @param msg the message to output
 * @param programName the name of the program
 * @param logFile the file to output to
 */
int processCSV(std::ifstream& inFile, std::string kmlFileName);

/**
 * @brief log the user
 * @date 11/18/2020
 * @param kmlFile the file to output to
 * @param name name of the country
 * @param latitude latitdude of the country
 * @param longitude longitude of the country
 */
int WritePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitude);
#endif