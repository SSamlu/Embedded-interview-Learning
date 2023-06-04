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
  } while(checkCondition);              
  
#define CHECK_INFO(condition, text1, status) \
  if(condition) {                           \
    cout << #text1;                          \
    status;                             \
  }

#define PRINT_INFO(item, Database, numberOrder)\
  printf("STT\t| ID\t| Ten\t| Price\n");                                                  \
  for (auto item : Database) {                                                                                                 \
    printf("%d\t| \t%s\t| \t%s\t| \t%d\n", numberOrder, item.getID(), item.getName(), item.getPrice());   \
    numberOrder++;\
  }                                                                                                                         \
  printf("\n");

#define CHECK_LIST(dataVector, notify1, content)\
  if(dataVector.empty()) {\
    printf(notify1); \
  } else {\
    content \
  }

/**
 * Function: Marco
 * Discription: this is function marco
 * Input:
 *    content - content of method
*/
#define LIST(content)\
  do {\
    content\
    printf("NHAN PHIM 0 DE THOAT \n");\
    cin >> choice;\
  } while (choice == 1)

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
  public:
    Dish(string nameDish, int priceDish);
    // void SetID(const int id);
    void setName(const string name);
    void setPrice(const int price);
    int getID();
    string getName();
    int getPrice();
};

