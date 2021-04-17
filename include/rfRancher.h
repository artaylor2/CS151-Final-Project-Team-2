#ifndef RFRANCHER_H
#define RFRANCHER_H

#include <iostream>
#include <fstream>
#include <sstream>

enum monstTypes {Ghost, Fire, Water, Forest, Rock, Ice};

std::string findStrongest(std::ifstream &in);
int hashSsid(std::string ssid);
int determineType(int ssidHash);

#endif