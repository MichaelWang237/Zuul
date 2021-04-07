//Zuul - Text-based game that has various rooms with items
//Michael Wang
//4/4/2021
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <cstring>
#include "Room.h"
using namespace std;

struct items {//struct of items w/ default locations
    int book = 1;
    int uprightPiano = 4;
    int somewhatEdibleHamburger = 5;
    int computer = 6; 
    int dissectedChickenWing = 13;
};
//initialize functions
void printItem(Room** list, int current, items location); 
void dropItem(Room** list, int current, items &location); 
void pickItem(Room** list, int current, items &location); 
void printLocation(Room** list, int current, items location);
void printExits(Room** list, int current);
void move(Room** list, int &current);

int main() {//main method
    //initialize Rooms and variables 
    int current = 8;
    Room* list[15];


    list[0] = new Room("You are in the library. There is a book here.",1,"Z",0,"E",2,"S",5,"Z",0);
    list[1] = new Room("You are in Mrs. Bell's classroom.",2,"Z",0,"E",3,"S",6,"W",1);
    list[2] = new Room("You are in Mrs. Werner's classroom.",3,"Z",0,"E",4,"S",7,"W",2);
    list[3] = new Room("You are in Mr. Rust's classroom. There's an upright piano here. You can pick it up -- I guess you're Superman.",4,"Z",0,"Z",0,"S",8,"W",3);
    list[4] = new Room ("You're in the cafeteria. Calling their offerings food would be generous. There's something resembling a hamburger in the corner. Do you  want to pick it up?",5,"N",1,"E",6,"S",9,"Z",0);
    list[5] = new Room ("You're in the 1-20 computer lab. As the name suggests, there are computers here.",6,"N",2,"E",7,"S",10,"W",5);
    list[6] = new Room ("You're in Mr. Schilling's room.",7,"N",3,"E",8,"S",11,"W",6);
    list[7] = new Room ("You're in Mrs. Thornewood's room. Find your way outside to win!",8,"N",4,"Z",0,"S",12,"W",7);
    list[8] = new Room ("You're outside. Free at last!",9,"N",5,"E",10,"S",13,"W",0);
   list[9] = new Room ("You're in the G-hall bathroom. There's a suspicious smell lingering in the air.",10,"N",6,"E",11,"S",14,"W",9);
     list[10] = new Room ("You're in Mrs. McNamee's classroom.",11,"N",7,"E",12,"S",15,"W",10);
     list[11] = new Room ("You're in Mrs. Boeschenstein's classroom.",12,"N",8,"Z",0,"Z",0,"W",11);
     list[12] = new Room ("You're in Mrs. Profit's room. There's a dissected chicken wing on one of the desks. I wouldn't eat that if I were you.",13,"N",9,"E",14,"Z",0,"Z",0);
     list[13] = new Room ("You're in Mrs. Engle's classroom.",14,"N",10,"E",15,"Z",0,"W",13);
    list[14] = new Room ("You're in Mrs. Railsback's room.",15,"N",11,"Z",0,"Z",0,"W",14);
    
    struct items location;
    char input[80];

    while(current != 9) {//while you haven't escaped, keep playing
        cout << "PICK, DROP, PRINT, MOVE" << endl;
        printLocation(list, current, location);
        cin >> input;
        if(strcmp(input, "PICK") == 0) {//if PICK, pick items
            pickItem(list, current, location);    
        }
        else if(strcmp(input, "DROP") == 0) {//if DROP, drop Items
            dropItem(list, current, location);    
        }
        else if(strcmp(input, "PRINT") == 0) {//if PRINT, print inventory
            printItem(list, current, location);    
        }
        else if(strcmp(input, "MOVE") == 0) {//if Move, print exits and move
            printExits(list, current);
            move(list, current);
        }
    }
    cout << "You are outside! Now go do something with your life." << endl; //Game Over
    return 0;
}
void printItem(Room** list, int current, items location) {//print Items
    if(location.book == 0) {
        cout << "You have a book" << endl;
    }
    if(location.uprightPiano == 0) {
        cout << "You have an upright piano" << endl;
    }
    if(location.somewhatEdibleHamburger == 0) {
        cout << "You have a somewhat edible hamburger" << endl;
    }
    if(location.computer == 0) {
        cout << "You have a computer" << endl;
    }
    if(location.dissectedChickenWing == 0) {
        cout << "you have a dissected chicken wing" << endl;
    }
}
void pickItem(Room** list, int current, items &location) {//pick Items
    if(location.book == current) {
        location.book = 0;
    }
    if(location.uprightPiano == current) {
        location.uprightPiano = 0;
    }
    if(location.somewhatEdibleHamburger == current) {
        location.somewhatEdibleHamburger = 0;
    }
    if(location.computer == current) {
        location.computer= 0;
    }
    if(location.dissectedChickenWing == current) {
        location.dissectedChickenWing = 0;
    }
}
void dropItem(Room** list, int current, items &location) {//drop Items
    if(location.book == 0) {
        location.book = current;
    }
    if(location.uprightPiano == 0) {
        location.uprightPiano = current;
    }
    if(location.somewhatEdibleHamburger == 0) {
        location.somewhatEdibleHamburger = current;
    }
    if(location.computer == 0) {
        location.computer = current;
    }
    if(location.dissectedChickenWing == 0) {
        location.dissectedChickenWing = current;
    }
}
void printLocation(Room** list, int current, items location) {//print current Location
    cout << list[current-1]->description << endl;
    if(location.book == current) {
        cout << "There is a book here." << endl;
    }
    if(location.uprightPiano == current) {
        cout << "There is an upright piano here. Maybe use it to escape?" << endl;
    }
    if(location.somewhatEdibleHamburger == current) {
        cout << "There is a somewhat edible hamburge here." << endl;
    }
    if(location.computer == current) {
        cout << "There is a computer here" << endl;
    }
    if(location.dissectedChickenWing == current) {
        cout << "There is a dissected chicken wing here" << endl;
    }
}
void printExits(Room** list, int current) {//print Exits
    map <string, int> currentExits;
    currentExits = list[current-1]->exits;
    for(map <string, int>::iterator itr = currentExits.begin(); itr != currentExits.end(); ++itr) {
        cout << itr->first << endl;
    }
}
void move(Room** list, int &current) {//move Rooms
    string input;
    cin >> input;
    map <string, int> currentExits;
    currentExits = list[current-1]->exits;
    for(map <string, int>::iterator itr = currentExits.begin(); itr != currentExits.end(); ++itr) {
        if(!input.compare(itr->first)) {
            current = itr->second;
        }
    }
}
