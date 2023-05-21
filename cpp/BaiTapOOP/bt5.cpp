/*
* File: bt5.cpp
* Author: NGUYEN DINH DIEN
* Date: 20/5/2023
* Description: Tạo một lớp người với các thuộc tính tên, tuổi và địa chỉ, và các
              phương thức để in thông tin của người đó và tính tuổi của người đó.
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

/**
 * Function: Class Human
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng Human
 * Input:
 *    None
 * Output:
 *    None
*/

class Human {
  private:
    string name;
    uint32_t age;
    string address;
  public:

    /**
     * Function: Constructor Human
     * Description: nhập thông tin khởi tạo các Human
     * Input:
     *    name - string
     *    age - uint32_t
     *    address - string
     * Output:
     *    None
    */
    Human(string name, uint32_t age, string address) {
      this->name = name;
      this->age = age;
      this->address = address;
    };
    void getInfoHuman();
    uint32_t getAge();
};

/**
 * Function: getInfoHuman
 * Description: in ra thông tin của Human
 * Input:
 *    None
 * Output:
 *    None
*/
void Human::getInfoHuman() {
  cout << "Ten: " << Human::name << endl;
  cout << "Age: " << Human::age << endl;
  cout << "Address: " << Human::address << endl;
}

/**
 * Function: getAge
 * Description: in ra tuổi của Human
 * Input:
 *    None
 * Output:
 *    None
*/
uint32_t Human::getAge() {
  return Human::age;
}
int main() {
  Human *nguoi;
  nguoi = new Human("Nuyen Dinh Dien", 24, "Dai Loc, Quang Nam");
  printf("Thong tin: \n");
  nguoi->getInfoHuman();
  cout << "So tuoi: " << nguoi->getAge() << endl;
  delete nguoi;
  return 0;
}