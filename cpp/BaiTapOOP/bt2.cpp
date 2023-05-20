#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class Distance {
  private:  
    uint8_t chieuDai;
    uint8_t chieuRong;
  public:
    Distance(uint8_t d = 0, uint8_t r = 0) {
      chieuDai = d;
      chieuRong = r;
    }
    uint8_t chuVi();
    uint8_t dienTich();
    uint8_t duongCheo();
    uint8_t kiemTra();
};

uint8_t Distance::chuVi() {
  uint16_t chuvi = (Distance::chieuDai + Distance::chieuRong) * 2;
  return chuvi;
}
uint8_t Distance::dienTich() {
  uint16_t dienTich = Distance::chieuDai * Distance::chieuRong;
  return dienTich;
}
uint8_t Distance::duongCheo() {
  uint16_t duongCheo = sqrt(pow(Distance::chieuDai, 2) + pow(Distance::chieuRong, 2));
  return duongCheo;
}
uint8_t Distance::kiemTra() {
  if(Distance::chieuDai == Distance::chieuRong) {
    return 1;
  }
  return 0;
}

int main() {
  Distance *math;
  math = new Distance(10, 11);
  printf("chu vi hcn la: %d\n", math->chuVi());
  printf("dien tich hcn la: %d\n",math->dienTich());
  printf("duong cheo hcn la: %d\n", math->duongCheo());
  if(math->kiemTra()) {
    printf("Day la hinh vuong");
  } else {
    printf("Day la hinh chu nhat");
  }
  delete math;
  
  return 0;
}