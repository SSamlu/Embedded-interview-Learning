#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class hinhTron {
  private:
    float banKinh;
    const float pi = 3.14;
  public:
    hinhTron(float ht) {
      banKinh = ht;
    };
    float chuViHinhTron();
    float dienTichHinhTron();
};

float hinhTron::chuViHinhTron() {
  float a = 2 * hinhTron::banKinh * hinhTron::pi;
  return (2 * hinhTron::banKinh * hinhTron::pi);
};
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