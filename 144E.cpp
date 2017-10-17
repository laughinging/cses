#include<bits/stdc++.h>
using namespace std;

const int P = 538008;
int T;
int n, x1, y1, x2, y2;
int dp[5010], pre[5010];

int f(int s, int a, int b) {
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    dp[a] = 1;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < n; j++) {
            pre[j] = dp[j];
            if (j > 0) pre[j] += dp[j-1];
            if (j < n-1) pre[j] += dp[j+1];
        }
        for (int j = 0; j < n; j++)
            dp[j] = pre[j] % P;
    }
    return dp[b];
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> x1 >> y1 >> x2 >> y2;
        if (abs(x2-x1) > abs(y1-y2))
            cout << f(abs(x2-x1), y1-1, y2-1) << endl;
        else 
            cout << f(abs(y1-y2), x1-1, x2-1) << endl; 
    }
    
    return 0;
}
