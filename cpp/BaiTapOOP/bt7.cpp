#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;
class Date {
  private:
    uint8_t day;
    uint8_t month;
    uint16_t year;
  public:
    Date(uint8_t d, uint8_t m, uint16_t y) {
      day = d;
      month = m;
      year = y;
    }
    int ageCalculate(Date* dateBorn, Date* dateCurent);
    int KiemTraLaNgayNghiLe();
};
int Date::ageCalculate(Date* dateBorn, Date* dateCurent) {
  return dateCurent->year - dateBorn->year;
}
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