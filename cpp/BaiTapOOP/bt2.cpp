/*
* File: bt2.cpp
* Author: NGUYEN DINH DIEN
* Date: 20/5/2023
* Description: Tạo một lớp hình chữ nhật với các thuộc tính chiều dài, chiều rộng và
              các phương thức để tính chu vi, diện tích, đường chéo và kiểm tra xem
              nó có phải là hình vuông hay không.
*/
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

/**
 * Function: Class Distance
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng Distance
 * Input:
 *    None
 * Output:
 *    None
*/
class Distance {
  private:  
    uint8_t chieuDai;
    uint8_t chieuRong;
  public:
    /**
     * Function: Constructor Distance
     * Description: nhập thông tin khởi tạo các Distance
     * Input:
     *    d - uint8_t
     *    r - uint8_t
     * Output:
     *    None
    */
    Distance(uint8_t d = 0, uint8_t r = 0) {
      chieuDai = d;
      chieuRong = r;
    }
    uint8_t chuVi();
    uint8_t dienTich();
    uint8_t duongCheo();
    uint8_t kiemTra();
};

/**
 * Function: chuVi
 * Description: in ra kết quả chu vi dựa trên chiều dài và chiều rộng
 * Input:
 *    None
 * Output:
 *    chuvi - uint8_t
*/
uint8_t Distance::chuVi() {
  uint16_t chuvi = (Distance::chieuDai + Distance::chieuRong) * 2;
  return chuvi;
}

/**
 * Function: dienTich
 * Description: in ra kết quả diện tích dựa trên chiều dài và chiều rộng
 * Input:
 *    None
 * Output:
 *    dienTich - uint8_t
*/
uint8_t Distance::dienTich() {
  uint16_t dienTich = Distance::chieuDai * Distance::chieuRong;
  return dienTich;
}

/**
 * Function: duongCheo
 * Description: in ra kết quả đường chéo dựa trên chiều dài và chiều rộng
 * Input:
 *    None
 * Output:
 *    duongCheo - uint8_t
*/
uint8_t Distance::duongCheo() {
  uint16_t duongCheo = sqrt(pow(Distance::chieuDai, 2) + pow(Distance::chieuRong, 2));
  return duongCheo;
}

/**
 * Function: kiemTra
 * Description: Kiểm tra xem là hình vuông hay hay hình cn
 * Input:
 *    None
 * Output:
 *    Boolean - uint8_t
*/
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