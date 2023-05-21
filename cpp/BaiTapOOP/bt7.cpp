/*
* File: bt7.cpp
* Author: NGUYEN DINH DIEN
* Date: 20/5/2023
* Description: Tạo một lớp ngày tháng năm với các thuộc tính ngày, tháng và năm, và
              các phương thức để tính tuổi của người và kiểm tra xem một ngày nhất
              định có phải là ngày nghỉ lễ hay không.
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

/**
 * Function: Class Date
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng Date
 * Input:
 *    None
 * Output:
 *    None
*/

class Date {
  private:
    uint8_t day;
    uint8_t month;
    uint16_t year;
  public:
    /**
     * Function: Constructor Date
     * Description: nhập thông tin khởi tạo các Date
     * Input:
     *    d - uint8_t
     *    m - uint8_t
     *    y = uint16_t
     * Output:
     *    None
    */
    Date(uint8_t d, uint8_t m, uint16_t y) {
      day = d;
      month = m;
      year = y;
    }
    int ageCalculate(Date* dateBorn, Date* dateCurent);
    int KiemTraLaNgayNghiLe();
};

/**
 * Function: ageCalculate
 * Description: tính tuổi từ người sinh sinh
 * Input:
 *    dateBorn - object Date
 *    dateCurent - object Date
 * Output:
 *    Result - int
*/
int Date::ageCalculate(Date* dateBorn, Date* dateCurent) {
  return dateCurent->year - dateBorn->year;
}

/**
 * Function: KiemTraLaNgayNghiLe
 * Description: Kiểm tra xem có phải là ngyaf lễ không
 * Input:
 *    None
 * Output:
 *    Boolean - ỉnt
*/
int Date::KiemTraLaNgayNghiLe() {
  if (Date::day == 1 && Date::month == 1 || Date::day == 30 && Date::month == 4 || Date::day == 1 && Date::month == 5 || Date::day == 2 && Date::month == 9)
    return 1;
  else return 0;
}
int main() {
  Date *dateBorn, *dateCurent;
  dateBorn = new Date(25, 10, 1998);
  dateCurent = new Date(20, 10, 2023);
  printf("tuoi: %d\n", dateBorn->ageCalculate(dateBorn, dateCurent));
  cout << "La ngay nghi le: " << (dateBorn->KiemTraLaNgayNghiLe() ? "co" : "khong") << endl;
  // printf("La ngay nghi le: %s", (dateBorn->KiemTraLaNgayNghiLe() ? "co" : "khong"));
  delete dateBorn, dateCurent;
  return 0;
}