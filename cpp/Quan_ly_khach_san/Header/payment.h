#ifndef __PAYMENT_H
#define __PAYMENT_H
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
#endif
