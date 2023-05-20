#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

class Animal {
  private:
    string name;
    int age;
    float height; //cm
    float weight;
  public:
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

string Animal::getName() {
  return Animal::name;
}
float Animal::getAge() {
  return Animal::age;
}
float Animal::getWeight() {
  return Animal::weight;
}
float Animal::BMIIndex() {
  return (Animal::height / pow(Animal::weight, 2));
}
void weightCompare(Animal* animal1, Animal* animal2){
  if (animal1->getWeight() > animal2->getWeight()) {
    cout << "con" << animal1->getName() << "co trong luong lon hon con" << animal2->getName()<< endl;
  } else {
    cout << "con" << animal1->getName()<< "co trong luong nho hon con" << animal2->getName()<< endl;
  }
};
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