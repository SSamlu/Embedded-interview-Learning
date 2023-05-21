/*
* File: bt3.cpp
* Author: NGUYEN DINH DIEN
* Date: 20/5/2023
* Description: Tạo một lớp hình tròn với bán kính và các phương thức để tính chu vi
              và diện tích của hình tròn.
*/

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

/**
 * Function: Class hinhTron
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng hinhTron
 * Input:
 *    None
 * Output:
 *    None
*/

class hinhTron {
  private:
    float banKinh;
    const float pi = 3.14;
  public:
    /**
     * Function: Constructor hinhTron
     * Description: nhập thông tin khởi tạo các hinhTron
     * Input:
     *    ht - float
     * Output:
     *    None
    */
    hinhTron(float ht) {
      banKinh = ht;
    };
    float chuViHinhTron();
    float dienTichHinhTron();
};

/**
 * Function: chuViHinhTron
 * Description: in ra kết quả chu vi hình tròn dựa trên bán kính
 * Input:
 *    None
 * Output:
 *    a - float
*/
float hinhTron::chuViHinhTron() {
  float a = 2 * hinhTron::banKinh * hinhTron::pi;
  return (2 * hinhTron::banKinh * hinhTron::pi);
};

/**
 * Function: dienTichHinhTron
 * Description: in ra kết quả diện tích hình tròn dựa trên bán kính
 * Input:
 *    None
 * Output:
 *    Result - float
*/
float hinhTron::dienTichHinhTron(){
  return (2 * pow(hinhTron::banKinh, 2) * hinhTron::pi);
};


int main() {
  hinhTron *math;
  math = new hinhTron((float)11.1);
  printf("chu vi ht la: %f\n", math->chuViHinhTron());
  printf("dien tich ht la: %f\n",math->dienTichHinhTron());
  delete math;
  return 0;
}