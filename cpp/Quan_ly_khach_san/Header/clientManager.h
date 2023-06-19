#ifndef __CLIENT_MANAGER_H
#define __CLIENT_MANAGER_H
typedef struct {
  uint8_t day;
  uint8_t month;
  uint16_t year;
} TypeDate;

typedef struct {
  uint8_t second;
  uint8_t minute;
  uint8_t hour;
} TypeTime;

typedef enum {
  IN,
  OUT
} Status;

typedef struct {
  TypeTime time;
  TypeDate date;
  Status status;
} BookingHistory;

/**
 * Class: Customer
 * Description: this is Customer class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class Customer {
  private:
    uint8_t idRoom;
    string name;
    string phoneNumber;
    string address;
    vector<BookingHistory> bookingHistories;
  public:
    Customer(uint8_t id, string customerName, string customerPhone, string customerAddress);
    string getName();
    string getPhoneNumber();
    string getAddress();
    uint8_t getID();

    void setPhoneNumber(string phone);
    void setName(string name);
    void setAddress(string address);

    void bookingHistory(BookingHistory bookingDetails);
    void displayBookingHistory();
}
#endif