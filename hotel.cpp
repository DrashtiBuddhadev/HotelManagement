/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a hotel room
struct Room {
    int roomNumber;
    bool occupied;
    double rate;

    Room(int num, double r) : roomNumber(num), occupied(false), rate(r) {}
};

// Define a structure to represent guest information
struct Guest {
    string name;
    int roomNumber;
    int daysStayed;
    double totalBill;

    Guest(string n, int num, int days, double bill) : name(n), roomNumber(num), daysStayed(days), totalBill(bill) {}
};

// Hotel management class
class HotelManagement {
private:
    vector<Room> rooms;
    vector<Guest> guests;

public:
    // Constructor to initialize rooms
    HotelManagement(int numRooms) {
        for (int i = 0; i < numRooms; ++i) {
            rooms.push_back(Room(i + 1, 100.0)); // Assign room numbers and default rate
        }
    }

    // Function to display available rooms
    void displayAvailableRooms() {
        cout << "Available Rooms:" << endl;
        for (const auto& room : rooms) {
            if (!room.occupied) {
                cout << "Room " << room.roomNumber << endl;
            }
        }
    }

    // Function to allocate a room to a guest
    void allocateRoom(const string& guestName, int roomNumber, int daysStayed) {
        if (roomNumber < 1 || roomNumber > rooms.size()) {
            cout << "Invalid room number." << endl;
            return;
        }

        if (rooms[roomNumber - 1].occupied) {
            cout << "Room " << roomNumber << " is already occupied." << endl;
            return;
        }

        rooms[roomNumber - 1].occupied = true;
        double bill = rooms[roomNumber - 1].rate * daysStayed;
        guests.push_back(Guest(guestName, roomNumber, daysStayed, bill));
        cout << "Room " << roomNumber << " allocated to " << guestName << ". Total bill: $" << bill << endl;
    }

    // Function to display guest information
    void displayGuestInformation() {
        cout << "Guest Information:" << endl;
        for (const auto& guest : guests) {
            cout << "Name: " << guest.name << ", Room: " << guest.roomNumber << ", Days Stayed: " << guest.daysStayed << ", Total Bill: $" << guest.totalBill << endl;
        }
    }

    // Function to free up a room
    void freeRoom(int roomNumber) {
        if (roomNumber < 1 || roomNumber > rooms.size()) {
            cout << "Invalid room number." << endl;
            return;
        }

        if (!rooms[roomNumber - 1].occupied) {
            cout << "Room " << roomNumber << " is already vacant." << endl;
            return;
        }

        rooms[roomNumber - 1].occupied = false;
        cout << "Room " << roomNumber << " is now vacant." << endl;
    }
};

int main() {
    HotelManagement hotel(10); // Create a hotel with 10 rooms

    // Allocate rooms to guests
    hotel.allocateRoom("John Doe", 3, 5);
    hotel.allocateRoom("Jane Smith", 7, 3);

    // Display available rooms
    hotel.displayAvailableRooms();

    // Display guest information
    hotel.displayGuestInformation();

    // Free up a room
    hotel.freeRoom(3);

    return 0;
}
