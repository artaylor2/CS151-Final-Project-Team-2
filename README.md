# **Rf Rancher**
### - Created by Alix Taylor, Luke Foster, and Jacob Porath
## **Introduction:**
Rf Rancher is a proof of concept game conceptualized by Alix Taylor, Luke Foster, and Jacob Porath. The idea is that the game would allow the user to scan for nearby monsters, catch them, and take care of them. The way this would work in theory is, the user could run the game on a phone and press a scan button that would then use the nearby wifi network SSIDs to generate one of many types of monsters with unique stats and abilities. This was the original concept but as this was a school project for us, we had to simplify many of these systems for the sake of meeting a deadline.

### **What We Have Created:**
Our concept design of Rf Rancher runs on linux systems using the [GoDot game engine](https://godotengine.org/). We implemented the monsters and sub-types as C++ classes then implemented these classes into the GoDot game engine as addon modules. For getting the SSIDs, we used a Wifi interfacing library called [Wireless Tools](https://hewlettpackard.github.io/wireless-tools/Tools.html#latest) to pull the SSIDs and singal strengths of nearby networks. From there, we hash the SSID down to an integer and use this as a pseudo-randomly generated number to generate the monster. We created six types of monsters (Forest, Ice, Fire, Ghost, Water, and Rock). Each have their own subtle features that make them unique. All of this is done with a simple scan. After the player has found a monster, they can perform basic actions to take care of the monster, keeping it happy and healthy. Here's a short [video](https://www.youtube.com/watch?v=QfZtUyxhjz0) we recorded showing off the game and explaining some of the systems.

### **What We Would like to Add with More Time:**
- More monsters of each type.
- More abilities further defining each monster
- Expanded gameplay such as monster battles, more envionment interaction, etc.
- An environment preview system that takes the 3-5 strongest signals and shows what potential environments are nearby
- Capture minigames
- Monster growth/training/exp
## **How to Download and Install Rf Rancher:**
### Requirements:
*note: This guide only applies to building the project for Ubuntu Linux*

1. Install Wireless Tools for Linux dev library (libiw-dev)
```
sudo apt-get install libiw-dev    
```
2. Install all necessary tools for building Godot 3.3 from source in Ubuntu (one-line install prompt included below)
```
sudo apt-get install build-essential scons pkg-config libx11-dev libxcursor-dev libxinerama-dev libgl1-mesa-dev libglu-dev libasound2-dev libpulse-dev libudev-dev libxi-dev libxrandr-dev yasm
```
3. Download the Godot 3.3 source repository
```
git clone https://github.com/godotengine/godot.git
```
### Installation:
1. Copy the contents of the 'modules' folder in the RfRancher project repository in to, './modules' folder of the cloned Godot 3.3 source code repository 
2. Navigate to the root folder of the Godot 3.3 source code repository, and open a terminal window.
3. Input ``` scons -j4 -platform=x11 ``` to run the SCons build tool in the source root folder and compile the engine while including the custom RFRancher module and libiw libraries.
4. Navigate to the './bin' folder Godot 3.3 source code repository and run the file named, 'godot.x11.tools.64'. This is the extended Godot editor.
5. Select the 'Import' button on the right side of the editor, and navigate to the root directory of the RFRancher repository. Select the 'project.godot' file to load the project profile and open the game in the editor.
6. Press the 'Play' button in the upper right hand corner of the editor to run the game in debug mode.
## **Contribution:**
At this time, Rf Rancher is not being developed further by our small group of three. However, if you would like to get in contact with us for any reason, we are available via the Email addresses below:
- Alix Taylor - artaylor2@students.nic.edu
- Luke Foster - lgfoster@students.nic.edu
- Jacob Porath - jwporath@students.nic.edu
## **Authors and Acknowledgment:**
- Alix Taylor - Original concept, design, and Programming
- Luke Foster - Asset art, GUI design, and Programming
- Jacob Porath - "Under the hood" design and Programming
