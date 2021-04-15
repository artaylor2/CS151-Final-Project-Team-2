/**
 * @file wifiSniffer.h
 * @author Taylor, Alixandra (artaylor2@students.nic.edu)
 * @brief Wifi sniffer declaration file
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
**/

/**
 * IMPORTANT NOTE!
 * To compile this library make sure to install libiw-dev
 *      sudo apt-get install libiw-dev
 * 
 * And when compiling attach a -liw flag at the end of the compilation command
 * This flag will ensure that the library is properly linked to the header
 *      Ex:
 *      g++ -std=c++11 -Wall -Wextra wifiSniffer.cpp -liw
 * 
 *      note: The current structure of this code is designed around typecasting c-strings which is
 *            not allowed under ISO C++. This header will not compile with the -pedantic flag.
 */

#include <fstream>      // ofstream
#include <iostream>     // cerr and cout
#include <stdio.h>      // c-string handling for iwlib
#include <string>       // string handling for easier file manip
#include <time.h>       // time handling for iwlib
#include <iwlib.h>      // wireless tools / scanning library
#include <vector>       // vector<wireless_scan>()

using std::cerr;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::vector;

struct scanResult
{
    string ssid;
    int strength;
};

// Open a filepath using a given ofstream object and validate it
bool openFile(ofstream &newStream, string filePath);

// Sniff the local wifi networks and store the SSIDs and strengths in a file
bool sniffWifi(char* deviceID = "wifi0", string filePath = "./sniffResults");