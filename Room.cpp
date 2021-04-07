#include <iostream>
#include <cstring>
#include <string>
#include "Room.h"
#include <map>
using namespace std;

//function to creat Rooms with needed info
Room::Room(string newDescription, int newID, string North, int N, string East, int E, 
        string South, int S, string West, int W) {
    description = newDescription;
    id = newID;
    if(!North.compare("N")) {
       exits["NORTH"] = N;
    }
    if(!East.compare("E")) {
       exits["EAST"] = E;
    }
    if(!South.compare("S")) {
       exits["SOUTH"] = S;
    }
    if(!West.compare("W")) {
       exits["WEST"] = W;
    }
}
string Room::getDescription() {//print Description of Room
    return description;
}
int Room::getID() {//print ID of ROOM
    return id;
}

