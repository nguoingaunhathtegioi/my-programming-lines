#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> lis;

    for (int i = 0; i < n; ++i) {
        // Tìm vị trí đầu tiên trong lis mà >= a[i]
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);

        if (it == lis.end()) {
            lis.push_back(a[i]); // Thêm vào cuối nếu lớn hơn mọi phần tử trước
        } else {
            *it = a[i]; // Ghi đè để giữ LIS "tối ưu" nhất
        }
    }

    cout << lis.size() << endl;

    return 0;
}
