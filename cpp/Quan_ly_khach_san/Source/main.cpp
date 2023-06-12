/**
 * File: main.c++
 * Author: NGUYEN DINH DIEN
 * Date: 31/5/2023
 * Discription: this is file for hotel manager
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
using namespace std;

/**
 * Class: Room
 * Description: this is Room class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class Room {
  private:
    uint8_t roomNo;
    bool isBooked;
    bool isClearing;
  public:
    Room(uint8_t number);
    uint8_t getRoomNumber();
    bool isAvailable();
    void bookRoom();
    void checkIn();
    void checkOut();
};

/*
* Function: Room
* Description: This function use for constructor Room
* Input:
*   none
* Output:
*   return: None
*/
Room::Room(uint8_t number) {
  Room::roomNo = number;
  Room::isBooked = false;
  Room::isClearing = false;
}

/*
* Function: getRoomNumber
* Description: This function use for get Room Number
* Input:
*   None
* Output:
*   return: room number
*/
uint8_t Room::getRoomNumber() {
  return Room::roomNo;
}

/*
* Function: isAvailable
* Description: This function use for check Room available
* Input:
*   None
* Output:
*   return: Boolean
*/
bool Room::isAvailable() {
  return !Room::isBooked && !Room::isClearing;
}

/*
* Function: bookRoom
* Description: This function use for check book Room
* Input:
*   None
* Output:
*   return: None
*/
void Room::bookRoom() {
  this->isBooked = true; 
}

/*
* Function: checkIn
* Description: This function use for check in Room
* Input:
*   None
* Output:
*   return: None
*/
void Room::checkIn() {
  this->isBooked = true;
  this->isClearing = false;
}

/*
* Function: checkOut
* Description: This function use for check out Room
* Input:
*   None
* Output:
*   return: None
*/
void Room::checkOut() {
  this->isBooked = false;
  this->isClearing = true;
}

/**
 * Class: HotelManager
 * Description: this is HotelManager class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class HotelManager {
  private:
    vector<Room> databaseRooms;
    void displayAvailableRooms();
    void bookRoom(uint8_t roomNumber);
    void checkIn(uint8_t roomNumber);
    void checkOut(uint8_t roomNumber);
  public:
    HotelManager();
    void addRoom(uint8_t roomNumber);
    // void displayRooms(uint8_t roomNumber);
};

/*
* Function: HotelManager
* Description: This function use for constructor HotelManager
* Input:
*   none
* Output:
*   return: None
*/
HotelManager::HotelManager() {
  while(1) {
    printf("*****Hotel Manager*****\n");
    printf(" 1. Display available rooms \n 2. Book a room\n 3. Check in to a Room\n 4. Check out the Room\n 5. Exit\n");
    printf("Enter: ");
    int choice;
    cin >> choice;
    switch (choice) {
      case 1:
        this->displayAvailableRooms();
        break;
      case 2:
        uint8_t roomNo;
        cout << "Enter the room number: ";
        cin >> roomNo;
        this->bookRoom(roomNo);
        break;
      case 3:
        uint8_t roomNo1;
        cout << "Enter the room number: ";
        cin >> roomNo1;
        this->checkIn(roomNo1);
        break;
      case 4:
        uint8_t roomNo2;
        cout << "Enter the room number: ";
        cin >> roomNo2;
        this->checkOut(roomNo2);
        break;
      case 5:
        exit(0);
      default:
        cout << "Invalid choice" << endl;
        break;
    }
  }
};

/*
* Function: displayAvailableRooms
* Description: This function use for display Available Rooms
* Input:
*   None
* Output:
*   return: None
*/
void HotelManager::displayAvailableRooms(){
  cout << "available Rooms: " << endl;
  for(auto item : this->databaseRooms) {
    if(item.isAvailable()) {
      cout << "Room: " << (int)item.getRoomNumber() << endl;
    }
  }
};

/*
* Function: bookRoom
* Description: This function use for book Room of HotelManager class
* Input:
*   None
* Output:
*   return: None
*/
void HotelManager::bookRoom(uint8_t roomNumber) {
  for(auto item : this->databaseRooms) {
    if(item.getRoomNumber() == roomNumber) {
      item.bookRoom();
      cout << "Booked Room " << (int)roomNumber << endl;
      return;
    }
  }
  cout << "No Room " << (int)roomNumber << endl;
};

/*
* Function: checkIn
* Description: This function use for of check In of HotelManager class
* Input:
*   roomNumber - uint8_t
* Output:
*   return: None
*/
void HotelManager::checkIn(uint8_t roomNumber) {
  for(auto& item : this->databaseRooms) {
    if(item.getRoomNumber() == roomNumber) {
      item.checkIn();
      cout << "Checked In Room " << (int)roomNumber << endl;
      return;
    }
  }
  cout << "No Room " << (int)roomNumber << endl;
};

/*
* Function: checkOut
* Description: This function use for of check Out HotelManager class
* Input:
*   None
* Output:
*   return: None
*/
void HotelManager::checkOut(uint8_t roomNumber) {
  for(auto& item : this->databaseRooms) {
    if(item.getRoomNumber() == roomNumber) {
      item.checkOut();
      cout << "Checked Out Room " << (int)roomNumber << endl;
      return;
    }
  }
  cout << "No Room " << (int)roomNumber << endl;
};

/*
* Function: addRoom
* Description: This function use for of add Room HotelManager class
* Input:
*   None
* Output:
*   return: None
*/
void HotelManager::addRoom(uint8_t roomNumber) {
  this->databaseRooms.push_back(Room(roomNumber));
};

int main() {
  HotelManager *hotelManager;
  hotelManager = new HotelManager();
  delete hotelManager;
  return 0;
}