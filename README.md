# Provan_CSCI2270_FinalProject
This is Evan Provan's project for CU Boulder's CSCI 2270 Final Project.

Summary:
This project is an all inclusive zombie apocalypse program which has many functionalities named the Post-Apocalyptic Transit and Resource Monitor Network (PATRN). First, it allows the user to keep track of the available postapocalyptic cities they can travel to. It reads in the list of the most likely to survive cities and creates a graph from that data. It assigns disricts to each of the groups of cities, with distances in between them, and allows the user to calculate the shortest path between two cities in two different ways. The first way is the lowest number of cities to travel through, and the second is the shortest total distance (milage) between two cities. The program also allows for displaying the user's current city (automatically set to seattle), with functionality to move to connecting cities, add cities to the network, and update connections between two cities. This program also allows the user to keep track of their resources, such as food, water, and weapons, as well as add an inventory of special items. Finally, this program allows the user to keep track of their current party by adding new members, removing members, and displaying the current party.

How to run:
1. Clone the git repository to your local machine.
2. Rebuild the program in your IDE of choice.
3. Compile and Run

Dependencies:
None besides basic #include <> and #include "" libraries

System Requirements:
Should run on any OS (I've tested 5 (Windows 8.1, Windows 7, Ubuntu 14.04 (32bit Linux), Elementary OS (64bit Linux), Xubuntu).
Should run on any computer with a compiler and doesn't require a large amount of RAM or a powerful CPU

Group Members:
Evan Provan

Contributors:
Evan Provan

Open issues/bugs:
Program does not check to see if an item or weapon is already included in the item vector (could be fixed easily, requesting enhancement).
Would greatly appreciate any rigorous testing and reporting of bugs/ideas for enhancement!
