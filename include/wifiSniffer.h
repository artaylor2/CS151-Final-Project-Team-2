/**
 * @file wifiSniffer.h
 * @author Taylor, Alixandra (artaylor2@students.nic.edu)
 * @brief Wifi sniffer declaration file
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
**/

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

// Open a filepath using a given ofstream object and validate it
bool openFile(ofstream &newStream, string filePath);

// Sniff the local wifi networks and store the SSIDs and strengths in a file
bool sniffWifi(char* deviceID = "wifi0", string filePath = "./sniffResults");