#ifndef __EMPLOYEE_MANAGER_H
#define __EMPLOYEE_MANAGER_H

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

/**
 * Class: Employee
 * Description: this is Employee class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
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
#endif
