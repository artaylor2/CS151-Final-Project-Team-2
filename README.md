# **Rf Rancher**
### - Created by Alix Taylor, Luke Foster, and Jacob Porath
## **Introduction:**
Rf Rancher is a proof of concept game conceptualized by Alix Taylor, Luke Foster, and Jacob Porath. The idea is that the game would allow the user to scan for nearby monsters, catch them, and take care of them. The way this would work in theory is, the user could run the game on a phone and press a scan button that would then use the nearby wifi network SSIDs to generate one of many types of monsters with unique stats and abilities. This was the original concept but as this was a school project for us, we had to simplify many of these systems for the sake of meeting a deadline.

### **What We Have Created:**
Our conecpt design of Rf Rancher runs on linux systems using the [GoDot game engine](https://godotengine.org/). We implemented the monsters and sub-types as C++ classes then implemented these classes into the GoDot game engine as addon modules. For getting the SSIDs, we used a Wifi interfacing library called [Wireless Tools](https://hewlettpackard.github.io/wireless-tools/Tools.html#latest) to pull the SSIDs and singal strengths of nearby networks. From there, we hash the SSID down to an integer and use this as a pseudo-randomly generated number to generate the monster. We created six types of monsters (Forest, Ice, Fire, Ghost, Water, and Rock). Each have their own subtle features that make them unique. All of this is done with a simple scan. After the player has found a monster, they can perform basic actions to take care of the monster, keeping it happy and healthy.

### **What We Would like to Add with More Time:**
- More monsters of each type.
- More abilities further defining each monster
- 
## **How to Download and Install Rf Rancher:**
### Requirements:
1. ...
### Installation:
1. ...
## **Contribution:**
At this time, Rf Rancher is not being developed further by our small group of three. However, if you would like to get in contact with us for any reason, we are available via the Email addresses below:
- Alix Taylor - artaylor2@students.nic.edu
- Luke Foster - lgfoster@students.nic.edu
- Jacob Porath - jwporath@students.nic.edu
## **Authors and Acknowledgment:**
- Alix Taylor - Original concept, design, and Programming
- Luke Foster - Asset art, GUI design, and Programming
- Jacob Porath - "Under the hood" design and Programming