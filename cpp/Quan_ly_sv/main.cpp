/*
* File: main.cpp
* Author: NGUYEN DINH DIEN
* Date: 24/05/2023
* Description: This is file for student management
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cctype>
#include <cstring>

#include <vector>

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
typedef enum {
  NAM,
  NU
} GIOITINH;

typedef enum {
  GIOI,
  KHA,
  TRUNG_BINH,
  YEU
} HOCLUC;

typedef enum {
  TEN,
  TUOI,
  GIOI_TINH,
  DIEM
} Object;
/*
* Class: Student
* Description: This is student class
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
class Student {
  private:
    int ID;
    string name;
    int age;
    GIOITINH gioiTinh;
    float DIEM_TOAN;
    float DIEM_LY;
    float DIEM_HOA;
    float DIEM_TB;
    // static int id;
  public:
    Student();
    uint8_t getID();
    void setName(string sName);
    string getName();
    void setGioiTinh(GIOITINH GTgioiTinh);
    string getGioiTinh();
    void setAge(int uAge);
    uint8_t getAge();
    void setDiemToan(float toan);
    float getDiemToan();
    void setDiemLy(float ly);
    float getDiemLy();
    void setDiemHoa(float Hoa);
    float getDiemHoa();
    float getDiemTrungBinh();
    HOCLUC getHocLuc();
};

/*
* Class: Student
* Function: setName
* Description: This function use for constructor Student
* Input:
*   none
* Output:
*   return: None
*/

Student::Student(){
  int id = 100;
  Student::ID = id;
  id++;
}

/*
* Class: Student
* Function: setName
* Description: This function use for get ID of a Student
* Input:
*   none
* Output:
*   return: None
*/
uint8_t Student::getID(){
  return this->ID;
}

/*
* Class: Student
* Function: setName
* Description: This function use for set name of a Student
* Input:
*   name - name of Student
* Output:
*   return: None
*/
void Student::setName(string sName) {
  this->name = sName;
};

/*
* Class: Student
* Function: getName
* Description: This function use for get name of student
* Input:
*   Dont have input parameters
* Output:
*   return: Name of Student
*/
string Student::getName() {
  return Student::name;
};

/*
* Class: Student
* Function: setGioiTinh
* Description: This function use for set sex of a Student
* Input:
*   gioiTinh - sex of Student
* Output:
*   return: None
*/
void Student::setGioiTinh(GIOITINH GTgioiTinh) {
  this->gioiTinh = GTgioiTinh;
};

/*
* Class: Student
* Function: getGioiTinh
* Description: This function use for get sex of student
* Input:
*   Dont have input parameters
* Output:
*   return: Sex of Student
*/
string Student::getGioiTinh() {
  string tmp = Student::gioiTinh == NAM ? "NAM" : "NU"; 
  return tmp;
};

/*
* Class: Student
* Function: setAge
* Description: This function use for set age of a Student
* Input:
*   uAge - age of Student
* Output:
*   return: None
*/
void Student::setAge(int uAge){
    this->age = uAge;
}

/*
* Class: Student
* Function: getAge
* Description: This function use for get sex of student
* Input:
*   Dont have input parameters
* Output:
*   return: Age of Student
*/
uint8_t Student::getAge() {
  return Student::age;
};

/*
* Class: Student
* Function: setDiemToan
* Description: This function use for set mark of Math
* Input:
*   toan - mark of Math
* Output:
*   return: None
*/
void Student::setDiemToan(float toan) {
  this->DIEM_TOAN = toan;
};

/*
* Class: Student
* Function: getDiemToan
* Description: This function use for get math mark of student
* Input:
*   Dont have input parameters
* Output:
*   return: DIEM_TOAN of Student
*/
float Student::getDiemToan() {
  return Student::DIEM_TOAN;
};

/*
* Class: Student
* Function: setDiemLy
* Description: This function use for set mark of Math
* Input:
*   ly - mark of Math
* Output:
*   return: None
*/
void Student::setDiemLy(float ly) {
  this->DIEM_LY = ly;
};
float Student::getDiemLy() {
  return Student::DIEM_LY;
};

