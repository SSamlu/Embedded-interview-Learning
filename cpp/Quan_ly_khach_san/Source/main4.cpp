/**
 * File: main4.cpp
 * Author: NGUYEN DINH DIEN
 * Date: 12/6/2023
 * Discription: this is file for hotel manager session payment manager
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
  uint8_t day;
  uint8_t month;
  uint16_t year;
} TypeDate;

typedef enum {
  CREDIT_CARD,
  CASH,
  INTERNET_BANKING
} PaymentMethod;

/**
 * Class: Payment
 * Description: this is Payment class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class Payment {
  private:
    string paymentId;
    double amount;
    PaymentMethod method;

  public:
    Payment(string paymentId, double amount, PaymentMethod method);
    string getPaymentId();
    double getAmount();
    PaymentMethod getMethod();
    void setPaymentId(string paymentId);
    void setAmount(double amount);
    void setMethod(PaymentMethod method);
};

/**
* Function: Payment
* Description: This function use for constructor Payment
* Input:
*   paymentId- string
*   amount - double
*   method - PaymentMethod
* Output:
*   return: None
*/
Payment::Payment(string paymentId, double amount, PaymentMethod method) {
  this->paymentId = paymentId;
  this->amount = amount;
  this->method = method;
}

/*
* Function: getPaymentId
* Description: This function use for get payment ID
* Input:
*   None
* Output:
*   return: paymentId
*/
string Payment::getPaymentId() {
  return paymentId;
}

/*
* Function: getAmount
* Description: This function use for get amount
* Input:
*   None
* Output:
*   return: amount
*/
double Payment::getAmount() {
  return amount;
}

/*
* Function: getMethod
* Description: This function use for get method
* Input:
*   None
* Output:
*   return: payment method 
*/
PaymentMethod Payment::getMethod() {
  return method;
}

/*
* Function: setPaymentId
* Description: This function use for set Payment Id
* Input:
*   paymentId - string
* Output:
*   return: None
*/
void Payment::setPaymentId(string paymentId) {
  this->paymentId = paymentId;
}

/*
* Function: setAmount
* Description: This function use for set Amount
* Input:
*   amount - double
* Output:
*   return: None
*/
void Payment::setAmount(double amount) {
  this->amount = amount;
}

/*
* Function: setMethod
* Description: This function use for set Method
* Input:
*   method - PaymentMethod
* Output:
*   return: None
*/
void Payment::setMethod(PaymentMethod method) {
  this->method = method;
}

/**
 * Class: PaymentHistory
 * Description: this is PaymentHistory class
 * Input:
 *   Dont have input parameters`
 * Output:
 *   return: none
*/
class PaymentHistory {
  private:
    vector<Payment> paymentList;

  public:
    void addPayment();
    void displayPaymentHistory();
};

/*
* Function: addPayment
* Description: This function use for add Payment
* Input:
*   None
* Output:
*   return: None
*/
void PaymentHistory::addPayment() {
  string paymentId;
  double amount;
  int methodCode;

  cout << "Enter payment ID: ";
  cin >> paymentId;

  cout << "Enter payment amount: ";
  cin >> amount;

  cout << "Select payment method:" << endl;
  cout << "1. Credit Card" << endl;
  cout << "2. Cash" << endl;
  cout << "3. Internet Banking" << endl;
  cout << "Enter method code: ";
  cin >> methodCode;

  PaymentMethod method;
  switch (methodCode) {
    case 1:
      method = CREDIT_CARD;
      break;
    case 2:
      method = CASH;
      break;
    case 3:
      method = INTERNET_BANKING;
      break;
    default:
      cout << "Invalid method code. Payment not added." << endl;
      return;
  }

  Payment newPayment(paymentId, amount, method);
  paymentList.push_back(newPayment);

  cout << "Payment added successfully!" << endl;
}

/*
* Function: displayPaymentHistory
* Description: This function use for display Payment History
* Input:
*   None
* Output:
*   return: None
*/
void PaymentHistory::displayPaymentHistory() {
  if (paymentList.empty()) {
    cout << "No payment history available." << endl;
  } else {
    cout << "Payment History:" << endl;
    for (size_t i = 0; i < paymentList.size(); i++) {
      Payment& payment = paymentList[i];
      cout << "Payment ID: " << payment.getPaymentId() << endl;
      cout << "Amount: " << payment.getAmount() << endl;
      cout << "Method: ";
      switch (payment.getMethod()) {
        case CREDIT_CARD:
          cout << "Credit Card";
          break;
        case CASH:
          cout << "Cash";
          break;
        case INTERNET_BANKING:
          cout << "Internet Banking";
          break;
      }
      cout << endl << "----------------------" << endl;
    }
  }
}

int main() {
  return 0;
}
