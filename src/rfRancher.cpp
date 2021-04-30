/**
 * @file rfRancher.cpp
 * @author Jacob Porath
 * @brief Definition file for rfRancher functions
 * @date 2021-04-29
 */
#include "rfRancher.h"

/**
 * @brief Uses wifiSniffer functions to find the strongest signal strength wifi network and return its ssid
 * 
 * @return std::string SSID of the strongest signal strength network
 */
std::string ssidScan()
{
	std::string wifiID = "";

	try
	{
    	wifiID = getDeviceID();
	}
	catch(std::logic_error err) // Throws error if can't find system files (wsl causes problems here)
	{

	}

	if(!wifiID.empty())
	{
		if(!sniffWifi(&wifiID[0], "./bin/scans/sniffResults"))
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
	std::string ssid = "";
	getline(in, ssid);
	in.close(); // Close the file
    return ssid;
}

/**
 * @brief hashes the string into a large random number 
 * 
 * @param ssid string to be hashed (network ssid)
 * @return int hash result
 */
int hashSsid(std::string ssid)
{
    int total = 1;
    for(int i = 0; i < ssid.size(); i++)
    {
        total *= ssid[i]; // multiply by each ascii value
        total = total % 9999999 + 1000000; // limit number growth to prevent overflow and zero values
    }
    total = abs(total);
    return total;
}

/**
 * @brief determines what monster type the hash value should correspond to
 * 
 * @param ssidHash hashed ssid value
 * @return int monster type corresponding to enum in rfRancher.h
 */
int determineType(int ssidHash)
{
    return ssidHash % 6;
} // Returns enum defined in rfRancher.h