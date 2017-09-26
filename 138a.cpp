#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000010];
int dp[1000010];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[2] + min(a[0], a[1]);

    for (int i = 3; i < n; i++) {
        dp[i] = min(dp[i-3], min(dp[i-1], dp[i-2])) + a[i];
    }
    cout << min(dp[n-1], dp[n-2]) << endl;
    
    return 0;
}
