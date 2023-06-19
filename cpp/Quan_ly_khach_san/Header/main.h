#ifndef __ROOM_H
#define __ROOM_H
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
#endif