/*
* Class: Student
* Function: setDiemHoa
* Description: This function use for set mark of Math
* Input:
*   Hoa - mark of Math
* Output:
*   return: None
*/
void Student::setDiemHoa(float Hoa) {
  this->DIEM_HOA = Hoa;
};

/*
* Class: Student
* Function: getDiemHoa
* Description: This function use for get DIEM_HOA of student
* Input:
*   Dont have input parameters
* Output:
*   return: Name of Student
*/
float Student::getDiemHoa() {
  return Student::DIEM_HOA;
};

/*
* Class: Student
* Function: getDiemTrungBinh
* Description: This function use for get DIEN_TB of student
* Input:
*   Dont have input parameters
* Output:
*   return: DIEM_TB of Student
*/

float Student::getDiemTrungBinh(){
  if(Student::DIEM_TOAN < 0 || Student::DIEM_TOAN > 10) {
    printf("ERROR! CHUA NHAP DIEM TOAN");
    return -1;
  }
  if(Student::DIEM_LY < 0 || Student::DIEM_LY > 10) {
    printf("ERROR! CHUA NHAP DIEM LY");
    return -1;
  }
  if(Student::DIEM_HOA < 0 || Student::DIEM_HOA > 10) {
    printf("ERROR! CHUA NHAP DIEM HOA");
    return -1;
  }
  Student::DIEM_TB = (Student::DIEM_HOA + Student::DIEM_LY + Student::DIEM_TOAN) / 3;
  return Student::DIEM_TB;
}

/*
* Class: Student
* Function: getHocLuc
* Description: This function use for get HOCLUC of student
* Input:
*   Dont have input parameters
* Output:
*   return: Name of Student
*/
HOCLUC Student::getHocLuc() {
  float DiemTB = Student::getDiemTrungBinh();
  if(DiemTB >= 8) {
    return GIOI;
  } else if(DiemTB >= 6.5) {
    return KHA;
  } else if(DiemTB >= 5.5) {
    return TRUNG_BINH;
  } else {
    return YEU;
  }
}

/*
* Class: Menu
* Description: This is Menu class
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
class Menu {
  private:
    vector<Student> Database;
    uint8_t checkInput(void *value, Object object);

  public:
    Menu();
    void addStudent();
    void updateStudentByID(uint8_t id);
    void removeStudent(uint8_t id);
    void searchStudentByName();
    void sortListStudentByGPA();
    void sortListStudentByName();
    void showListStudent();
    int checkExit(char* str);
    // void showList();
};

uint8_t Menu::checkInput(void *value, Object object) {
  uint8_t status = 1;
  switch (object)
  {
  case TEN:
    /* code */
    // CHECK_INFO(*(string*) value == '', "ERROR: Ten khong hop le, vui long nhap lai", status = 0);
    // if (*(string*) value == '') {
    //   cout << "ERROR: Ten khong hop le, vui long nhap lai";
    //   status = 0;
    // }
    break;
  case TUOI:
    CHECK_INFO(*(int*) value < 7 || *(int*) value > 24, "ERROR: Tuoi khong hop le, vui long nhap lai\n", status = 0);
    break;
  case GIOI_TINH:
    CHECK_INFO(*(string*) value != "NAM" && *(string*) value != "NU", "ERROR: Gioi Tinh khong hop le, vui long nhap lai\n", status = 0);
    break;
  case DIEM:
    CHECK_INFO(*(float *) value < 0 || *(float *) value > 10, "Error: Diem khong hop le, vui long nhap lai\n", status = 0);
    break;
  default:
    status = 0;
    break;
  }
  return status;
};

