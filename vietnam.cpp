#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[20], b[20], dp[20][2][2][10][20], tt[20][2][2][10][20];
string x, y;

int f2(int i, int g, int l, int d, int cnt) {
    if (i >= y.size()) return 1;
    if (tt[i][g][l][d][cnt] != -1) return tt[i][g][l][d][cnt];
    
    int dl = (g ? 0 : a[i]);
    int dr = (l ? 9 : b[i]);
    
    tt[i][g][l][d][cnt] = 0;
    for (int dd = dl; dd <= dr; dd++) {
        if (dd == d) {
            tt[i][g][l][d][cnt] += f2(i + 1, g || (dd > dl), l || (dd < dr), dd, cnt + 1);
        } else {
            tt[i][g][l][d][cnt] += f2(i + 1, g || (dd > dl), l || (dd < dr), dd, 1);
        }
    }
    
    return tt[i][g][l][d][cnt];
}

int f(int i, int g, int l, int d, int cnt) {
    if (i >= y.size()) return d * cnt * cnt;
    if (dp[i][g][l][d][cnt] != -1) return dp[i][g][l][d][cnt];
    
    int dl = (g ? 0 : a[i]);
    int dr = (l ? 9 : b[i]);
    
    dp[i][g][l][d][cnt] = 0;
    for (int dd = dl; dd <= dr; dd++) {
        if (dd == d) {
            dp[i][g][l][d][cnt] += f(i + 1, g || (dd > dl), l || (dd < dr), dd, cnt + 1);
        } else {
            dp[i][g][l][d][cnt] += f(i + 1, g || (dd > dl), l || (dd < dr), dd, 1) + d * cnt * cnt * f2(i + 1, g || (dd > dl), l || (dd < dr), dd, 1);
        }
    }
    
    return dp[i][g][l][d][cnt];
}

signed main() {
    cin >> x >> y;
    for (int i = y.size() - x.size(); i < y.size(); i++) a[i] = x[i - y.size() + x.size()] - '0';
    for (int i = 0; i < y.size(); i++) b[i] = y[i] - '0';
    
    memset(dp, -1, sizeof(dp));
    memset(tt, -1, sizeof(tt));
    cout << f(0, 0, 0, 0, 0);
}#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[20], b[20], dp[20][2][2][10][20], tt[20][2][2][10][20];
string x, y;

int f2(int i, int g, int l, int d, int cnt) {
    if (i >= y.size()) return 1;
    if (tt[i][g][l][d][cnt] != -1) return tt[i][g][l][d][cnt];
    
    int dl = (g ? 0 : a[i]);
    int dr = (l ? 9 : b[i]);
    
    tt[i][g][l][d][cnt] = 0;
    for (int dd = dl; dd <= dr; dd++) {
        if (dd == d) {
            tt[i][g][l][d][cnt] += f2(i + 1, g || (dd > dl), l || (dd < dr), dd, cnt + 1);
        } else {
            tt[i][g][l][d][cnt] += f2(i + 1, g || (dd > dl), l || (dd < dr), dd, 1);
        }
    }
    
    return tt[i][g][l][d][cnt];
}

int f(int i, int g, int l, int d, int cnt) {
    if (i >= y.size()) return d * cnt * cnt;
    if (dp[i][g][l][d][cnt] != -1) return dp[i][g][l][d][cnt];
    
    int dl = (g ? 0 : a[i]);
    int dr = (l ? 9 : b[i]);
    
    dp[i][g][l][d][cnt] = 0;
    for (int dd = dl; dd <= dr; dd++) {
        if (dd == d) {
            dp[i][g][l][d][cnt] += f(i + 1, g || (dd > dl), l || (dd < dr), dd, cnt + 1);
        } else {
            dp[i][g][l][d][cnt] += f(i + 1, g || (dd > dl), l || (dd < dr), dd, 1) + d * cnt * cnt * f2(i + 1, g || (dd > dl), l || (dd < dr), dd, 1);
        }
    }
    
    return dp[i][g][l][d][cnt];
}

signed main() {
    cin >> x >> y;
    for (int i = y.size() - x.size(); i < y.size(); i++) a[i] = x[i - y.size() + x.size()] - '0';
    for (int i = 0; i < y.size(); i++) b[i] = y[i] - '0';
    
    memset(dp, -1, sizeof(dp));
    memset(tt, -1, sizeof(tt));
    cout << f(0, 0, 0, 0, 0);
}