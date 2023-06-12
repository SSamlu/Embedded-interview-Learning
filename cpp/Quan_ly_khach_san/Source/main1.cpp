/**
 * File: main1.cpp
 * Author: NGUYEN DINH DIEN
 * Date: 12/6/2023
 * Discription: this is file for hotel manager session client manager
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

/*
* Function: Customer
* Description: This function use for constructor Customer
* Input:
*   none
* Output:
*   return: None
*/
Customer::Customer(uint8_t id, string customerName, string customerPhone, string customerAddress) {
  this->idRoom = id;
  this->name = customerName;
  this->phoneNumber = customerPhone;
  this->address = customerAddress;
}

/*
* Function: getName
* Description: This function use for get name Number
* Input:
*   None
* Output:
*   return: name
*/
string Customer::getName() {
  return this->name;
}

/*
* Function: getID
* Description: This function use for get id
* Input:
*   None
* Output:
*   return: id
*/
uint8_t Customer::getID() {
  return this->idRoom;
}

/*
* Function: bookingHistory
* Description: This function use for get bookingHistory
* Input:
*   bookingDetails - BookingHistory
* Output:
*   return: None
*/
void Customer::setPhoneNumber(string phone) {
  this->phoneNumber = phone;
};

/*
* Function: bookingHistory
* Description: This function use for get bookingHistory
* Input:
*   bookingDetails - BookingHistory
* Output:
*   return: None
*/
void Customer::setName(string name) {
  this->name = name;
};

/*
* Function: bookingHistory
* Description: This function use for get bookingHistory
* Input:
*   bookingDetails - BookingHistory
* Output:
*   return: None
*/
void Customer::setAddress(string address) {
  this->address = address;
};

/*
* Function: bookingHistory
* Description: This function use for get bookingHistory
* Input:
*   bookingDetails - BookingHistory
* Output:
*   return: None
*/
void Customer::bookingHistory(BookingHistory bookingDetails) {
  this->bookingHistories.push_back(bookingDetails);
}

/*
* Function: displayBookingHistory
* Description: This function use for displayBookingHistory
*   None
* Output:
*   return: None
*/
void Customer::displayBookingHistory() {
  cout << "Bokking history of customer: " << this->name << endl;
  for (auto history : this->bookingHistories) {
    cout << "Date: " << (int) history.date.day << (int) history.date.month << (int) history.date.year << endl;
    cout << "Time: " << (int) history.time.hour << (int) history.time.minute << (int) history.time.second << endl;
    cout << "Status: " << (history.status == IN) ? "CHECK IN" : "CHECK OUT" << endl;
  }
}

/**
 * Class: CustomerManager
 * Description: this is CustomerManager class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class CustomerManager {
  private:
    vector<Customer> databaseCustomers;
  public:
    void addCustomer(uint8_t idRoom, customerName, string customerPhone, string customerAddress);
    void editCustomer(uint8_t idRoom);
    void deleteCustomer(uint8_t idRoom);
    void displayCustomerInfo(uint8_t idRoom);
}

/*
* Function: addCustomer
* Description: This function use for get addCustomer
* Input:
*   idRoom - uint8_t
*   customerName - string
*   customerPhone - string
*   customerAddress - string
* Output:
*   return: None
*/
void CustomerManager::addCustomer(uint8_t idRoom, string customerName, string customerPhone, string customerAddress) {
  Customer customer(idRoom, customerName, customerPhone, customerAddress);
  this->databaseCustomers.push_back(customer);
  cout << "khach hang " << customerName << "da duoc them vao." << endl;
}

/*
* Function: editCustomer
* Description: This function use for get edit Customer
* Input:
*   idRoom - uint8_t
* Output:
*   return: None
*/
void CustomerManager::editCustomer(uint8_t idRoom) {
  for(auto customer : this->databaseCustomers) {
    if(customer.getID() == idRoom) {
      string newPhone, name, address;
      cin >> newPhone;
      customer.setPhoneNumber(newPhone);
      cin >> name;
      customer.setName(name);
      cin >> address;
      customer.setName(address);
      cout << "Edit informaion customer tai phong" << idRoom << endl;
      return 0;
    }
  }
  cout << "So Phong " << idRoom << "khong ton tai" <<endl;
}

void CustomerManager::deleteCustomer(uint8_t idRoom) {
  for(auto customer : this->databaseCustomers) {
    if(customer.getID() == idRoom) {
      this->databaseCustomers.erase(customer);
      cout << "Delete customer at Room" << idRoom << endl;
      return;
    }
  }
  cout << "ID Room "  << idRoom << "not found" <<endl;
}

/*
* Function: displayCustomerInfo
* Description: This function use for get edit display Customer Information
* Input:
*   idRoom - uint8_t
* Output:
*   return: None
*/
void CustomerManager::displayCustomerInfo(uint8_t idRoom) {
  for(auto customer : this->databaseCustomers) {
    if(customer.getID() == idRoom) {
      cout << "***Customer information***" << endl;
      cout << "Customer name" << customer.getName() << endl;
      cout << "Customer ID Room" << customer.getID() << endl;
    }
  }
}

int main() {
  CustomerManager *manager;
  manager = new CustomerManager("101", "Dien", "0989855145", "Quang Nam");
  return 0;
}