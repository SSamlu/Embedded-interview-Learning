#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;
class Car {
  private:
    string colorCar;
    string engineType;
    double kmNo;
  public:
    Car(string color, string engine, float mileage) {
      colorCar = color;
      engineType = engine;
      kmNo = mileage;
    }
    int maintenanceCosts();
    double mileageWentedCheck();
    void infoCarPrint();
};
int Car::maintenanceCosts() {
  return 0;
};
double Car::mileageWentedCheck() {
  return Car::kmNo;
};
void Car::infoCarPrint() {
  printf("Mau xe: %s\n", Car::colorCar);
  printf("Loại dong co: %s\n",Car::engineType);
  printf("Sp km da di: %.2f\n", Car::kmNo);
};
int main() {
  Car *xe;
  xe = new Car("white", "electric", 100.0);
  printf("Thong tin xe: \n");
  xe->infoCarPrint();
  cout << "chi phi bao tri xe: " << xe->maintenanceCosts() << "VND" << endl;
  cout << "So km da di duoc: " << xe->mileageWentedCheck() << " Km" <<endl;
  delete xe;
  return 0;
}