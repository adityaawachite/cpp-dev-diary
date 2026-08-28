
#include <iostream>
#include <string>
using namespace std;

// Simple structure to store room information
struct Room {
    int roomNumber;
    string type;        // Single, Double, Suite
    double price;
    bool isBooked;
    string guestName;
};

// Display all rooms (using pointer to array)
void showAllRooms(Room* rooms, int totalRooms) {
    cout << "\n========== ROOM STATUS ==========\n";
    cout << "Room No.   Type      Price     Status      Guest\n";
    cout << "-----------------------------------------------\n";

    for (int i = 0; i < totalRooms; i++) {
        cout << rooms[i].roomNumber << "         "
             << rooms[i].type << "     "
             << rooms[i].price << "     "
             << (rooms[i].isBooked ? "Booked" : "Available") << "     "
             << (rooms[i].isBooked ? rooms[i].guestName : "-") << endl;
    }
    cout << "=================================\n";
}

// Book a room using reference
void bookRoom(Room& room, string guest) {
    if (room.isBooked) {
        cout << "Sorry, Room " << room.roomNumber << " is already booked.\n";
        return;
    }

    room.isBooked = true;
    room.guestName = guest;
    cout << "Room " << room.roomNumber << " successfully booked for " << guest << "!\n";
}

// Checkout using pointer
void checkoutRoom(Room* room) {
    if (!room->isBooked) {
        cout << "Room " << room->roomNumber << " is already vacant.\n";
        return;
    }

    cout << "Checking out guest: " << room->guestName << endl;
    room->isBooked = false;
    room->guestName = "";
    cout << "Room " << room->roomNumber << " is now available.\n";
}

// Find room by number (returns pointer)
Room* findRoom(Room* rooms, int totalRooms, int roomNo) {
    for (int i = 0; i < totalRooms; i++) {
        if (rooms[i].roomNumber == roomNo) {
            return &rooms[i];   // return address of the room
        }
    }
    return nullptr;             // room not found
}

int main() {
    // Hotel has 5 rooms
    Room hotel[5] = {
        {101, "Single", 1500.0, false, ""},
        {102, "Single", 1500.0, false, ""},
        {201, "Double", 2500.0, false, ""},
        {202, "Double", 2500.0, false, ""},
        {301, "Suite",  4500.0, false, ""}
    };

    int choice;
    int roomNo;
    string guestName;

    do {
        cout << "\n======= HOTEL MANAGEMENT SYSTEM =======\n";
        cout << "1. Show All Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Checkout\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showAllRooms(hotel, 5);          // passing array as pointer
                break;

            case 2:
                cout << "Enter Room Number to book: ";
                cin >> roomNo;
                cout << "Enter Guest Name: ";
                cin.ignore();                    // clear buffer
                getline(cin, guestName);

                {
                    Room* found = findRoom(hotel, 5, roomNo);
                    if (found != nullptr) {
                        bookRoom(*found, guestName);  // pass by reference
                    } else {
                        cout << "Room not found!\n";
                    }
                }
                break;

            case 3:
                cout << "Enter Room Number for checkout: ";
                cin >> roomNo;

                {
                    Room* found = findRoom(hotel, 5, roomNo);
                    if (found != nullptr) {
                        checkoutRoom(found);     // pass by pointer
                    } else {
                        cout << "Room not found!\n";
                    }
                }
                break;

            case 4:
                cout << "Thank you for using Hotel Management System!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}