#include <algorithm>
#include "pch.h"
void test(int a, int* b, int& c) {
    a = 10;
    *b = 20;
    c = 30;
}

enum LoaiTamGiac {
    TamGiacKhongTonTai,
    TamGiacDeu,
    TamGiacCan,
    TamGiacVuong,
    TamGiacThuong
};

LoaiTamGiac XacDinhLoaiTamGiac(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return TamGiacKhongTonTai;
    }

    if (a == b && b == c) {
        return TamGiacDeu;
    }

    if (a == b || b == c || c == a) {
        return TamGiacCan;
    }

    double maxSide = std::max(a, std::max(b, c));
    double sumSquares = a * a + b * b + c * c;

    if (2 * maxSide * maxSide == sumSquares) {
        return TamGiacVuong;
    }

    return TamGiacThuong;
};

TEST(XacDinhLoaiTamGiacCaseName, TamGiacKhongTonTaiName_1) {
    double a = 0; double b = 1; double c = 3;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacKhongTonTai);
}
TEST(XacDinhLoaiTamGiacCaseName, TamGiacKhongTonTaiName_2) {
    double a = 4; double b = -1; double c = 1;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacKhongTonTai);
}
TEST(XacDinhLoaiTamGiacCaseName, TamGiacKhongTonTaiName_3) {
    double a = 3; double b = 1; double c = -3;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacKhongTonTai);
}

TEST(XacDinhLoaiTamGiacCaseName, TamGiacDeuName) {
    double a = 3; double b = 3; double c = 3;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacDeu);
}

TEST(XacDinhLoaiTamGiacCaseName, TamGiacCanName_1) {
    double a = 1; double b = 1; double c = 2;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacCan);
}
TEST(XacDinhLoaiTamGiacCaseName, TamGiacCanName_2) {
    double a = 2; double b = 1; double c = 1;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacCan);
}
TEST(XacDinhLoaiTamGiacCaseName, TamGiacCanName_3) {
    double a = 1; double b = 2; double c = 1;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacCan);
}

TEST(XacDinhLoaiTamGiacCaseName, TamGiacVuongName_1) {
    double a = 3; double b = 4; double c = 5;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacVuong);
}

TEST(XacDinhLoaiTamGiacCaseName, TamGiacThuongName) {
    double a = 2; double b = 3; double c = 4;
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(a, b, c);
    EXPECT_EQ(tamgiac, TamGiacThuong);
}