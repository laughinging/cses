#include<bits/stdc++.h>
using namespace std;

int cnt[50];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            cnt[i+j] ++;
    int mx = 0;
    for (int i = 2; i <= m+n; i++)
        mx = max(mx, cnt[i]);
    for (int i = 2; i <= m+n; i++)
        if (cnt[i] == mx)
            cout << i << endl;
    return 0;
}
