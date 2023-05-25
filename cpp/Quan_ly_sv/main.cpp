/*
* File: main.cpp
* Author: NGUYEN DINH DIEN
* Date: 24/05/2023
* Description: This is file for student management
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

typedef enum {
  NAME,
  NU
} GIOITINH;

typedef enum {
  GIOI,
  KHA,
  TRUNG_BINH,
  YEU
} HOCLUC;

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
    uint8_t ID;
    string name;
    uint8_t age;
    GIOITINH gioiTinh;
    float DIEM_TOAN;
    float DIEM_LY;
    float DIEM_HOA;
    float DIEM_TB;
  public:
    Student();
    uint8_t getID();
    void setName(string name);
    string getName();
    void setGioiTinh(GIOITINH gioiTinh);
    GIOITINH getGioiTinh();
    void setAge(uint8_t age);
    uint8_t getAge();
    void setDiemToan(float toan);
    float getDiemToan();
    void setDiemLy(float ly);
    float getDiemLy();
    void setDiemHoa(float Hoa);
    float getDiemHoa();
    float getDiemTrungBinh();
    HOCLUC getHocLuc();
}

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
  static uint8_t id = 100;
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
void setName(string name) {
  this->name = name;
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
string getName() {
  return name;
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
void setGioiTinh(GIOITINH gioiTinh) {
  this->gioiTinh = gioiTinh;
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
GIOITINH getGioiTinh() {
  return gioiTinh;
};

/*
* Class: Student
* Function: setAge
* Description: This function use for set age of a Student
* Input:
*   age - age of Student
* Output:
*   return: None
*/
void Student::setAge(uint8_t age){
    this->age = age;
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
uint8_t getAge() {
  return age;
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
void setDiemToan(float toan) {
  this->DIEM_TOAN = toan;
};


float getDiemToan() {
  return Diem_TOAN;
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
void setDiemLy(float ly) {
  this->DIEM_LY = ly;
};
float getDiemLy() {
  return DIEM_LY;
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
void setDiemHoa(float Hoa) {
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
float getDiemHoa() {
  return DIEM_HOA;
};

/*
* Class: Student
* Function: getDiemTrungBinh
* Description: This function use for get DIEN_TB of student
* Input:
*   Dont have input parameters
* Output:
*   return: Name of Student
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
  public:
    void addStudent();
    void updateStudentByID(uint8_t id);
    void removeStudent(uint8_t id);
    void searchStudentByName(string name);
    void sortListStudentByGPA();
    void sortListStudentByName();
    void showListStudent();
    // void showList();
}

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
  uint8_t age;
  float diem;
  cout << "Nhap ten: ";
  cin >> ten;
  sv.setName(string ten);
  cout << "Gioi tinh(Nam/Nu)";
  cin >> s_gioiTinh;
  sv.setGioiTinh(s_gioiTinh);
  cout << "So tuoi: ";
  cin >> age;
  sv.setAge(age);
  cout << "Nhap Diem Toan: ";
  cin >> diem;
  sv.setDiemToan(diem);
  cout << "Nhap Diem Ly: ";
  cin >> diem;
  sv.setDiemLy(diem);
  cout << "Nhap Diem Hoa: ";
  cin >> diem;
  sv.setDiemHoa(diem);
  Database.push_back(sv);
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
    if (Database[i].id == id) {
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
void Menu::searchStudentByName(string name) {

}

void Menu::sortListStudentByGPA() {
  if (Database.empty()) {
    cout << "Danh sach sinh vien rong." << endl;
    return;
  }
  vector<SinhVien> svList = danhSachSinhVien;
  for (int i = 0; i < Database.size() - 1; i++) {
    for (int j = i + 1; j < Database.size(); j++) {
      if (Database[i].getDiemTrungBinh() > Database[j].getDiemTrungBinh()) {
        swap(Database[i], Database[j]);
      }
    }
  }
  printf("\nID\t TEN\t\t GIOITINH\t TUOI\t TOAN\t LY\t HOA\t GPA\t HOCLUC\n");
  for(item : svList){
    cout << "ID: "<< item.getID();
    cout << "name: "<< item.getName();
    cout << "age: "<< item.getAge();
    cout << "sex: "<< item.getGioiTinh();
    cout << "Toan: "<< item.getDiemToan();
    cout << "Ly: "<< item.getDiemLy();
    cout << "Hoa: "<< item.getDiemHoa();
    cout << "Diem TB: "<< item.getDiemTrungBinh();
    count << "Hoc Luc: "<< item.getHocLuc();
  }
}
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

  printf("\nID\t TEN\t\t GIOITINH\t TUOI\t TOAN\t LY\t HOA\t GPA\t HOCLUC\n");
  for(item : Menu::Database){
    cout << "ID: "<< item.getID();
    cout << "name: "<< item.getName();
    cout << "age: "<< item.getAge();
    cout << "sex: "<< item.getGioiTinh();
    cout << "Toan: "<< item.getDiemToan();
    cout << "Ly: "<< item.getDiemLy();
    cout << "Hoa: "<< item.getDiemHoa();
    cout << "Diem TB: "<< item.getDiemTrungBinh();
    count << "Hoc Luc: "<< item.getHocLuc();
  }
  printf("\n");
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
void removeStudent(uint8_t id) {
    uint8_t index = -1;
    for (int i = 0; i < Database.size(); i++) {
      if (Database[i].id == id) {
        index = i;
        break;
      }
    }

    if (index != -1) {
        Database.erase(Database.begin() + index);
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
void sortListStudentByName() {
  if (Database.empty()) {
    cout << "Danh sach sinh vien rong." << endl;
    return;
  }

  vector<Student> svList = Database;
  for (int i = 0; i < Database.size() - 1; i++) {
    for (int j = i + 1; j < Database.size(); j++) {
      if (Database[i].getName() == Database[j].getName())> Database[j].name) {
        swap(Database[i], Database[j]);
      }
    }
  }

  cout << "Danh sach sinh vien sap xep theo ten:" << endl;
  for (const auto& sv : svList) {
      cout << "ID: " << sv.getID() << endl;
      cout << "Ten: " << sv.getName() << endl;
      cout << "Gioi tinh: " << sv.getGioiTinh << endl;
      cout << "Tuoi: " << sv.getAge() << endl;
      cout << "Diem Toan: " << sv.getDiemToan() << endl;
      cout << "Diem Ly: " << sv.getDiemLy() << endl;
      cout << "Diem Hoa: " << sv.getDiemHoa() << endl;
      cout << "Diem Trung Binh: " << sv.getDiemTrungBinh() << endl;
      cout << "Hoc Luc: " << sv.getHocLuc() << endl;
      cout << "---------------------------------" << endl;
  }
}

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
    printf("8. Thoat\n");
    printf("-------------------------------------------\n");
    cin >> phim;
    uint8_t id;
    switch (key)
    {
    case 1:
      addStudent();
      break;
    case 2:
      cout << "Nhap ID sinh vien can cap nhat: ";
      cin >> id;
      updateStudentByID();
      break;
    case 3:
      cout << "Nhap ID sinh vien can remove: ";
      cin >> id;
      removeStudent(id);
      break;
    case 4:
      string name;
      cout << "Nhap ten sinh vien can tim kiem: ";
      cin >> name;
      searchStudentByName(name);
      break;
    case 5:
      sortListStudentByGPA();
      break;
    case 6:
      sortListStudentByName();
      break;
    case 7:
      showListStudent()
      break;
    case 8:
      exit(0);
      break;
    default:
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
int main() {
  Menu *menu;
  menu = new Menu();
  return 0;
}