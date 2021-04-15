#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "rfRancher.h"
#include "monsterBase.h"
// #include "wifiSniffer.h"

int main(int argc, char *argv[])
{
	// Open wifisniffer file
	std::ifstream in("bin/scans/ResHallF1");
	if(!in.is_open())
	{
		std::cerr << "File failed to open\n";
		std::exit(1);
	}

	// Get strongest ssid
	std::string ssid = findStrongest(in);
	if(ssid == "")
	{
		std::cerr << "No monsters nearby :(\n";
		std::exit(1);
	}

	// Determine monster type
	int type = determineType(ssid);

	// Temp monster creation for testing
	MonsterBase monster(ssid);

	// Not yet implemented

	// // Create monster instance
	// switch (type)
	// {
	// case Ghost:
	// 	/* code */
	// 	break;
	// case Fire:
	// 	/* code */
	// 	break;
	// case Water:
	// 	/* code */
	// 	break;
	// case Forest:
	// 	/* code */
	// 	break;
	// case Rock:
	// 	/* code */
	// 	break;
	// case Ice:
	// 	/* code */
	// 	break;
	// }

	return 0;
}