#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

class Human {
  private:
    string name;
    uint32_t age;
    string address;
  public:
    Human(string name, uint32_t age, string address) {
      this->name = name;
      this->age = age;
      this->address = address;
    };
    void getInfoHuman();
    uint32_t getAge();
};
void Human::getInfoHuman() {
  cout << "Ten: " << Human::name << endl;
  cout << "Age: " << Human::age << endl;
  cout << "Address: " << Human::address << endl;
}
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
  delete nguoi;
  return 0;
}