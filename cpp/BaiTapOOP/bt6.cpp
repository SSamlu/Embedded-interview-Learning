/*
* File: bt6.cpp
* Author: NGUYEN DINH DIEN
* Date: 20/5/2023
* Description: Tạo một lớp phân số với các thuộc tính tử số và mẫu số và các phương
              thức để tính toán các phép tính toán cơ bản như cộng, trừ, nhân và
              chia.
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

/**
 * Function: Class PhanSo
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng PhanSo
 * Input:
 *    None
 * Output:
 *    None
*/

class PhanSo {
  private:
    int tu;
    int mau;
  public:
    /**
     * Function: Constructor PhanSo
     * Description: nhập thông tin khởi tạo các PhanSo
     * Input:
     *    t - int
     *    m - int
     * Output:
     *    None
    */
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

/**
 * Function: setVal
 * Description: set phân số từ giá trị tử và mẫu
 * Input:
 *    None
 * Output:
 *    val - float
*/
float PhanSo::setVal() {
  float val = (float)PhanSo::tu / (float)PhanSo::mau;
  return val;
};

/**
 * Function: congHaiPS
 * Description: cộng hai phân số
 * Input:
 *    x - object PhanSo
 *    y - object PhanSo
 * Output:
 *    Result - float
*/
float PhanSo::congHaiPS(PhanSo* x, PhanSo* y) {
  float a = x->setVal();
  float b = y->setVal();
  return x->setVal() + y->setVal();
}

/**
 * Function: truHaiPS
 * Description: Trừ hai phân số
 * Input:
 *    x - object PhanSo
 *    y - object PhanSo
 * Output:
 *    Result - float
*/
float PhanSo::truHaiPS(PhanSo* x, PhanSo* y) {
  return x->setVal() - y->setVal();
}

/**
 * Function: nhanHaiPS
 * Description: Nhân hai phân số
 * Input:
 *    x - object PhanSo
 *    y - object PhanSo
 * Output:
 *    Result - float
*/
float PhanSo::nhanHaiPS(PhanSo* x, PhanSo* y) {
  return x->setVal() * y->setVal();
}

/**
 * Function: chiaHaiPS
 * Description: chia hai phân số
 * Input:
 *    x - object PhanSo
 *    y - object PhanSo
 * Output:
 *    Result - float
*/
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