/*
* Function: Dish
* Description: This function use for constructor Dish
* Input:
*   none
* Output:
*   return: None
*/
Dish::Dish(string nameDish, int priceDish){
  static int id = 100;
  Dish::ID = id;
  id++;
  this->nameDish = nameDish;
  this->priceDish = priceDish;
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

int Dish::getID() {
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
string Dish::getName() {
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
int Dish::getPrice() {
  return this->priceDish;
}

class OrderDish {
  private:
    int quantityDish = 0;
    string nameDish;
    int priceDish;
    int IDDish;
  public:
    OrderDish(int id, string name, int quantity, int price);
    void setQuantity(int quantity);
    int getQuantity();
    string getName();
    int getPrice();
    int getIDDish();
};

  OrderDish::OrderDish(int id, string name, int quantity, int price) {
    this->IDDish = id;
    this->nameDish = name;
    this->priceDish = price;
    this->quantityDish = quantity; 
  };

/*
 * Function: setQuantity
 * Description: 
 * Input:
 *  quantity - quantity of dish 
*/
void OrderDish::setQuantity(int quantity) {
  OrderDish::quantityDish = quantity;
};

/*
 * Function: getQuantity
 * Description: 
 * Output:
 *  Return - quantity of dish 
*/
int OrderDish::getQuantity() {
  return OrderDish::quantityDish; // this->quantityDish
}

string OrderDish::getName() {
  return OrderDish::nameDish; // this->nameDish
}

int OrderDish::getPrice() {
  return OrderDish::priceDish; // this->priceDish
}

int OrderDish::getIDDish() {
  return OrderDish::IDDish; // this->idDish
}
typedef enum {
  CHUA_DAT,
  DA_DAT
} statusTable;

class Manager {
  private:
    int idDish;
    int numberTables = 0;
    vector<Dish> listDish;
  public:
    void setNumberTables(int quantityTables);
    void addDish();
    void updateDish();
    void removeDish();
    void getDish();
    int getNumberTables();
    // vector<Table> getListTable();
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
  Manager::numberTables = quantityTables;
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
  int choice;
  int price_dish;
  LIST(
    printf("**Them mon moi**\n");
    INPUT_INPOMATION("NHAP TEN MON: ", name_dish, 0);
    INPUT_INPOMATION("NHAP GIA: ", price_dish, price_dish < 0);
    Dish dish(name_dish, price_dish);
    this->listDish.push_back(dish);
    printf("Nhan phim 1 De tiep tuc\n");
  );
}

/*
* Function: updateDish
* Description: This function use for update Dish ordered
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
  int choice;
  CHECK_LIST(
    listDish,
    "List order null\n",
    printf("----list order----\n");
    int orderNo = 1;
    PRINT_INFO(item, Manager::listDish, orderNo);
    LIST(
      printf("**Update Dish**\n");
      INPUT_INPOMATION("NHAP ID MON: ", id_dish, 0);
      for(int i = 0; i < tmpDish->size(); i++) {
        if((tmpDish->at(i)).getID() == id_dish) {
          INPUT_INPOMATION("NHAP TEN MON: ", name_dish, 0);
          INPUT_INPOMATION("NHAP GIA: ", price_dish, price_dish < 0);
          tmpDish->at(i).setName(name_dish);
          tmpDish->at(i).setPrice(price_dish);
          haveDish = 1;
          break;
        }
      }
      if(haveDish == -1) {
        printf("ERR: KHONG TIM THAY MON AN CAN SUA\n");
      }
      printf("Hay nhan phim 1 neu ban muon tiep tuc");
    );
  );
}

/*
* Function: removeDish
* Description: This function use for remove Dish
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
  int choice;
  CHECK_LIST(
    listDish,
    "List order null\n",
    printf("----list order----\n");
    int orderNo = 1;
    PRINT_INFO(item, Manager::listDish, orderNo);
    LIST(
      INPUT_INPOMATION("NHAP ID MON: ", id_dish, 0);
      for(int i = 0; i < tmpDish->size(); i++) {
        if((tmpDish->at(i)).getID() == id_dish) {
          tmpDish->erase(tmpDish->begin() + i);
          haveDish = 1;
          break;
        }
      }
      if(haveDish == -1) {
        printf("KHONG TIM THAY MON AN CAN XOA\n");
      }
    );
  );
}

/*
* Function: getDish
* Description: This function use for get Dish
* Input:
*   None
* Output:
*   return: None
*/
void Manager::getDish() {
  int choice;
  CHECK_LIST(
    listDish,
    "List order null\n",
    LIST(
      printf("----List Dish----\n");
      int orderNo;
      PRINT_INFO(item, Manager::listDish, orderNo);
      printf("Hay nhan phim 1 neu ban muon tiep tuc");
    );
  );
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
// vector<Table> Manager::getListTable() {
//   return Manager::numberTables;
// }

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
    statusTable status = CHUA_DAT;
    vector<Dish> listDish;
    vector<OrderDish> listOrderDish;
    
  public:
    Table(Manager manager);
    // void setTableID(const int id);
    // void setStatus(statusTable status); //locked
    void updateListDish(Manager manager);

    // int getTableID(); //locked
    statusTable getStatus();
    void orderDish();
    void getTotalPrice();
    void getOrderDish();
    vector<Dish> getListDish(); // locked
};

/*
* Function: Dish
* Description: This function use for constructor Table, copy list dish of manager created to order
* Input:
*   manager - object Manager
* Output:
*   return: None
*/
Table::Table(Manager manager) {
  for(auto data : manager.getListDish()) {
    this->listDish.push_back(data);
  }
}

/*
* Function: setName
* Description: This function use for set name of Dish
* Input:
*   name - string
* Output:
*   return: None
*/
// void Table::setTableID(const int id) {
//   this->tableID = id;
// };

/*
* Function: setName
* Description: This function use for set name of Dish
* Input:
*   name - string
* Output:
*   return: None
*/
// void Table::setStatus(statusTable status) {
//   this->status = status;
// };

/*
* Function: setName
* Description: This function use for set name of Dish
* Input:
*   name - string
* Output:
*   return: None
*/
void Table::orderDish() {
  int choice;
  int id_dish;
  int quantity;
  vector<Dish> *tmpDish = &listDish;
  int haveDish = -1;
  CHECK_LIST(
    listDish,
    "List order null\n",
    int numberOrder = 1;
    PRINT_INFO(item, Table::listDish, numberOrder);
    LIST(
      INPUT_INPOMATION("Nhap ID Mon An: ", id_dish, 0);
      for(int i = 0; i < tmpDish->size(); i++) {
        if(tmpDish->at(i).getID() == id_dish) {
          INPUT_INPOMATION("NHAP SO LUONG MON: ", quantity, quantity < 0);
          OrderDish dish(tmpDish->at(i).getID(), tmpDish->at(i).getName(), quantity, tmpDish->at(i).getPrice());
          listOrderDish.push_back(dish);
          this->status = DA_DAT;
          haveDish = 1;
          break;
        }
      }
      if(haveDish != -1) {
        printf("KHONG CO THONG TIN CUA MON AN\n");
      }
    );
  )
}

/*
* Function: getTableID
* Description: This function use for get  number Table
* Input:
*   Dont have input parameters
* Output:
*   return: tableID of Table
*/
// int Table::getTableID() {
//   return this->tableID;
// }

/*
* Function: getStatus
* Description: This function use for get  number Table
* Input:
*   Dont have input parameters
* Output:
*   return: tableID of Table
*/
statusTable Table::getStatus() {
  return this->status;
}

/*
* Function: updateListDish
* Description: This function use for update List Dish
* Input:
*   Dont have input parameters
* Output:
*   return: tableID of Table
*/
void Table::updateListDish(Manager manager) {
  Table::listDish.clear();
  for(auto item : manager.getListDish()) {
    listDish.push_back(item);
  }
}

void Table::getOrderDish() {
  int choice;
  CHECK_LIST(
    this->listDish,
    "List order is null\n",
    LIST(
      printf("----List Dish----\n");
      int orderNo;
      PRINT_INFO(item, Table::listDish, orderNo);
      printf("Hay nhan phim 1 neu ban muon tiep tuc");
    );
  );
};

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
    int noTable = 0;
  public:
    // Staff();
    void getStatusTables();
    void selectTables(int noTable);
    int getNumTables();
    void getDataFromManager(Manager* manager);
    void updateDataFromManager(Manager* manager);
    // vector<Dish> getListDish();
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
  for(int i = 0; i < Staff::noTable; i++) {
    Table table(*manager);
    listTable.push_back(table);
  }
}

/*
* Function: updateDish
* Description: This function use to update Data From Manager
* Input:
*   manager - object
* Output:
*   return: None
*/
void Staff::updateDataFromManager(Manager* manager) {
  int lastNoTables = Staff::noTable;
  Staff::noTable = manager->getNumberTables();
  // update info dish
  for(int i = 0; i < lastNoTables; i++) {
    Table table(*manager);
    listTable.at(i).updateListDish(*manager);
  }
  // amount table want to setup
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
*   return: number Table
*/
int Staff::getNumTables() {
  return Staff::noTable;
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
  CHECK_LIST(
    Staff::listTable,
    "Table of your is null\n",
    printf("----Status table----\n");
    printf("Ban     |");
    for(int i = 1; i <= Staff::noTable; i++) {
      printf("\t%d\t|", i);
    }
    printf("\nStatus: |");
    for(int i = 0; i < Staff::noTable; i++) {
      if(listTable.at(i).getStatus() == DA_DAT){
        printf("\tX\t|");
      } else {
        cout << listTable.at(i).getStatus();
        printf("\tO\t|");
        break;
      }
    }
  );
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
  CHECK_LIST(
    this->listTable,
    "Table of your not setup yet!\n",
    printf("------BAN %d------\n", Staff::noTable + 1);
    printf("1. Goi mon \n 2. Danh sach mon da goi\n 3. Thoanh Toan\n");
    printf("0. Thoat\n");
    INPUT_INPOMATION('Moi Nhap: ', choice, choice > 3 || choice < 0);
    switch (choice) {
      case 1:
        this->listTable.at(noTables).orderDish();
        break;
      case 2:
        this->listTable.at(noTables).getOrderDish();
        break;
      case 3:
        // this->listTable.at(noTables).getTotalPrice();
        break;
      case 0:
        return;
      default:
        break;
    }
  );
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
};

/*
* Function: updateDish
* Description: This function use for update Dish
* Input:
*   None
* Output:
*   return: None
*/
Menu::Menu() {
  int command;
  Manager mn;
  Staff st;
  enum Command {
      BACK,
      MANAGER,
      STAFF
  };
  while(1) {
    printf("------CHUONG TRINH QUAN LY ORDER THUC UONG------\n");
    printf("1. Quan ly\n");
    printf("2. Nhan Vien\n");
    printf("0. Thoat\n");
    printf("-------------------------------------------\n");
    INPUT_INPOMATION("Nhan phim : ", command, command > 2 || command < 0);
    switch (command) {
    case BACK:
      exit(0);
      break;
    case MANAGER:
        manager(&mn);
        st.getDataFromManager(&mn); //get Data from manager
        break;
    case STAFF:
        st.updateDataFromManager(&mn); //update data from manager
        staff(&st);
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
    printf("*--Nhan vien--*\n");
    staff->getStatusTables();
    printf("\n0. Thoat\n");
    printf("----------------");
    INPUT_INPOMATION("Chon Ban: ", choice, choice > staff->getNumTables() || choice < 0);
    switch(choice) {
      case 0:
        return 0;
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
Menu::manager(Manager* manager){
  int choice;
  do {
    printf("\n------QUAN LY------\n");
    printf("1. Them mon\n");
    printf("2. Sua mon\n");
    printf("3. Xoa mon\n");
    printf("4. Danh sach mon an\n");
    printf("5. Dat so luong ban\n");
    printf("0. Thoat\n");
    printf("-------------------------------------------\n");
    INPUT_INPOMATION("Chon phuong thuc: ", choice, choice > 5 || choice < 0);
    switch (choice) {
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
        INPUT_INPOMATION("Nhap so luong ban: ", no, 0);
        manager->setNumberTables(no);
        break;
      case 0:
        return 0;
      default:
        break;
    }
  } while (1);
  
  
}

int main() {
  Menu *menu = new Menu();
  delete menu;
  return 0;
}