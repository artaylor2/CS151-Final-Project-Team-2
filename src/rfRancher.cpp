#include "rfRancher.h"

std::string findStrongest(std::ifstream &in)
{
    std::string tempS = "";
    std::string ssidStrongest = ""; // Current strongest ssid
    int strongest = 0; // Current strongest strength value
    int tempI = 0;
    while(getline(in, tempS))
    {
        in >> tempI;
        in.get(); // Get \n
        if(tempI > strongest)
        {
            ssidStrongest = tempS;
            strongest = tempI;
        }
    }
    return ssidStrongest; // Returns an empty string "" if there are no available ssids
}

int hashSsid(std::string ssid)
{
    int total = 1;
    for(int i = 0; i < ssid.size(); i++)
    {
        total *= ssid[i]; // multiply by each ascii value
        total = total % 9999999 + 1000000; // limit number growth to prevent overflow and zero values
    }
    total = abs(total);
    return total;
}

int determineType(int ssidHash)
{
    return ssidHash % 6;
    // int next = ssid[0]; // Get ascii value of first char
    // if(next <= 47)
    //     return Ghost;
    // else if(next <= 64)
    //     return Fire;
    // else if(next <= 80)
    //     return Water;
    // else if(next <= 96)
    //     return Forest;
    // else if(next <= 112)
    //     return Rock;
    // else
    //     return Ice;
} // Returns enum defined in rfRancher.h