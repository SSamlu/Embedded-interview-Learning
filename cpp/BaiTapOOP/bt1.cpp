#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

class ToaDo {
  private:
    int8_t ToaDoX;
    int8_t ToaDoY;
    
  public:
    int8_t setToaDo(int8_t x, int8_t y);
    int8_t getToaDoX();
    int8_t getToaDoY();
    ToaDo(int8_t x = 0,int8_t y = 0) {
      ToaDoX = x;
      ToaDoY = y;
    }
    double distanceTwoPoints(ToaDo* a);
    double dienTichTamGiac(ToaDo* a, ToaDo* b);
};
int8_t ToaDo::getToaDoX() {
  return ToaDo::ToaDoX;
}
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

double ToaDo::distanceTwoPoints(ToaDo* a) {
  return sqrt(pow(a->ToaDoX - ToaDo::ToaDoX, 2) + pow(a->ToaDoY - ToaDo::ToaDoY, 2));
}
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