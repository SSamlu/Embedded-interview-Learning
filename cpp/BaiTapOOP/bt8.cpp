/*
* File: bt8.cpp
* Author: NGUYEN DINH DIEN
* Date: 20/5/2023
* Description: Tạo một lớp tài khoản ngân hàng với các thuộc tính số tài khoản, tên tài
              khoản và số dư, và các phương thức để rút, nộp tiền và kiểm tra số dư
              trong tài khoản.
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

/**
 * Function: Class BankAccount
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng BankAccount
 * Input:
 *    None
 * Output:
 *    None
*/

class BankAccount {
  private:
    string accountNumber;
    string accountName;
    uint16_t accountBalance;
  public:
    /**
     * Function: Constructor BankAccount
     * Description: nhập thông tin khởi tạo các BankAccount
     * Input:
     *    accountNo - string
     *    name - string
     *    Balance - int
     * Output:
     *    None
    */
    BankAccount(string accountNo, string name, int Balance) {
      accountNumber = accountNo;
      accountName = name;
      accountBalance = Balance;
    }
    uint16_t getBalance();
    void napTien(uint16_t soTienNap);
    void rutTien(uint16_t soTienRut);
};

/**
 * Function: getBalance
 * Description: in ra số dư của tài khoản
 * Input:
 *    None
 * Output:
 *    Result - uint16_t
*/
uint16_t BankAccount::getBalance() {
  return BankAccount::accountBalance;
}

/**
 * Function: napTien
 * Description: nập tiền cào tài khoản
 * Input:
 *    soTienNap - uint16_t
 * Output:
 *    None
*/
void BankAccount::napTien(uint16_t soTienNap) {
  BankAccount::accountBalance += soTienNap;
  cout << "quy khach da nap " << BankAccount::accountBalance << " VND vao tai khoan" << endl;
};

/**
 * Function: rutTien
 * Description: Rút iền
 * Input:
 *    soTienRut - uint16_t
 * Output:
 *    None
*/
void BankAccount::rutTien(uint16_t soTienRut) {
  if(soTienRut <= BankAccount::accountBalance && BankAccount::accountBalance > 0) {
    BankAccount::accountBalance -= soTienRut;
    cout << "Quy khach da rut " << BankAccount::accountBalance << " VND tu tai khoan" <<endl;
  } else {
    cout << "Khong du tien trong tai khoan de rut" << endl;
  }
};

int main() {
  BankAccount *client;
  client = new BankAccount("GN100", "Dien", 1000);
  cout << "So du trong tai khoan cua Quy Khach la: " << client->getBalance() << " VND" << endl;
  client->napTien(100);
  cout << "So du trong tai khoan cua Quy Khach la: " << client->getBalance() << " VND" << endl;
  client->rutTien(200);
  cout << "So du trong tai khoan cua Quy Khach la: " << client->getBalance() << " VND" << endl;
  delete client;
  return 0;
}