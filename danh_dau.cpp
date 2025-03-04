#include <iostream>
#include <math.h>
using namespace std;

//Chỉ số của mark là từ 0 tới 10^6, ban đầu toàn bộ mảng mark[] = 0

int mark[1000001]; 

int main(){
    int n = 8;
    int a[8] = {3, 1, 3, 0, 2, 4, 1, 6};
    //đánh dấu
    for(int i = 0; i < n; i++){
        //Lấy a[i] làm chỉ số và chuyển mark[a[i]] = 1
        mark[a[i]] = 1;
    }
    int dem = 0;
    //Bạn có thể duyệt từ i = 0 tới giá trị max trong mảng cũng được
    for(int i = 0; i <= 1000000; i++){
        if(mark[i] == 1){
            ++dem;
        }
    }
    cout << "So luong phan tu khac nhau : " << dem << endl;
    return 0;
}