/**
 * File: main2.cpp
 * Author: NGUYEN DINH DIEN
 * Date: 12/6/2023
 * Discription: this is file for hotel manager session employee manager and security
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef enum {
  JANITOR,
  RECEPTIONIST,
  LAUNDER_STAFF,
  LUGGAGE_STAFF,
  GARDENER
} JobPosition;

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
} Schedule;

/**
 * Class: User
 * Description: this is User class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class User {
  private:
    string username;
    string password;
  public:
    User(string username, string password);
    string getUsername();
    bool authenticate(string inputPassword);
    
}
bool User::authenticate(string inputPassword) {
  return this->password == inputPassword;
}
class Employee {
  private:
    uint16_t ID;
    string name;
    string phoneNumber;
    JobPosition position;
    Schedule schedule;
    User user;
  public:
    Employee(string nameEmployee, string phoneNumberEmployee, JobPosition positionEmployee, Schedule scheduleEmployee, User user);
    //get
    uint16_t getId();
    string getName(string password);
    string getPhoneNumber(string password);
    JobPosition getPosition(string password);
    Schedule getSchedule(string password);
    //set
    void setName(string nameEmployee);
    void setPhoneNumber(string phoneNumberEmployee);
    void setPosition(JobPosition positionEmployee);
    void setSchedule(Schedule scheduleEmployee);
};

/*
* Function: Employee
* Description: This function use for constructor Employee
* Input:
*   none
* Output:
*   return: None
*/
Employee::Employee(string nameEmployee, string phoneNumberEmployee, JobPosition positionEmployee, Schedule scheduleEmployee, User user) {
  static uint16_t idEmployee = 100;
  this->ID = idEmployee;
  idEmployee++;
  this->name = nameEmployee;
  this->phoneNumber = phoneNumberEmployee;
  this->position = positionEmployee;
  this->schedule = scheduleEmployee;
  this->user = user;
};

/*
* Function: getId
* Description: This function use for get id
* Input:
*   None
* Output:
*   return: id
*/
uint16_t Employee::getId() {
  return this->ID;
};

/*
* Function: getName
* Description: This function use for get name
* Input:
*   password - string
* Output:
*   return: name
*/
string Employee::getName(string password) {
  if(this->user.authenticate(password) || password == "Admin") {
    return this->name;
  }
}

/*
* Function: getPhoneNumber
* Description: This function use for get phone
* Input:
*   password - string
* Output:
*   return: phone number
*/
string Employee::getPhoneNumber(string password) {
  if(this->user.authenticate(password) || password == "Admin") {
    return this->phoneNumber;
  }
};

/*
* Function: getPosition
* Description: This function use for get job position
* Input:
*   password - string
* Output:
*   return: job position
*/
JobPosition Employee::getPosition(string password) {
  if(this->user.authenticate(password) || password == "Admin") {
    return this->position;
  }
};

/*
* Function: getSchedule
* Description: This function use for get schedule
* Input:
*    password - string
* Output:
*   return: schedule
*/
Schedule Employee::getSchedule(string password) {
  if(this->user.authenticate(password) || password == "Admin") {
    return this->schedule;
  }
};

/*
* Function: setName
* Description: This function use for get name
* Input:
*   nameEmployee - string
* Output:
*   return: None
*/
void Employee::setName(string nameEmployee) {
  this->name = nameEmployee;
};

/*
* Function: setPhoneNumber
* Description: This function use for get phone
* Input:
*   phoneNumberEmployee - string
* Output:
*   return: None
*/
void Employee::setPhoneNumber(string phoneNumberEmployee) {
  this->phoneNumber = phoneNumberEmployee;
};

/*
* Function: setPosition
* Description: This function use for get Job position
* Input:
*   positionEmployee - string
* Output:
*   return: None
*/
void Employee::setPosition(JobPosition positionEmployee) {
  this->position = positionEmployee;
};

/*
* Function: setSchedule
* Description: This function use for get schedule
* Input:
*   scheduleEmployee - string
* Output:
*   return: None
*/
void Employee::setSchedule(Schedule scheduleEmployee) {
  this->schedule = scheduleEmployee;
};

/**
 * Class: EmployeeManager
 * Description: this is EmployeeManager class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class EmployeeManager {
  private:
    vector<Employee> databaseEmployees;
  public:
    void addEmployee(Employee employee);
    void removeEmployee(uint16_t idEmployee);
    void updateEmployee(uint16_t idEmployee);
    void displayEmployee();
}

/*
* Function: addEmployee
* Description: This function use for add Employee
* Input:
*   employee - Employee
* Output:
*   return: None
*/
void EmployeeManager::addEmployee(Employee employee) {
  this->databaseEmployees.push_back(employee);
  cout << "Added customer" << employee.getName() << "into database." << endl;
}

/*
* Function: removeEmployee
* Description: This function use for  remove Employee
* Input:
*   idEmployee - uint16_t
* Output:
*   return: None
*/
void EmployeeManager::removeEmployee(uint16_t idEmployee) {
  for(auto employee : this->databaseEmployees) {
    if(employee.getId() == idEmployee) {
      this->databaseEmployees.erase(employee);
      cout << "Employee" << employee.getName() << "removed" << endl;
    }
  }
  cout << "ID Employee" << idEmployee << "not found" << endl;
}

/*
* Function: updateEmployee
* Description: This function use for update Employee
* Input:
*   idEmployee - uint16_t
* Output:
*   return: None
*/
void EmployeeManager::updateEmployee(uint16_t idEmployee) {
  for(auto employee : this->databaseEmployees) {
    if(employee.getId() == idEmployee) {
      string name, phone;
      JobPosition pos;
      cout << "Name: ";
      cin >> name >> endl;
      employee.setName(name);
      cout << "Phone: ";
      cin >> phone >> endl;
      employee.setPhoneNumber(phone);
      printf("Select position: \n");
      printf("1. Janitor \n2. Receptionist \n3.Laundry Staff \n4.Luggage Staff \n5.Gardener\n");
      printf("Enter your choice: ");
      int choice;
      cin >> choice;
      switch (choice) {
        case 1:
          pos = JANITOR;
          break;
        case 2:
          pos = RECEPTIONIST;
          break;
        case 3:
          pos = LAUNDER_STAFF;
          break;
        case 4:
          pos = LUGGAGE_STAFF;
          break;
        case 5:
          GARDENER
          break;
        default:
          cout << "Invalid choice" << endl;
          break;
      }
      employee.setPosition(pos);
      cout << "Employee updated" << endl;
      return 0;
    }
  }
  cout << "ID Employee" << idEmployee << "not found" << endl;
}

/*
* Function: displayEmployee
* Description: This function use for display Employee
* Input:
*   None
* Output:
*   return: None
*/
void EmployeeManager::displayEmployee() {
  for(auto employee : this->databaseEmployees) {
    cout << "Employee name: " << employee.getName() << endl;
    cout << "Employee Phone: " << employee.getPhoneNumber() << endl;
    cout << "Employee position: ";
    switch (employee.getPosition()) {
      case JANITOR:
        cout << "Janitor" << endl;
        break;
      case RECEPTIONIST:
        cout << "Receptionist" << endl;
        break;
      case LAUNDER_STAFF:
        cout << "Laundry Staff" << endl;
        break;
      case LUGGAGE_STAFF:
        cout << "Luggage Staff" << endl;
        break;
      case GARDENER:
        cout << "Gardener" << endl;
        break;
      default:
        break;
    }
  }
}
int main() {
  return 0;
}