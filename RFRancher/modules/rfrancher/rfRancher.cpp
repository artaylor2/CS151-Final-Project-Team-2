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

Node * RfRancher::testGetMonster(String curSSID)
{  
    srand(time(NULL));

    // If no SSID is retrieved generate a random one instead.
    if(curSSID.empty())
    {
        curSSID += rand();
    }

    // Get new hash and type selection integer
    int newHash = hashSsid(curSSID);
    int selection = newHash % 6;

    // Create monster pointer
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

Node * RfRancher::getMonster()
{  
    srand(time(NULL));
    String curSSID = "";

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
    
	if(!in.is_open())
	{
		printf("Couldn't get device ID, using old data.");
	}
    else
    {
        string temp;
        // Get strongest ssid
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

    // Create monster pointer
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

void RfRancher::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("getMonster"), &RfRancher::getMonster);
    ClassDB::bind_method(D_METHOD("testGetMonster"), &RfRancher::testGetMonster);
    ClassDB::bind_method(D_METHOD("hashSSID"), &RfRancher::hashSsid);
}
