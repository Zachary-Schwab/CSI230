//Zachary Schwab
#include <cstdlib>
#include <cstring>

#include "util.h"

//picks a random element from a string array
string randomElement(vector<string> V)
{
    int randomNum = rand() % V.size();
    return V[randomNum];
}

//sums all the doubles from a double vector
double sum(vector<double> V)
{
    double total;
    for(int i = 0; i < V.size(); i++)
    {
        total += V[i];
    }
    return total;
}

//averages all the doubles from a double vector
double avg(vector<double> V)
{
    return  sum(V)/V.size();   
}

//returns the lowest double from a double vector
double lowest(vector<double> V)
{
    //sets lowest as max so that no matter the double the first will be set as lowest.
    double lowest = __DBL_MAX__;
    for(int i = 0; i < V.size(); i++)
    {
        if(V[i] < lowest)
        {
            lowest = V[i];
        }
    }
    return lowest;
}

//converts a multi word string to camel case format
string camelCase(string& S)
{
    int i = 0;
    bool capitalize = false;
    S[0] = tolower(S[0]);

    while(i < S.length())
    {   
        i++;
        char substr = S[i];

        if(capitalize && substr != ' ')
        {
            S[i] = toupper(S[i]);
            capitalize = false;
            continue;   
        }
        else
        {
            S[i] = tolower(S[i]);
        }
        //if a space make sure the next letter is capitalized
        if (substr == ' ')
        {
            capitalize = true;
            for(int j = i; j < S.length(); j++)
            {
                S[j] = S[j+1];
            }
               S.pop_back();
               i--;
        }    
    }
    return S;
}