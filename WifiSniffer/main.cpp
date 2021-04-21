/**
 * @file main.cpp
 * @author Taylor, Alixandra (artaylor2@students.nic.edu)
 * @brief Test driver for wifi sniffer
 * @version 0.1
 * @date 2021-04-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>

#include "wifiSniffer.h"

using std::cout;
using std::string;

int main()
{
    // Get the system's current wireless device
    string curID = getDeviceID();

    // Validate the returned value
    if(!curID.empty())
    {
        cerr << "Wifi device unavailable." << endl
             << "Cancelling scan." << endl << endl;
    }
    else
    {
        // Sniff the system's current wifi signals on that device
        // Variable is passed as a pointer to first char to convert from
        // string to c-string
        sniffWifi(&curID[0]);
    }

    return 0;
}