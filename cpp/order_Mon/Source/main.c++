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
  printf("STT\t| ID\t| Ten\t| Price\n");                                                  \
  for (auto item : Database) {                                                                                                 \
    printf("%d\t| \t%s\t| \t%s\t| \t%d\n", item.getID(), item.getID(), item.getName(), item.getPrice()); \   \
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

class Manager;

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
    Table(Manager manager);
    void setTableID(const int id);
    void setStatus(statusTable status);
    void setListDish(vector<Dish> listDish);
    int getTableID();
    statusTable getStatus();
    // vector<Dish> getListDish();
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
  typedef enum {
    CLEAR_DISH,
    ORDER_DISH
  } status;

  
  switch (status) {
    case CLEAR_DISH:
      this->listDish.clear();
      break;
    case ORDER_DISH:
      this->listDish.push_back(listDish);
      break;
    default:
      break;
  }
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

// vector<Dish> Table::getListDish() {
//   return this->listDish;
// }


class Manager {
  private:
    int idDish;
    int numberTables;
    vector<Dish> listDish;
    vector<Table> listTable;
  public:
    void setNumberTables(int quantityTables);
    void addDish();
    void updateDish();
    void removeDish();
    void getDish();
    int getNumberTables();
    vector<Table> getListTable();
    vector<Dish> getListDish();
};

/*
* Function: setName
* Description: This function use for set number amount of Table
* Input:
*   name - string
* Output:
*   return: None
*/
void Manager::setNumberTables(int quantityTables) {
  // INPUT_INPOMATION("NHAP SO LUONG BAN: ", id_Dish, id_Dish < 0);
  Manager::numberTables = quantityTables
};

/*
* Function: addDish
* Description: This function use for add dish
* Input:
*   None
* Output:
*   return: None
*/
void Manager::addDish() {
  string name_dish;
  int price_dish;
  INPUT_INPOMATION("NHAP TEN MON: ", name_dish, 0);
  INPUT_INPOMATION("NHAP GIA: ", price_dish, price_dish < 0);

  Dish dish(name_dish, price_dish);

  Manager::listDish.push_back(dish);
}

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
void Manager::updateDish() {
  string name_dish;
  int price_dish;
  int id_dish;
  vector<Dish> *tmpDish = &listDish;
  int haveDish = -1;
  if(listDish.empty()) {
    printf("Danh sach Thuc Uong trong");
  } else {
    PRINT_INFO(item, listDish);
    // for (Dish item : listDish) {
      
    // }
    INPUT_INPOMATION("NHAP ID MON: ", id_dish, 0);
    for(int i = 0; i < tmpDish->size(); i++) {
      if((tmp->at(i)).GetID() == id_dish) {
        INPUT_INPOMATION("NHAP TEN MON: ", name_dish, 0);
        INPUT_INPOMATION("NHAP GIA: ", price_dish, price_dish < 0);
        tmpDish->at(i).SetName(name_dish);
        tmpDish->at(i).SetPrice(price_dish);
        haveDish = 1;
        break;
      }
    }

    if(haveDish == -1) {
      printf("KHONG TIM THAY MON AN CAN SUA\n");
    }
  
  }
}

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
void Manager::removeDish() {
  // string name_dish;
  // int price_dish;
  int id_dish;
  vector<Dish> *tmpDish = &listDish;
  int haveDish = -1;
  if(tmpDish->empty()) {
    printf("Danh sach Thuc Uong trong");
  } else {
    printf("STT\t| ID\t| Ten\t| Price\n");
    PRINT_INFO(item, tmpDish);
    INPUT_INPOMATION("NHAP ID MON: ", id_dish, 0);
    for(int i = 0; i < tmpDish->size(); i++) {
      if((tmp->at(i)).GetID() == id_dish) {
        tmpDish->remove(tmpDish->begin() + i);
        haveDish = 1;
        break;
      }
    }
    if(haveDish == -1) {
      printf("KHONG TIM THAY MON AN CAN XOA\n"))
    }
  }
}

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
void Manager::getDish() {
  if(listDish.empty()) {
    printf("Danh sach Thuc Uong trong");
  } else {
    printf("STT\t| ID\t| Ten\t| Price\n");
    PRINT_INFO(item, listDish);
  }
}

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
int Manager::getNumberTables() {
  return Manager::numberTables;
}

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
vector<Table> Manager::getListTable() {
  return Manager::numberTables;
}

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
vector<Dish> Manager::getListDish() {
  return Manager::listDish;
}

