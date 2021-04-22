#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "rfRancher.h"
#include "forestType.h"
#include "waterType.h"
#include "fireType.h"
#include "rockType.h"
#include "iceType.h"
#include "ghostType.h"
#include "monsterBase.h"
#include "wifiSniffer.h"

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

	// Generate randoom number from ssid
	int ssidHash = hashSsid(ssid);

	// Determine monster type
	int type = determineType(ssidHash);

	// Temp monster creation for testing base class
	// MonsterBase monster(ssidHash);
	// std::cout << monster.toStr() << '\n';

	// CODE BELOW CURRENTLY BROKEN BUT WILL FIX SOON

	// Create monster instance
	// switch (type)
	// {
	// 	case Ghost:
	// 	{
	// 		GhostType ghost(ssid);
	// 		std::cout << ghost.toStr() << '\n';
	// 		break;
	// 	}
	// 	case Fire:
	// 	{
	// 		FireType fire(ssid);
	// 		std::cout << fire.toStr() << '\n';
	// 		break;
	// 	}
	// 	case Water:
	// 	{
	// 		WaterType water(ssid);
	// 		std::cout << water.toStr() << '\n';
	// 		break;
	// 	}
	// 	case Forest:
	// 	{
	// 		ForestType forest(ssid);
	// 		std::cout << forest.toStr() << '\n';
	// 		break;
	// 	}
	// 	case Rock:
	// 	{
	// 		RockType rock(ssid);
	// 		std::cout << rock.toStr() << '\n';
	// 		break;
	// 	}
	// 	case Ice:
	// 	{
	// 		IceType ice(ssid);
	// 		std::cout << ice.toStr() << '\n';
	// 		break;
	// 	}
	// }

	return 0;
}