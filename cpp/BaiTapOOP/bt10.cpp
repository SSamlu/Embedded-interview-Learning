/*
* File: bt10.cpp
* Author: NGUYEN DINH DIEN
* Date: 20/5/2023
* Description: Tạo một lớp sách với các thuộc tính tên sách, tác giả, năm xuất bản
              và số lượng, và các phương thức để in thông tin sách, mượn sách và
              trả sách
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

/**
 * Function: Class Book
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng Book
 * Input:
 *    None
 * Output:
 *    None
*/
class Book {
  private:
    string nameBook;
    string authorName;
    int quantityBook;
  public:

    /**
     * Function: Constructor Book
     * Description: nhập thông tin khởi tạo các Book
     * Input:
     *    name - string
     *    author - string
     *    quantity - int
     * Output:
     *    None
    */
    Book(string name, string author, int quantity) {
      nameBook = name;
      authorName = author;
      quantityBook = quantity;
    }
    void infoBookPrint();
    uint8_t muonSach(int quantity);
    uint8_t traSach(int quantity);
};

/**
 * Function: infoBookPrint
 * Description: in ra thông tin và số lượng của sách
 * Input:
 *    None
 * Output:
 *    None
*/
void Book::infoBookPrint() {
  printf("Tên tac gia: %s\n", Book::authorName);
  printf("Ten sach: %s\n",Book::nameBook);
  printf("So luong Sach: %d\n", Book::quantityBook);
};

/**
 * Function: muonSach
 * Description: nhập số sách muốn mượn và kiểm tra xem có sách để mượn không
 * Input:
 *    quantity - int
 * Output:
 *    boolean - uint8_t
*/
uint8_t Book::muonSach(int quantity) {
  if(Book::quantityBook > quantity) {
    Book::quantityBook -= quantity;
    return 1;
  } else {
    cout << "Sach hien da het" << endl;
    return 0;
  }
};

/**
 * Function: traSach
 * Description: nhập số sách muốn trả và in ra kêt quả là đã trả bao nhiêu sách
 * Input:
 *    quantity - int
 * Output:
 *    boolean - uint8_t
*/
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