/*
* Class: Menu
* Function: addStudent
* Description: This function use for adding student
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::addStudent(){
  Student sv;
  printf("Thong tin Sinh vien:\n");
  string ten;
  string s_gioiTinh;
  int age;
  float diemToan;
  float diemLy;
  float diemHoa;
  string exit;
  while(1) {
    if(Menu::Database.size() > 0) {
      cout << "Ban co muon tiep tuc khong: \n 'exit' de thoat \n '1' de tiep tuc" << endl;
      cin >> exit;
      if(exit == "exit") return;
    }
    INPUT_INPOMATION("Nhap Ten: ", ten, Menu::checkInput(&ten, TEN));
    sv.setName(ten);
    INPUT_INPOMATION("Gioi tinh(NAM/NU)", s_gioiTinh, Menu::checkInput(&s_gioiTinh, GIOI_TINH));
    sv.setGioiTinh(s_gioiTinh == "NAM" ? NAM : NU);
    INPUT_INPOMATION("So tuoi: ", age, Menu::checkInput(&age, TUOI));
    sv.setAge(age);
    INPUT_INPOMATION("Nhap Diem Toan: ", diemToan, Menu::checkInput(&diemToan, DIEM));
    sv.setDiemToan(diemToan);
    INPUT_INPOMATION("Nhap Diem Ly: ", diemLy, Menu::checkInput(&diemLy, DIEM));
    sv.setDiemLy(diemLy);
    INPUT_INPOMATION("Nhap Diem Hoa: ", diemHoa, Menu::checkInput(&diemHoa, DIEM));
    sv.setDiemHoa(diemHoa);
    Database.push_back(sv);
  }
}

/*
* Class: Menu
* Function: updateStudentByID
* Description: This function use for update student by ID
* Input:
*   id - id of student
* Output:
*   return: none
*/
void Menu::updateStudentByID(uint8_t id) {
  uint8_t index = -1;
  for (int i = 0; i < Database.size(); i++) {
    if (Database[i].getID() == id) {
      index = i;
      break;
    }
  }
  if (index != -1) {

    cout << "Da xoa sinh vien co ID " << id << endl;
  }
  else {
    cout << "Khong tim thay sinh vien co ID " << id << endl;
  }
}

/*
* Class: Menu
* Function: searchStudentByName
* Description: This function use for search student by name
* Input:
*   id - id of student
* Output:
*   return: none
*/
void Menu::searchStudentByName() {
  string mName;
  if (Menu::Database.empty()) {
    cout << "Danh sach sinh vien rong." << endl;
    return;
  }
  INPUT_INPOMATION("Nhap ten sinh vien can tim kiem: ", mName, 1);
  for(auto item : Menu::Database) {
    if(strcmp(item.getName().c_str(), mName.c_str()) == 0) {
       printf("ID\t TEN\t\t GIOITINH\t TUOI\t TOAN\t LY\t HOA\t GPA\t HOCLUC\n");
      printf("%d\t %s\t\t %s\t\t %d\t %.2lf\t %.2lf\t %.2lf\t %.2lf\t %d\n", item.getID(), item.getName().c_str(), item.getGioiTinh().c_str(),\
        item.getAge(), item.getDiemToan(), item.getDiemLy(), item.getDiemHoa(), item.getDiemTrungBinh(), item.getHocLuc());
      printf("\n");
    }
  }
}

void Menu::sortListStudentByGPA() {
  if (Database.empty()) {
    cout << "Danh sach sinh vien rong." << endl;
    return;
  }
  vector<Student> svList = Database;
  for (int i = 0; i < Database.size() - 1; i++) {
    for (int j = i + 1; j < Database.size(); j++) {
      if (Database[i].getDiemTrungBinh() > Database[j].getDiemTrungBinh()) {
        swap(Database[i], Database[j]);
      }
    }
  }
  PRINT_INFO(item, svList);
};
/*
* Class: Menu
* Function: showListStudent
* Description: This function use for adding student
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::showListStudent(){
  if (Menu::Database.empty()) {
    cout << "Danh sach sinh vien rong." << endl;
    return;
  }
  PRINT_INFO(item, Menu::Database);
}

/*
* Class: Menu
* Function: removeStudent
* Description: This function use for remove student
* Input:
*   id - id of students
* Output:
*   return: none
*/
void Menu::removeStudent(uint8_t id) {
    uint8_t index = -1;
    for (int i = 0; i < Menu::Database.size(); i++) {
      if (Menu::Database[i].getID() == id) {
        index = i;
        break;
      }
    }

    if (index != -1) {
        Menu::Database.erase(Menu::Database.begin() + index);
        cout << "Da xoa sinh vien co ID " << id << endl;
    }
    else {
        cout << "Khong tim thay sinh vien co ID " << id << endl;
    }
}

