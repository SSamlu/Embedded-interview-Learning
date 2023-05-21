/*
* File: bt1.cpp
* Author: NGUYEN DINH DIEN
* Date: 20/5/2023
* Description: Tạo một lớp điểm trong hệ tọa độ 2D và viết các phương thức để tính
                khoảng cách giữa hai điểm, tính diện tích của tam giác được tạo bởi ba
                điểm.
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

/**
 * Function: Class ToaDo
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng ToaDo
 * Input:
 *    None
 * Output:
 *    None
*/

class ToaDo {
  private:
    int8_t ToaDoX;
    int8_t ToaDoY;
    
  public:
    int8_t setToaDo(int8_t x, int8_t y);
    int8_t getToaDoX();
    int8_t getToaDoY();

    /**
     * Function: Constructor ToaDo
     * Description: nhập thông tin khởi tạo các ToaDo
     * Input:
     *    x - int8_t
     *    y - int8_t
     * Output:
     *    None
    */
    ToaDo(const int8_t x = 0, const int8_t y = 0) {
      ToaDoX = x;
      ToaDoY = y;
    }
    double distanceTwoPoints(ToaDo* a);
    double dienTichTamGiac(ToaDo* a, ToaDo* b);
};
/**
 * Function: distanceTwoPoints
 * Description: in ra kết quả tọa độ X
 * Input:
 *    None
 * Output:
 *    Result - int8_t
*/
int8_t ToaDo::getToaDoX() {
  return ToaDo::ToaDoX;
}

/**
 * Function: distanceTwoPoints
 * Description: in ra kết quả tọa độ Y
 * Input:
 *    None
 * Output:
 *    Result - int8_t
*/
int8_t ToaDo::getToaDoY() {
  return ToaDo::ToaDoY;
}
// class math {
//   private:
//     ToaDo A;
//     ToaDo B;
//     ToaDo C;
//     typedef enum{
//       KHOANG_CACH,
//       DIEN_TICH
//     } PhepToan;
//   public:
//     // void phepToanOxy(ToaDo a, ToaDo b);
//     // void phepToanOxy(ToaDo a, ToaDo b, ToaDo c);
//     double distanceTwoPoints();
//     double dienTichTamGiac();
// };

/**
 * Function: distanceTwoPoints
 * Description: in ra kết quả khoảng cách giwuax hai điểm cho trước
 * Input:
 *    a - Object ToaDo
 * Output:
 *    Result - double
*/
double ToaDo::distanceTwoPoints(ToaDo* a) {
  return sqrt(pow(a->ToaDoX - ToaDo::ToaDoX, 2) + pow(a->ToaDoY - ToaDo::ToaDoY, 2));
}

/**
 * Function: dienTichTamGiac
 * Description: in ra kết quả diện tích tam giac với điểm cho trước
 * Input:
 *    a - Object ToaDo
 *    b - Object ToaDo
 * Output:
 *    Result - double
*/
double ToaDo::dienTichTamGiac(ToaDo* a, ToaDo* b) {
  double x = ToaDo::distanceTwoPoints(a);
  double y = ToaDo::distanceTwoPoints(b);
  double z = a->distanceTwoPoints(b);
  double p = (x + y + z) / 2;
  return sqrt(p * (p - x) * (p - y) * (p - z));
};

int main() {
  ToaDo *Diem1, *Diem2, *Diem3;
  Diem1 = new ToaDo(1, 1);
  Diem2 = new ToaDo(1, 6);
  Diem3  = new ToaDo(10, 6);
  cout << "Khoang cach giua hai diem la: " << Diem1->distanceTwoPoints(Diem2) << endl; // same với Diem1 vs Diem3,...
  cout << "Dien Tich Tam giac la: " << Diem1->dienTichTamGiac(Diem2, Diem3) << endl;
  delete Diem1, Diem2, Diem3;
  return 0;
}