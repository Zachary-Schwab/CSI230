#include <cstdlib>
#include <cstring>

#include "util.h"

string randomElement(vector<string> V)
{
    int randomNum = rand() % V.size();
    return V[randomNum];
}

double sum(vector<double> V)
{
    double total;
    for(int i = 0; i < V.size(); i++)
    {
        total += V[i];
    }
    return total;
}
double avg(vector<double> V)
{
    return  sum(V)/V.size();   
}
double lowest(vector<double> V)
{
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

string camelCase(string& S)
{
    int i = 0;
    bool capitalize = false;
    S[0] = tolower(S[0]);

    while(i < S.length())
    {   
        i++;
        char substr = S[i];

        if(capitalize)
        {
            S[i] = toupper(S[i]);
            capitalize = false;
            continue;   
        }
        else
        {
            S[i] = tolower(S[i]);
        }
        
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