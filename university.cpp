#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxN = 1e5 + 5;
const int inf = 1e9 + 5;

int parent[maxN],sz[maxN],sum[maxN],a[maxN],p[maxN],kq[maxN];
bool check[maxN];

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
    sum[v] = a[v];
}

int find(int v)
{
    return (parent[v] == v)? v: parent[v] = find(parent[v]);
}

void union_set(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a!=b)
    {
        if (sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
        sum[a] = sum[a] + sum[b];
    }
}

signed main()
{
    int n,m;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> p[i];
    
    for (int i = 1; i <= n; i++) make_set(i);
    for (int i = n; i >= 1; i--)
    {
        check[p[i]] = true;
        
        if (p[i] > 1 && check[p[i]- 1]) union_set(p[i],p[i]-1);
        if (p[i] < n && check[p[i]+ 1]) union_set(p[i],p[i]+1);
        
        m = max(m,sum[find(p[i])]);
        kq[i-1] = m;
    }
    
    for (int i = 1; i <= n; i++) cout << kq[i] << '\n';
}