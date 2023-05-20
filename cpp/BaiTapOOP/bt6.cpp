#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;
class PhanSo {
  private:
    int tu;
    int mau;
  public:
    PhanSo(int t = 0, int m = 1) {
      tu = t;
      mau = m;
    };
    float setVal();
    float congHaiPS(PhanSo* x, PhanSo* y);
    float truHaiPS(PhanSo* x, PhanSo* y);
    float nhanHaiPS(PhanSo* x, PhanSo* y);
    float chiaHaiPS(PhanSo* x, PhanSo* y);
};
float PhanSo::setVal() {
  float val = (float)PhanSo::tu / (float)PhanSo::mau;
  return val;
};

float PhanSo::congHaiPS(PhanSo* x, PhanSo* y) {
  float a = x->setVal();
  float b = y->setVal();
  return x->setVal() + y->setVal();
}
float PhanSo::truHaiPS(PhanSo* x, PhanSo* y) {
  return x->setVal() - y->setVal();
}
float PhanSo::nhanHaiPS(PhanSo* x, PhanSo* y) {
  return x->setVal() * y->setVal();
}
float PhanSo::chiaHaiPS(PhanSo* x, PhanSo* y) {
  return x->setVal() / y->setVal();
}

int main() {
  PhanSo ps, *ps1, *ps2;
  ps1 = new PhanSo(10, 11);
  ps2 = new PhanSo(1, 11);
  cout << "KQ phep cong: " << ps.congHaiPS(ps1, ps2) << endl;
  cout << "KQ phep tru: " << ps.truHaiPS(ps1, ps2) << endl;
  cout << "KQ phep nhan: " << ps.nhanHaiPS(ps1, ps2) << endl;
  cout << "KQ phep chia: " << ps.chiaHaiPS(ps1, ps2) << endl;
  delete ps1, ps2;
  return 0;
}