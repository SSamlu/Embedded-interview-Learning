#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;
class BankAccount {
  private:
    string accountNumber;
    string accountName;
    uint16_t accountBalance;
  public:
    BankAccount(string accountNo, string name, int Balance) {
      accountNumber = accountNo;
      accountName = name;
      accountBalance = Balance;
    }
    uint16_t getBalance();
    void napTien(uint16_t soTienNap);
    void rutTien(uint16_t soTienRut);
};
uint16_t BankAccount::getBalance() {
  return BankAccount::accountBalance;
}
void BankAccount::napTien(uint16_t soTienNap) {
  BankAccount::accountBalance += soTienNap;
  cout << "quy khach da nap " << BankAccount::accountBalance << " VND vao tai khoan" << endl;
};
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