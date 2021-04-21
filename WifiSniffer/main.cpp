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

#include "wifiSniffer.h"

int main()
{
    // Get the system's current wireless device
    string curID = getDeviceID();
    cout << curID << " as device" << endl;

    // Sniff the system's current wifi signals on that device
    sniffWifi(&curID[0]);

    return 0;
}