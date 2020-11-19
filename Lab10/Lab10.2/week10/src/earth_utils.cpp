/**
 * @file earth_utils.cpp
 * @brief impliments google earth processing
 * @author Zachary Schwab
 * #assignment Lab 10.2
 * @date 11/18/2020
 */

#include "earth_utils.h"
#include <iostream>
#include <sstream>
int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    std::string strCountry, strCapital, strLat, strLong;
    std::string strLine;
    int recordCount = 0;

    if(inFile)
    {
        getline(inFile, strLine);

        std::ofstream kmlFile;
        kmlFile.open(kmlFileName);
        kmlFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
        kmlFile << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << std::endl;
        kmlFile << "<Document>" << std::endl;

        while(getline(inFile, strLine))
        {
            std::stringstream ss;
            ss << strLine;
            getline(ss,strCountry, ',');
            getline(ss,strCapital, ',');
            getline(ss,strLat, ',');
            getline(ss,strLong, ',');
            
            WritePlacemark(kmlFile, (strCapital + "," + strCountry), strLat, strLong);
            recordCount++;
        }
        kmlFile << "</Document>" << std::endl;
        kmlFile << "</kml>" << std::endl;
    }
    else
    {
        return 0;
    }
    

    return recordCount;
}

int WritePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitude)
{
    kmlFile << "<Placemark>" << std::endl;
    kmlFile << "<name>" << name << "</name>" << std::endl;
    kmlFile << "<Point><coordinates>" << longitude << "," << latitude << "</coordinates></Point>" << std::endl;
    kmlFile << "</Placemark>" << std::endl;
    return 1;
}