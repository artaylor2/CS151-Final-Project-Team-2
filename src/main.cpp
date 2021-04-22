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
	if(string wifiID = getDeviceID())
	{
		if(!sniffWifi(wifiID))
		{
			cerr << "Scan failed, using old data." << endl;
		}
	}
	else
	{
		cerr << "Couldn't get device ID, using old data." << endl;
	}
	
	// Open sniffer results file
	std::ifstream in("bin/scans/sniffResults");
	if(!in.is_open())
	{
		std::cerr << "File failed to open\n";
		std::exit(1);
	}

	// Get strongest ssid
	std::string ssid;
	getline(in, ssid);
	in.close(); // Close the file

	// Generate randoom number from ssid
	int ssidHash = hashSsid(ssid);

	// Determine monster type
	int type = determineType(ssidHash);

	// Temp monster creation for testing base class
	// MonsterBase monster(ssidHash);
	// std::cout << monster.toStr() << '\n';


	// Create monster instance
	switch (type)
	{
		case Ghost:
		{
			GhostType ghost(ssidHash);
			std::cout << ghost.toStr() << '\n';
			break;
		}
		case Fire:
		{
			FireType fire(ssidHash);
			std::cout << fire.toStr() << '\n';
			break;
		}
		case Water:
		{
			WaterType water(ssidHash);
			std::cout << water.toStr() << '\n';
			break;
		}
		case Forest:
		{
			ForestType forest(ssidHash);
			std::cout << forest.toStr() << '\n';
			break;
		}
		case Rock:
		{
			RockType rock(ssidHash);
			std::cout << rock.toStr() << '\n';
			break;
		}
		case Ice:
		{
			IceType ice(ssidHash);
			std::cout << ice.toStr() << '\n';
			break;
		}
	}

	return 0;
}