/*
* Class: Menu
* Function: sortListStudentByName
* Description: This function use for sort list student by name
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
void Menu::sortListStudentByName() {
  if (Menu::Database.empty()) {
    cout << "Danh sach sinh vien rong." << endl;
    return;
  }

  vector<Student> svList = Menu::Database;
  for (int i = 0; i < Menu::Database.size() - 1; i++) {
    for (int j = i + 1; j < Menu::Database.size(); j++) {
      if (Database[i].getName() > Database[j].getName()) {
        swap(Database[i], Database[j]);
      }
    }
  }
  cout << "Danh sach sinh vien sap xep theo ten:" << endl;
  PRINT_INFO(sv, svList);
  // for (auto sv : svList) {
  //     cout << "ID: " << sv.getID() << endl;
  //     cout << "Ten: " << sv.getName() << endl;
  //     cout << "Gioi tinh: " << sv.getGioiTinh() << endl;
  //     cout << "Tuoi: " << sv.getAge() << endl;
  //     cout << "Diem Toan: " << sv.getDiemToan() << endl;
  //     cout << "Diem Ly: " << sv.getDiemLy() << endl;
  //     cout << "Diem Hoa: " << sv.getDiemHoa() << endl;
  //     cout << "Diem Trung Binh: " << sv.getDiemTrungBinh() << endl;
  //     cout << "Hoc Luc: " << sv.getHocLuc() << endl;
  //     cout << "---------------------------------" << endl;
  // }
}

// int checkExit(string str) {
//   if(strcmp(str.c_str(), "EXIT") == 0) return 1;
//   return 0;
// };

/*
* Class: Menu
* Function: sortListStudentByName
* Description: This function use for constructor Menu
* Input:
*   Dont have input parameters
* Output:
*   return: none
*/
Menu::Menu(){
  uint8_t phim = 0;

  do
  {
    printf("------CHUONG TRINH QUAN LY SINH VIEN------\n");
    printf("1. Them Sinh Vien\n");
    printf("2. Cap nhat Thong Tin Sinh Vien\n");
    printf("3. Xoa Sinh Vien boi ID\n");
    printf("4. Tim kiem Thong Tin theo Ten \n");
    printf("5. Sap Xep Sinh Vien theo GPA\n");
    printf("6. Sap Xep Sinh Vien theo Ten\n");
    printf("7. Hien thi Danh Sach Sinh Vien\n");
    printf("Nhan '0' de thoat\n");
    printf("-------------------------------------------\n");
    cin >> phim;
    uint8_t id;
    string mName;
    switch (phim)
    {
    case '1':
      addStudent();
      break;
    case '2':
      cout << "Nhap ID sinh vien can cap nhat: ";
      cin >> id;
      updateStudentByID(id);
      break;
    case '3':
      cout << "Nhap ID sinh vien can remove: ";
      cin >> id;
      removeStudent(id);
      break;
    case '4':
      searchStudentByName();
      break;
    case '5':
      sortListStudentByGPA();
      break;
    case '6':
      sortListStudentByName();
      break;
    case '7':
      showListStudent();
      break;
    default:
      cout << "Lua chon khong hop le!\n";
      break;
    }
  } while (1);
}
/*
* Function: swap
* Description: This function swap object student
* Input:
*   student1 - object
*   student1 - object
* Output:
*   return: none
*/
void swap(Student *student1, Student *student2)
{
    Student student = *student1;
    *student1 = *student2;
    *student2 = student;
}

/*
* Function: swap
* Description: This function compare character in a string
* Input:char
*   word - char
*   key - char
* Output:
*   return: int
*/
int compareWords(char* word, char* key) {
  uint8_t i = 0, j = 0;
  while (*(word + i) != '\0' && *(key + j) != '\0'){
    int wordAscii = (int)(*(word + i));
    int keyAscii = (int)(*(key + j));
    if (wordAscii > keyAscii){
      return 1;
    } else if (wordAscii < keyAscii) {
      return 0;
    }
    i++; j++;
  }
  return 0;
}

int main() {
  Menu *menu;
  menu = new Menu();
  return 0;
}