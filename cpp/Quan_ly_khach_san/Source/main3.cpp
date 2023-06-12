/**
 * File: main3.cpp
 * Author: NGUYEN DINH DIEN
 * Date: 12/6/2023
 * Discription: this is file for hotel manager session service manager
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define PRINT_INFO(item, Database, numberOrder)\
  printf("STT\t| ID\t| Desc\t| Price\n");                                                  \
  for (auto item : Database) {                                                                                                 \
    printf("%d\t| \t%s\t| \t%s\t| \t%d\n", numberOrder, item.getID(), item.getName(), item.getPrice());   \
  }                                                                                                                         \
  printf("\n");


/**
 * Class: Service
 * Description: this is Service class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class Service {
  private:
    string name;
    string description;
    double price;
  public:
    Service(string name, string description, double price);
    string getName();
    string getDescription();
    double getPrice();

    void setName(string nameService);
    void setDescription(string descriptionService);
    void setPrice(double price);
};

/*
* Function: Service
* Description: This function use for constructor Service
* Input:
*   none
* Output:
*   return: None
*/
Service::Service(string name, string description, double price) {
  this->name = name;
  this->description = description;
  this->price = price;
}

/*
* Function: getName
* Description: This function use for get name
* Input:
*   None
* Output:
*   return: name
*/
string Service::getName() {
  return this->name;
}

/*
* Function: getName
* Description: This function use for get name
* Input:
*   None
* Output:
*   return: name
*/
string Service::getDescription() {
  return this->description;
}

/*
* Function: getName
* Description: This function use for get name
* Input:
*   None
* Output:
*   return: name
*/
double Service::getPrice() {
  return this->price;
}

/*
* Function: setName
* Description: This function use for set Name
* Input:
*   nameService - string
* Output:
*   return: None
*/
void Service::setName(string nameService) {
  this->name = nameService;
}

/*
* Function: setDescription
* Description: This function use for set Description
* Input:
*   descriptionService - string
* Output:
*   return: None
*/
void Service::setDescription(string descriptionService) {
  this->description = descriptionService;
}

/*
* Function: setPrice
* Description: This function use for set price
* Input:
*   price - double
* Output:
*   return: None
*/
void Service::setPrice(double price) {
  this->price = price;
}

/**
 * Class: ServiceManager
 * Description: this is ServiceManager class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class ServiceManager {
  private:
    vector<Service> databaseServices;
  public:
    void addService();
    void editService();
    void removeService();
    void displayService();
}

/*
* Function: addService
* Description: This function use for add Service
* Input:
*   None
* Output:
*   return: None
*/
void ServiceManager::addService() {
  string name, description;
  double price;
  cout << "Service name: ";
  cin >> name;
  cout << "Service description: ";
  cin >> description;
  cout << "Service price: ";
  cin >> price;
  Service service(name, description, price);
  databaseServices.push_back(service);
}

/*
* Function: editService
* Description: This function use for edit Service
* Input:
*   None
* Output:
*   return: None
*/
void ServiceManager::editService() {
  int index;
  string name, description;
  double price;
  cout << "the index of service: ";
  cin >> index;
  if(index >= 0 && index < databaseServices.size()) {
    Service& service = databaseServices[index];
    cout << "Service name: ";
    cin >> name;
    cout << "Service description: ";
    cin >> description;
    cout << "Service price: ";
    cin >> price;
    service.setName(name);
    service.setDescription(description);
    service.setPrice(price);
  } else {
    cout << "Service Not Found!" << endl;
  }
}

/*
* Function: removeService
* Description: This function use for remove Service
* Input:
*   None
* Output:
*   return: None
*/
void ServiceManager::removeService() {
  if(this->databaseServices.empty()) {
    cout << "No service!" << endl;
  } else {
    for(auto& service : this->databaseServices) {
      this->databaseServices.erase(service)
    }
  }
}

/*
* Function: removeService
* Description: This function use for remove Service
* Input:
*   None
* Output:
*   return: None
*/
void ServiceManager::displayService() {
  if(this->databaseServices.empty()) {
    cout << "No service!" << endl;
  } else {
    for(auto& service : this->databaseServices) {
      this->databaseServices.erase(service);
    }
  }
}
int main(){
  return 0;
}
