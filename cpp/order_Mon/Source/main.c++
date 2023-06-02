/**
 * File: main.c++
 * Author: NGUYEN DINH DIEN
 * Date: 31/5/2023
 * Discription: this is file for order goods
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#define INPUT_INPOMATION(text, var, checkCondition) \
  do {                                  \
    cout << #text;                      \
    cin >> var;                         \
  } while(checkCondition == 0);              
  
#define CHECK_INFO(condition, text1, status) \
  if(condition) {                           \
    cout << #text1;                          \
    status;                             \
  }

#define PRINT_INFO(item, Database)\
  printf("\nID\t TEN\t\t GIOITINH\t TUOI\t TOAN\t LY\t HOA\t GPA\t HOCLUC\n");                                                  \
  for (auto item : Database) {                                                                                                 \
    printf("%d\t %s\t\t %s\t\t %d\t %.2lf\t %.2lf\t %.2lf\t %.2lf\t %d\n", item.getID(), item.getName().c_str(), item.getGioiTinh().c_str(),\
    item.getAge(), item.getDiemToan(), item.getDiemLy(), item.getDiemHoa(), item.getDiemTrungBinh(), item.getHocLuc());   \
  }                                                                                                                         \
  printf("\n");
/**
 * Class: Dish
 * Description: this is Dish class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class Dish {
  private:
    int ID;
    string nameDish;
    int priceDish;
    int amountDish;
  public:
    Dish();
    // void SetID(const int id);
    void SetName(const string name);
    void setPrice(const int price);
    unsigned int GetID();
    string getName();
    unsigned int getPrice();
};

/*
* Function: Dish
* Description: This function use for constructor Dish
* Input:
*   none
* Output:
*   return: None
*/
Dish:Dish(){
  static id = 1;
  Dish::ID = 1;
  id++;
}

/*
* Function: setName
* Description: This function use for set name of Dish
* Input:
*   name - string
* Output:
*   return: None
*/
void Dish::setName(const string name) {
  this->nameDish = name;
}

/*
* Function: setPrice
* Description: This function use for set price of Dish
* Input:
*   price - string
* Output:
*   return: None
*/
void Dish::setPrice(int price) {
  this->priceDish = price;
}

void Dish::GetID() {
  return this->ID;
}

/*
* Function: setPrice
* Description: This function use for set price of Dish
* Input:
*   Dont have input parameters
* Output:
*   return: Name of Dish
*/
void Dish::getName() {
  return this->nameDish;
}

/*
* Function: setPrice
* Description: This function use for set price of Dish
* Input:
*   Dont have input parameters
* Output:
*   return: Price of Dish
*/
void Dish::getPrice() {
  return this->priceDish;
}


typedef enum {
  CHUA_DAT,
  DA_DAT
} statusTable;

/**
 * Class: Table
 * Description: this is Table class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class Table {
  private:
    int tableID;
    statusTable status;
    vector<Dish> listDish;
  public:
    Table();
    void setTableID(const int id);
    void setStatus(statusTable status);
    void setListDish(vector<Dish> listDish);
    int getTableID();
    statusTable getStatus();
    vector<Dish> getListDish();
};

/*
* Function: Dish
* Description: This function use for constructor Dish
* Input:
*   none
* Output:
*   return: None
*/
Table::Table() {
}

/*
* Function: setName
* Description: This function use for set name of Dish
* Input:
*   name - string
* Output:
*   return: None
*/
void Table::setTableID(const int id) {

  this->tableID = id;
};

/*
* Function: setName
* Description: This function use for set name of Dish
* Input:
*   name - string
* Output:
*   return: None
*/
void Table::setStatus (statusTable status) {
  this->status = status;
};

/*
* Function: setName
* Description: This function use for set name of Dish
* Input:
*   name - string
* Output:
*   return: None
*/
void Table::setListDish(vector<Dish> listDish) {
  this->listDish = listDish;
}

/*
* Function: getTableID
* Description: This function use for get  number Table
* Input:
*   Dont have input parameters
* Output:
*   return: tableID of Table
*/
int Table::getTableID() {
  return this->tableID;
}

statusTable Table::getStatus() {
  return this->status;
}

vector<Dish> Table::getListDish() {
  return this->listDish;
}


class Manager {
  private:
    int idDish;
    vector<Dish> listDish;
    vector<Table> listTable;
  public:

    void addDish();
    void updateDish();
    void removeDish();
    void getDish();
    vector<Table> getListTable();
    vector<Dish> getListDish();
};

void Manager::addDish() {
  
}

void Manager::updateDish() {

}

void Manager::removeDish() {

}

void Manager::getDish() {

}

vector<Table> Manager::getListTable() {

}

vector<Dish> Manager::getDishList() {

}

class Staff {
  private: 
    Manager mn;
  public:
    Staff();
    int showTableID();
    void order(const int id);
    void getListDish(const int id);

} 

/**
 * Class: Menu
 * Description: this is Menu class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class Menu {
  private:
    Manager mn;
  public:
    void manager();
    void staff();
    void showInfo()
}

Menu::Menu() {
  uint8_t command;
  enum Command {
      BACK = 0,
      MANAGER,
      STAFF
  };
  while(1){
    cin >> command;
    switch (command) {
    case BACK:
        return 0;
        break;

    case MANAGER:
        manager();
        break;

    case STAFF:
        staff();
        break;
    default:
        printf("KHONG CO LENH NAY\n");
        break;
    }
  }
}

Menu::manager() {

}

Menu::staff() {

}

menu::showInfo() {

}

int main() {
  return 0;
}