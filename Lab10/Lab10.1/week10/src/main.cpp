/**
* @file week10.cpp
* @brief  Week 10, C++ Review and Warmup from CSI140
*
* @author Zachary Schwab
* @assignment 10.1
* @date 11/11/2020
* @credits
* 
*/

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>

#include "util.h"
using namespace std;

//runs the whole program
int main()
{
    srand(time(NULL));

    vector<string> S {"Micro", "Tiny", "Small", "Medium", "Large", "Jumbo"};
    cout << "Dumping the Vector of 6 Elements: ";
    for(string s : S) {cout << s + " ";}
    cout << endl << "Calling randomElement" << endl << randomElement(S) << endl;

    vector<double> V {20.1,21.3,44.55,0.1,0.4,0.5,0.8};
    cout << "Dumping the vector of doubles" << endl;
    for(double d : V) {cout << d << " ";}
    cout << endl;

    cout << "sum:" << sum(V) << endl;
    cout << "avg:" << avg(V) << endl;
    cout << "lowest:" << lowest(V) << endl;

    string strMessage = "The quick red fox jumped over the lazy brown dog";
    cout << "Calling camelCase with:" << strMessage << endl;

    camelCase(strMessage);
    cout << "strMessage after camelCase: " << strMessage << endl;
    return EXIT_SUCCESS;
}