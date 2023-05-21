/*
* File: bt4.cpp
* Author: NGUYEN DINH DIEN
* Date: 20/5/2023
* Description: Tạo một lớp động vật với các thuộc tính tên, tuổi và trọng lượng, và các
              phương thức để tính chỉ số BMI, so sánh tuổi và trọng lượng của các
              động vật khác nhau.
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

/**
 * Function: Class Animal
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng Animal
 * Input:
 *    None
 * Output:
 *    None
*/
class Animal {
  private:
    string name;
    int age;
    float height; //cm
    float weight;
  public:

    /**
     * Function: Constructor Animal
     * Description: nhập thông tin khởi tạo các Animal
     * Input:
     *    sName - string
     *    iAge - int
     *    fHeight - float
     *    fWeight - float
     * Output:
     *    None
    */
    Animal(string sName, int iAge, float fHeight, float fWeight) {
      name = sName;
      age = iAge;
      height = fHeight;
      weight = fWeight;
    }
    float BMIIndex();
    float getName();
    float getAge();
    float getWeight();
};

/**
 * Function: getName
 * Description: in ra đó là động vật gì
 * Input:
 *    None
 * Output:
 *    Result - string
*/
string Animal::getName() {
  return Animal::name;
}

/**
 * Function: getAge
 * Description: in ra tuổi của động vật
 * Input:
 *    None
 * Output:
 *    Result - string
*/
float Animal::getAge() {
  return Animal::age;
}

/**
 * Function: getWeight
 * Description: in ra cân nặng của động vật
 * Input:
 *    None
 * Output:
 *    Result - string
*/
float Animal::getWeight() {
  return Animal::weight;
}

/**
 * Function: BMIIndex
 * Description: in ra chỉ số BMI của động vật
 * Input:
 *    None
 * Output:
 *    Result - string
*/
float Animal::BMIIndex() {
  return (Animal::height / pow(Animal::weight, 2));
}

/**
 * Function: weightCompare
 * Description: so sánh cân nặng của hai động vật
 * Input:
 *    animal1 - Animal object
 *    animal2 - Animal object
 * Output:
 *    None
*/
void weightCompare(Animal* animal1, Animal* animal2){
  if (animal1->getWeight() > animal2->getWeight()) {
    cout << "con" << animal1->getName() << "co trong luong lon hon con" << animal2->getName()<< endl;
  } else {
    cout << "con" << animal1->getName()<< "co trong luong nho hon con" << animal2->getName()<< endl;
  }
};

/**
 * Function: ageCompare
 * Description: so sách tuổi của nó
 * Input:
 *    animal1 - Animal object
 *    animal2 - Animal object
 * Output:
 *    None
*/
void ageCompare(Animal* animal1, Animal* animal2){
  if (animal1->getAge() > animal2->getAge()) {
    cout << "con" << animal1->getName() << "co trong luong lon hon con" << animal2->getName()<< endl;
  } else {
    cout << "con" << animal1->getName() << "co trong luong nho hon con" << animal2->getName()<< endl;
  }
};
int main() {
  Animal *animal[3];
  // animal = new Animal[10];
  animal[0] = new Animal("Dog", 5, (float)40.3, (float)15.7);
  animal[1] = new Animal("Cat", 3, (float)17.3, (float)5.7);
  animal[2] = new Animal("cow", 5, (float)140.5, (float)200.7);
  weightCompare(animal[0], animal[1]);
  ageCompare(animal[0], animal[1]);
  delete[] animal;
  return 0;
}