#include <map>
#include <string>
#include <cstring>
using namespace std;

class Room {//create class for Rooms, must have Descripition, Exists, and Room ID
    public:
        Room(string description, int newID, string North, int N, string East, int E, 
                string South, int S, string West, int W);
        string getDescription();
        int getID();
        map <string, int> exits;
        string description;
        int id;
    private:
        };
