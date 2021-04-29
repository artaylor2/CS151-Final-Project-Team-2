/**
 * @file wifiSniffer.cpp
 * @author Taylor, Alixandra (artaylor2@students.nic.edu)
 * @brief Wifi sniffer definition file
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "wifiSniffer.h"

/**
 * @brief Conduct a wifi scan and output the results to a file
 * 
 * @param deviceID The device ID of the hardware performing the scan
 * @param filePath The filepath of the file where the results will be saved
 * @return true Scan failed
 * @return false Scan was successful
 */

bool sniffWifi(char* deviceID, string filePath)
{
    // Initialize necessary variables for the scan
    wireless_scan_head resultHead;  // Head pointer object for the results
    wireless_scan *resultPtr;       // Result pointer for traversing the linked list
    iwrange range;                  // The range of networks being polled
    int socket;                     // The socket being used to conduct the scan

    // Get a free socket for scanning on
    socket = iw_sockets_open();

    // Gather metadata for the scan
    if (iw_get_range_info(socket, deviceID, &range) < 0) 
    {
        cerr << "Error during iw_get_range_info. Scan incomplete." << endl;
        return false;
    }

    // Perform the scan, and return the head of the result in to resultHead
    if (iw_scan(socket, deviceID, range.we_version_compiled, &resultHead) < 0) 
    {
        cerr << "Error during iw_scan. Scan incomplete." << endl;
        return false;
    }

    vector<scanResult> resultVector;
    scanResult tempResult;
    resultPtr = resultHead.result;

    // Traverse the linked list, storing non-repeats in to a vector of scanResult structs
    while(resultPtr != nullptr)
    {
        // Init flag for duplicate found
        bool foundDup = false;

        // Migrate the needed data from the results list to the temporary struct
        tempResult.ssid = resultPtr->b.essid;
        tempResult.strength = resultPtr->stats.qual.level;

        // Check for duplicates already present in the result vector
        for(int i = 0; i < resultVector.size(); i++)
        {
            if(tempResult.ssid == resultVector[i].ssid)
            {
                foundDup = true;
                break;
            }
        }

        // If the ID is unique then push the temporary result on to the back of the result vector
        if(!foundDup && !tempResult.ssid.empty())
        {
            resultVector.push_back(tempResult);
        }

        // Increment pointer
        resultPtr = resultPtr->next;        
    }

    // Sort the results
    quickSort(resultVector, 0, resultVector.size()-1);

    // Write the results to file
    cout << "Sniffed " << resultVector.size() << " results." << endl;
   
    ofstream resultStream(filePath);
    if(!resultStream.is_open())
    {
        cerr << "Error opening file.";
        return false;
    }

    for(int i = resultVector.size() - 1; i >= 0; i--)
    {
        resultStream << resultVector[i].ssid << endl
                     << resultVector[i].strength << endl;
    }

    resultStream.close();

    // If the process is successful then return confirmation to the calling function
    return true;
}

/**
 * @brief Quick sort a vector of scan results
 * 
 * @param vec The vector of scan results
 * @param left smallest index
 * @param right biggest index
 */
void quickSort(vector<scanResult> &vec, int left, int right)
{
    if(left < right)
    {
        int pivotIndex = partition(vec, left, right);
        quickSort(vec, left, pivotIndex - 1);
        quickSort(vec, pivotIndex, right);
    }
    return;
}

/**
 * @brief Partititoning for a quick sort of a vector of scan results
 * 
 * @param vec vector of scan results
 * @param left smallest index
 * @param right largest index
 * @return int new pivot index
 */
int partition(vector<scanResult> &vec, int left, int right)
{
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = vec[pivotIndex].strength;
    int i = left, j = right;
    scanResult temp;

    while(i <= j) 
    {
        while(vec[i].strength < pivotValue) 
        {
            i++;
        }
        while(vec[j].strength > pivotValue) 
        {
            j--;
        }
        if(i <= j) 
        {
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

/**
 * @brief Get the device ID of the system's first wireless device
 * 
 * @return char* ID name of the first registered wireless device
 */
string getDeviceID()
{
    // Create a temp variable for extracting the info we want
    string lineScrub;

    // Open the device's wireless reference file
    ifstream deviceStream("/proc/net/wireless");

    // Verify file opened successfully
    if(!deviceStream.is_open())
    {
        cerr << "Error querying wifi device" << endl;
        return NULL;
    }

    // Scrub first two lines of the file
    getline(deviceStream, lineScrub);
    getline(deviceStream, lineScrub);

    // Read the ID of the first device
    getline(deviceStream, lineScrub, ':');
    
    // Close the file stream and return the result
    deviceStream.close();
    
    return lineScrub;
}