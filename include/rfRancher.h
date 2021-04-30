/**
 * @file rfRancher.h
 * @author Jacob Porath
 * @brief Header file for rfRancher functions
 * @date 2021-04-29
 */
#ifndef RFRANCHER_H
#define RFRANCHER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "wifiSniffer.h"

enum monstTypes {Undefined = -1, Ghost, Fire, Water, Forest, Rock, Ice};

std::string ssidScan();
int hashSsid(std::string ssid);
int determineType(int ssidHash);

#endif