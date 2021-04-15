/**
 * @file wifiSniffer.cpp
 * @author Taylor, Alixandra (artaylor2@students.nic.edu)
 * @brief Wifi sniffer definition file
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "wifiSniffer.h"

bool sniffWifi(char* deviceID, string filePath)
{
    wireless_scan_head resultHead;
    wireless_scan *resultPtr;
    iwrange range;
    int socket;

    socket = iw_sockets_open();

    // Gather metadata for the scan
    if (iw_get_range_info(socket, deviceID, &range) < 0) 
    {
        cerr << "Error during iw_get_range_info. Scan incomplete." << endl;
        return false;
    }

    // Perform the sca
    if (iw_scan(socket, deviceID, range.we_version_compiled, &resultHead) < 0) 
    {
        cerr << "Error during iw_scan. Scan incomplete." << endl;
        return false;
    }

    while(resultPtr != nullptr)
    {
        cout << resultPtr->b.essid << endl
             << resultPtr->stats.qual.level << endl;
    }
    
    return true;
}

bool openFile(ofstream &newStream, string filePath)
{
    try
    {
        newStream.open(filePath);
        
        if(!newStream.is_open())
        {
            throw string("File could not be opened.");
        }
    }
    catch(const string &s)
    {
        cerr << s << '\n';
        return false;
    }

    return true;   
}