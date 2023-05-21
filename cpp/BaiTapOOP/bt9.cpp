/*
* File: bt9.cpp
* Author: NGUYEN DINH DIEN
* Date: 20/5/2023
* Description: Tạo một lớp xe hơi với các thuộc tính màu sắc, kiểu động cơ và số km
              đã đi, và các phương thức để tính toán chi phí bảo trì, kiểm tra số km
              đã đi và in thông tin về xe.
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

/**
 * Function: Class Car
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng Car
 * Input:
 *    None
 * Output:
 *    None
*/

class Car {
  private:
    string colorCar;
    string engineType;
    double kmNo;
  public:
    /**
     * Function: Constructor Car
     * Description: nhập thông tin khởi tạo các Car
     * Input:
     *    color - string
     *    engine - string
     *    mileage - float
     * Output:
     *    None
    */
    Car(string color, string engine, float mileage) {
      colorCar = color;
      engineType = engine;
      kmNo = mileage;
    }
    int maintenanceCosts();
    double mileageWentedCheck();
    void infoCarPrint();
};

/**
 * Function: maintenanceCosts
 * Description: chi phí sửa chữa
 * Input:
 *    None
 * Output:
 *    Result - int
*/
int Car::maintenanceCosts() {
  if(Car::kmNo < 1000) return 1000;
  else return 2000;
};

/**
 * Function: mileageWentedCheck
 * Description: Kiểm tra số km đã đi
 * Input:
 *    None
 * Output:
 *    Result - double
*/
double Car::mileageWentedCheck() {
  return Car::kmNo;
};

/**
 * Function: infoCarPrint
 * Description: in ra thông số xe
 * Input:
 *    None
 * Output:
 *    None
*/
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