#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;
class Book {
  private:
    string nameBook;
    string authorName;
    int quantityBook;
  public:
    Book(string name, string author, int quantity) {
      nameBook = name;
      authorName = author;
      quantityBook = quantity;
    }
    void infoBookPrint();
    uint8_t muonSach(int quantity);
    uint8_t traSach(int quantity);
};

void Book::infoBookPrint() {
  printf("Tên tac gia: %s\n", Book::authorName);
  printf("Ten sach: %s\n",Book::nameBook);
  printf("So luong Sach: %d\n", Book::quantityBook);
};
uint8_t Book::muonSach(int quantity) {
  if(Book::quantityBook > quantity) {
    Book::quantityBook -= quantity;
    return 1;
  } else {
    cout << "Sach hien da het" << endl;
    return 0;
  }
};
uint8_t Book::traSach(int quantity) {
  Book::quantityBook += quantity;
  cout << "Da tra" << quantity << "sach\n" << endl;
  return 1;
}

int main() {
  Book *book = new Book("Tren Duong Bang", "Tony Buoi Sang", 100);

  printf("Toi muon muon 5 cuon \n");
  uint8_t muonSach = book->muonSach(5);
  if (muonSach) {
    /* code */
    printf("Toi Da muon duoc sach\n");
  }

  book->infoBookPrint();
  printf("Toi muon tra 5 cuon\n");
  uint8_t traSach = book->traSach(5);
  if(traSach) {
    printf("Toi Da tra duoc sach\n");
  }
  book->infoBookPrint();
  delete Book;
  return 0;
}