/**
 * Class: Staff
 * Description: this is Staff class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class Staff {
  private: 
    // Manager mn;
    vector<Table> listTable;
    int noTable;
  public:
    Staff();
    void getStatusTables();
    void selectTables(int noTable);

    int getNumTables();
    void getDataFromManager(Manager* manager);
    void updateDataFromManager(Manager* manager);
    vector<Dish> getListDish();
};

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
void Staff::getDataFromManager(Manager* manager) {
  Staff::noTable = manager->getNumberTables();
  for(int i=0; i<Staff::noTable; i++) {
    Table table(*manager);
    listTable.push_back(table);
  }
}

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
void Staff::updateDataFromManager(Manager* manager) {
  int lastNoTables = Staff::noTable;
  Staff::noTable = manager->getNumberTables();
  for(int i = 0; i < manager->getNumberTables(); i++) {
    Table table(*manager);
    listTable.at(i).updateListDish(* manager);
  }
  for(int i = 0; i < Staff::noTable; i++) {
    Table table(*manager);
    listTable.push_back(table);
  }
}

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
void Staff::getNumTables() {
  return Staff::noTables;
}

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
void Staff::getStatusTables() {
  if(listTable.empty()) {
    printf("Danh sach chua duoc set");
  } else {
    printf("Ban\t|") {
      for(int i = 0; i <= Staff::noTables; i++) {
        printf("\t%d\t|", i);
      }
      printf("\n Status:\t|");
      for(int i = 0; i <= Staff::noTables; i++) {
        if(listTable.at(i).getStatus() == DA_DAT){
          printf("\tX\t|");
        } else {
          printf("\tO\t|");
        }
      }
    }
  }
}

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
void Staff::selectTables(int noTables) {
  int choice;
  if(listTable.empty()) {
    printf("Danh sach chua duoc set");
  } else {
    printf("1. Goi mon \n 2. Danh sach mon da goi\n 3. Thoanh Toan\n");
    INPUT_INPOMATION('Moi Nhap: ', choice, choice > 3 || choice < 0);
    switch (choice) {
      case 1:
        listTable.at(noTables).setListDish();
        break;
      case 2:
        listTable.at(noTables).getListDish();
        break;
      default:
        break;
    }
  }
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
  public:
    Menu();
    staff(Staff * staff);
    manager(Manager * manager);
}

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
Menu::Menu() {
  uint8_t command;
  enum Command {
      BACK,
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

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
Menu::staff(Staff * staff){
  int choice;
  do {
    staff->getStatusTables();
    INPUT_INPOMATION("Chon Ban: ", choice, choice > staff->getStatusTables());
    switch(choice) {
      case 0:
        break;
      case 1:
        staff->selectTables(choice-1);
        break;
    }
  } while(1); 
}

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
Menu::manager(Manager * manager){
  int choice;
  do {
    INPUT_INPOMATION("Chon phuong thuc: ", choice, choice > 5 || choice < 0);
    switch (choice) {
      case 0:
        return;
      case 1:
        manager->addDish();
        break;
      case 2:
        manager->updateDish();
        break;
      case 3:
        manager->removeDish();
        break;
      case 4:
        manager->getListDish();
        break;
      case 5:
        int no;
        INPUT_INPOMATION("Nhap so luong ban: ", no, 1);
        manager->getNumberTables(no);
        break;
      default:
        break;
    }
  } while (1);
  
  
}

int main() {
  Menu *menu = new Menu();
  return 0;
}