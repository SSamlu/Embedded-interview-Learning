#include <stdint.h>
#include <stdio.h>

typedef struct {
  int year;
  int month;
  int day;
} DateTime;
/**
 *1. co ngay thang nam làm gốc (không thay đổi => const)
 *2. tháng 31 ngày, kiêm tra năm đó nhuận không
 *3. lấy này nhập - có ngày gốc rồi "%7" (chia lấy dư)
 *4. 
*/
int DayOfMonth(int month, int year) {
  switch (month)
  {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
      return 31;
      break;
    case 2:
      if(isLeapYear(year)) {
        return 29;
      } else {
        return 28;
      }
      break;
    default:
      return 30;
      break;
  }
}

int dayOfWeek(DateTime date) {
  int tmp = (14 - date.month) / 12;
  int y = date.year - tmp;
  int m = date.month + 12 * tmp - 2;
  int day = (date.day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
  return day;
}

int isLeapYear(int year) {
  if((year % 4 == 0 && year % 100 != 0)|| year % 400 == 0) {
    //  printf("%hd la nam nhuan.\n", year);
     return 1;
  } else {
    // printf("%hd khong phai nam nhuan.\n", year);
    return 0;
  }
}

int main() {
  const DateTime rootToday = {1, 1, 1};
  char *dayOfWeekName[] = {"Chu nhat", "Thu hai", "Thu ba", "Thu tu", "Thu nam", "Thu sau", "Thu bay"};
  DateTime today;
  printf("Nhap ngay, thang, nam: ");
  scanf("%d %d %hd", &today.day, &today.month, &today.year);
  printf("Ngay thang nam vua nhap: %d/%d/%hd\n", today.day, today.month, today.year);
  int daySinceRoot = 0;
  for (int year = rootToday.year; year < today.year; year++) {
    /* code */
    daySinceRoot += 365 + isLeapYear(year);
  }
  for (int month = 1; month < today.month; month++){
    /* code */
    daySinceRoot += DayOfMonth(month, today.year);
  }
  daySinceRoot += today.day - 1;
  int dayOfWeekNum = (dayOfWeek(rootToday) + daySinceRoot) % 7;
  printf("%d",dayOfWeekNum);
  
  printf("Ngay %d/%d/%hd la %s\n", today.day, today.month, today.year, dayOfWeekName[dayOfWeekNum]);
  return 0;
}