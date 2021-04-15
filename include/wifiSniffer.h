/**
 * @file wifiSniffer.h
 * @author Taylor, Alixandra (artaylor2@students.nic.edu)
 * @brief Wifi sniffer declaration file
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
**/

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <iwlib.h>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::vector;

bool openFile(ofstream &newStream, string filePath);
bool sniffWifi(char* deviceID = "wifi0", string filePath = "./sniffResults");