#include <iostream>

using namespace std;

int main() {
 // Khai báo biến
 int tongsocon, tongchan;

 // Nhập dữ liệu
 cout << "Nhập tổng số con: ";
 cin >> tongsocon;
 cout << "Nhập tổng số chân: ";
 cin >> tongchan;

 // Khởi tạo biến
 int ga = 0, cho = 0;

 // Giải phương trình
 for (int i = 0; i <= tongsocon; i++) {
   for (int j = 0; j <= tongsocon; j++) {
     if (2 * i + 4 * j == tongchan && i + j == tongsocon) {
       ga = i;
       cho = j;
       break;
     }
   }
   if (ga != 0) {
     break;
   }
 }

 // In kết quả
 cout << "Số gà: " << ga << endl;
 cout << "Số chó: " << cho << endl;

 return 0;
}