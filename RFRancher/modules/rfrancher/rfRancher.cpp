/**
 * @file fireType.cpp
 * @author Porath, Jacob & Taylor, Alixandra
 * @brief RfRancher monster and wifi wrapper object definitions
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "rfRancher.h"

/**
 * @brief getMonster() test that allows for custom SSIDs
 * 
 * @param curSSID The SSID to test
 * @return Node* A new monster object
 */
Node * RfRancher::testGetMonster(String curSSID)
{  
    // Seed the RNG
    srand(time(NULL));

    // If an empty SSID is retrieved generate a random monster instead.
    if(curSSID.empty())
    {
        curSSID += rand();
    }

    // Get new hash and type selection integer from the SSID
    int newHash = hashSsid(curSSID);
    int selection = newHash % 6;

    // Create monster pointer according to moduloed hash and return
    if(selection == 0)
    {
        GhostType* m = new GhostType;
        m->init(newHash);
        return m;
    }
    else if(selection == 1)
    {
        FireType* m = new FireType;
        m->init(newHash);
        return m;
    }
    else if(selection == 2)
    {
        WaterType* m = new WaterType;
        m->init(newHash);
        return m;
    }
    else if(selection == 3)
    {
        ForestType* m = new ForestType;
        m->init(newHash);
        return m;
    }
    else if(selection == 4)
    {
        RockType* m = new RockType;
        m->init(newHash);
        return m;
    }
    else
    {
        IceType* m = new IceType;
        m->init(newHash);
        return m;
    }    
}

/**
 * @brief Get a new monster
 * 
 * @return Node* Newly generated monster object
 */
Node * RfRancher::getMonster()
{  
    // Seed the RNG and set the default SSID
    srand(time(NULL));
    String curSSID = "";

    // WiFi device ID
    std::string wifiID = "";
	
    // Try to scan the /proc/net/wireless file for this machine's device ID
    try
	{
    	wifiID = getDeviceID();
	}
	catch(std::logic_error err) // Throws error if can't find system files (wsl causes problems here)
	{

	}

    // If one isn't found then use the old SSID text file instead
	if(!wifiID.empty())
	{
		if(!sniffWifi(&wifiID[0], "./scans/sniffResults"))
		{
			printf("Scan failed, using old data.");
		}
	}
	else
	{
        printf("Couldn't get device ID, using old data.");
	}

	// Open sniffer results file
	std::ifstream in("./scans/sniffResults");

    // Try to open the scan file
	if(!in.is_open())
	{
		printf("Scan file not found, generating random.");
	}
    else
    {
        string temp;

        // Get strongest ssid (first result) from the file
	    getline(in, temp);
        curSSID = &temp[0];
	    in.close(); // Close the file
    }

    // If no SSID is retrieved generate a random one instead.
    if(curSSID.empty())
    {
        curSSID += rand();
    }

    // Get new hash and type selection integer
    int newHash = hashSsid(curSSID);
    int selection = newHash % 6;

    // Create and return the new monster pointer
    if(selection == 0)
    {
        GhostType* m = new GhostType;
        m->init(newHash);
        return m;
    }
    else if(selection == 1)
    {
        FireType* m = new FireType;
        m->init(newHash);
        return m;
    }
    else if(selection == 2)
    {
        WaterType* m = new WaterType;
        m->init(newHash);
        return m;
    }
    else if(selection == 3)
    {
        ForestType* m = new ForestType;
        m->init(newHash);
        return m;
    }
    else if(selection == 4)
    {
        RockType* m = new RockType;
        m->init(newHash);
        return m;
    }
    else
    {
        IceType* m = new IceType;
        m->init(newHash);
        return m;
    }    
}

/**
 * @brief Hash a given string
 * 
 * @param ssid The string being hashed
 * @return int The resulting hash integer
 */
int RfRancher::hashSsid(String ssid)
{
    int total = 1;
    for(int i = 0; i < ssid.size() - 1; i++)
    {
        total *= ssid[i]; // multiply by each ascii value
        total = total % 9999999 + 1000000; // limit number growth to prevent overflow and zero values
    }

    total = abs(total);

    return total;
}

/**
 * @brief Godot bindings method
 * 
 */
void RfRancher::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("getMonster"), &RfRancher::getMonster);
    ClassDB::bind_method(D_METHOD("testGetMonster"), &RfRancher::testGetMonster);
    ClassDB::bind_method(D_METHOD("hashSSID"), &RfRancher::hashSsid);
}
